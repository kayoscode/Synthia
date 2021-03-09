#include "Song.h"
#include <iostream>
#include <fstream>

float noteFrequencies[OCTAVE_COUNT][NOTE_COUNT] {
    { 16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87, 0 },
    { 32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74, 0 },
    { 65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47, 0 },
    { 130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94, 0 },
    { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88, 0 },
    { 523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77, 0 },
    { 1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53, 0 },
    { 2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07, 0 },
    { 4186.01, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040.00, 7458.62, 7902.13, 0 }
};

Song::~Song() {
for(std::map<std::string, Part*>::iterator i = parts.begin(); i != parts.end(); ++i) {
    delete i->second;
}
}

void normalizeAmp(float* amps, int size) {
    float maxSignal = 0;

    for(int i = 0; i < size; ++i) {
        if(std::abs(amps[i]) > maxSignal) {
            maxSignal = std::abs(amps[i]);
        }
    }

    for(int i = 0; i < size; ++i) {
        amps[i] /= maxSignal;
    }
}

//for now, assuming a bitrate of 16
int SongEncoder::getSongBinarySize(Song& song, int sampleRate) {
    return (16/8 * sampleRate) * song.getDuration();
}

void SongEncoder::loadSongBinary(Song& song, char* data, int sampleRate, const Synthesizer& synthesizer) {
    float length = song.getDuration();
    float frequencyRate = (float)sampleRate;
    int bitRate = 16;
    int channels = 1;
    int samplesCount = (frequencyRate) * length;
    int size = (bitRate / 8) * samplesCount;

    float* encodedData = new float[samplesCount];

    for(int i = 0; i < samplesCount; ++i) {
        encodedData[i] = 0;
    }
    
    //load keyframe data into buffer
    //gotta greatly improve the time for this operation - too slow
    for(std::map<std::string, Part*>::iterator i = song.getParts()->begin(); i != song.getParts()->end(); ++i) {
        Part* part = i->second;
        std::map<unsigned int, Beat*>* keyframes = part->getKeyframes();

        for(std::map<unsigned int, Beat*>::iterator j = keyframes->begin(); j != keyframes->end(); ++j) {
            Beat* beat = j->second;
            int rawStart = j->first;
            float volume = 1;

            for(std::map<unsigned short, std::vector<NoteStruct>>::iterator k = beat->notes.begin(); k != beat->notes.end(); ++k) {
                for(int w = 0; w < k->second.size(); ++w) {
                    int rawDuration = k->second[w].duration / BEAT_SUBDIVIDE;
                    int fractionalDuration = k->second[w].duration % BEAT_SUBDIVIDE;
                    unsigned int noteFX = k->second[w].noteFX;
                    unsigned int startOffset = k->second[w].startOffset;
                    
                    float duration = (rawDuration + fractionalDuration / (float)BEAT_SUBDIVIDE) - startOffset;
                    float start = (rawStart + (k->first / (float)BEAT_SUBDIVIDE)) + startOffset;
                    start = 1 / (song.getBPM() / start) * 60;
                    duration = 1 / (song.getBPM() / duration) * 60;

                    int startIndex = (start / length) * samplesCount;

                    if(noteFX & NoteEffects::NOTE_FX_STACCATO) {
                        duration /= 2;
                    }

                    if(noteFX & NoteEffects::NOTE_FX_CRESCENDO) {
                        volume *= 1.2;
                    }

                    if(noteFX & NoteEffects::NOTE_FX_DIMINUENDO) {
                        volume *= .75;
                    }

                    synthesizer.synthesize(NOTE(k->second[w].note, k->second[w].oct), duration, start, startIndex, volume, encodedData, part->getInstrument(), frequencyRate);
                }
            }
        }

        //apply equalization
        part->getInstrument()->equalize(encodedData, samplesCount, frequencyRate);
    }

    normalizeAmp(encodedData, samplesCount);

    for(int i = 0; i < samplesCount; ++i) {
        short value = 0x7FFF * encodedData[i];
        short* d = (short*)data;
        d[i] = value;
    }

    delete[] encodedData;
}

uint32_t getBigEndian(uint32_t number) {
    char buffer[4];

    buffer[3] = number & 0xFF;
    buffer[2] = (number >> 8) & 0xFF;
    buffer[1] = (number >> 16) & 0xFF;
    buffer[0] = (number >> 24) & 0xFF;

    return *((uint32_t*)buffer);
}

