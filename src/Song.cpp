#include "Song.h"
#include <iostream>

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