uint16_t getBigEndian16(uint16_t number) {
    char buffer[2];

    buffer[1] = number & 0xFF;
    buffer[0] = (number >> 8) & 0xFF;

    return *((uint16_t*)buffer);
}

void Song::saveAsWav(const std::string& fileName) {
    std::cout << "SAVING\n\n";
    uint32_t sampleRate = 48000;
    uint16_t bitRate = 16;
    uint16_t channels = 1;
    uint32_t size = SongEncoder::getSongBinarySize(*this, sampleRate);
    char* binary = new char[size];
    uint32_t totalSize = 36 + size;

    uint32_t chunk1Size = 16;
    uint16_t PCM = 1;
    uint32_t byteRate = (sampleRate * channels * bitRate) / 8;
    uint16_t blockAlign = channels * (bitRate / 8);

    Synthesizer s;
    SongEncoder::loadSongBinary(*this, binary, sampleRate, s);

    std::ofstream outputFile(fileName + ".wav", std::ios::binary);
    outputFile.write("RIFF", 4);
    outputFile.write((char*)&totalSize, 4);
    outputFile.write("WAVE", 4);

    //write chunk1
    outputFile.write("fmt ", 4);
    outputFile.write((char*)&chunk1Size, 4);
    //write audio format which is 1 - because no compression is used
    outputFile.write((char*)&PCM, 2);
    //write number of channels which is always 1 which happens to be inside PCM
    outputFile.write((char*)&channels, 2);
    //write sample rate
    outputFile.write((char*)&sampleRate, 4);
    //write byte rate
    outputFile.write((char*)&byteRate, 4);
    //write block align
    outputFile.write((char*)&blockAlign, 2);
    //write bits per sample
    outputFile.write((char*)&bitRate, 2);

    //write data chunk
    outputFile.write("data", 4);
    //write data size
    outputFile.write((char*)&size, 4);
    //write actual sound data

    outputFile.write(binary, size);

    outputFile.close();
    delete[] binary;
}

Part* Song::addPart(const std::string& name, Instrument* instrument) {
    Part* part = new Part(bpm, timeSigTop, timeSigBottom, instrument);
    parts[name] = part;
    return part;
}

Part::~Part() {
    for(std::map<unsigned int, Beat*>::iterator i = keyframes.begin(); i != keyframes.end(); ++i) {
        delete i->second;
    }
}

unsigned int Part::addNote(unsigned int beat, Note note, Octave octave, unsigned int durationBeats, unsigned int noteFX) {
    //add note duration effects
    if(noteFX & NoteEffects::NOTE_FX_EXTEND) {
        durationBeats = durationBeats + (durationBeats / 2);
    }

    if(activeBeatFX & BeatEffects::BEAT_FX_ARPEGGIO) {
        beat += arpeggioCounter;
        durationBeats -= arpeggioCounter;
        arpeggioCounter += ARPEGGIO_OFFSET;
    }

    int rawBeat = beat / BEAT_SUBDIVIDE;
    int fractional = beat % BEAT_SUBDIVIDE;

    int rawDuration = durationBeats / BEAT_SUBDIVIDE;
    int fractionalDuration = durationBeats % BEAT_SUBDIVIDE;

    if(keyframes.find(rawBeat) == keyframes.end()) {
        keyframes[rawBeat] = new Beat();
    }

    NoteStruct newNote;
    newNote.duration = durationBeats;
    newNote.note = note;
    newNote.oct = octave;
    newNote.noteFX = noteFX;

    keyframes[rawBeat]->notes[fractional].push_back(newNote);
    
    float currentBeat = ((rawBeat + (fractional / (float)BEAT_SUBDIVIDE)) + (rawDuration + fractionalDuration / (float)BEAT_SUBDIVIDE));
    float minTime = 1 / (bpm / currentBeat) * 60;

    if(minTime > timeInSeconds) {
        timeInSeconds = minTime;
    }

    return beat + durationBeats;
}

void Part::enableBeatEffects(unsigned int beatEffects) {
    this->activeBeatFX = beatEffects;
    this->arpeggioCounter = 0;
}

float Part::getDuration() const {
    return timeInSeconds;
}