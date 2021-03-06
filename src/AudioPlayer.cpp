
#include "AudioPlayer.h"
#include <math.h>
#include <fstream>

AudioPlayer::AudioPlayer()
    :device(NULL), 
    deviceContext(NULL)
{
}

AudioPlayerInitStatus AudioPlayer::init(ALCchar* deviceName) {
    //initialize open Al
    device = alcOpenDevice(NULL);
    deviceContext = NULL;

    if(device != NULL) {
        deviceContext = alcCreateContext(device, NULL);

        if(deviceContext != NULL) {
            alcMakeContextCurrent(deviceContext);
            alDistanceModel(AL_LINEAR_DISTANCE_CLAMPED);

            alGenSources(1, &source);
            ALenum error = alGetError();

            if(error != AL_NO_ERROR) {
                return AudioPlayerInitStatus::AUDIO_PLAYER_SOURCE_GEN_FAILED;
            }
        }
        else {
            return AudioPlayerInitStatus::AUDIO_PLAYER_CONTEXT_LOAD_FAILED;
        }
    }
    else {
        return AudioPlayerInitStatus::AUDIO_PLAYER_DEVICE_LOAD_FAILED;
    }

    return AudioPlayerInitStatus::AUDIO_PLAYER_LOAD_SUCCESS;
}

AudioPlayer::~AudioPlayer() {
    alcMakeContextCurrent(NULL);
    alDeleteSources(1, &source);
    alcDestroyContext(deviceContext);
    alcCloseDevice(device);
}

std::vector<std::string> AudioPlayer::enumerateAudioDevices() {
    char* devices = (char*)alcGetString(NULL, ALC_DEVICE_SPECIFIER);

    //each device is separated by a null terminator and the
    //list is ended by a doulble null termination

    std::string currentDevice;
    std::vector<std::string> ret;

    while(true) {
        if(*devices == '\0') {
            ret.push_back(currentDevice);
            currentDevice = "";
            
            devices++;

            if(*devices == '\0') {
                break;
            }
        }

        currentDevice += *devices;
        devices++;
    }

    return ret;
}

void AudioPlayer::playAudio(const AudioBuffer& buffer, float listenerX, float listenerY, float listenerZ, float soundX, float soundY, float soundZ) {
    alcMakeContextCurrent(deviceContext);
    alSourcef(source, AL_GAIN, volume);
    alListener3f(AL_POSITION, listenerX, listenerY, listenerZ);
    alSource3f(source, AL_POSITION, soundX, soundY, soundZ);

    alSourcei(source, AL_LOOPING, 0);
    alSourcei(source, AL_BUFFER, buffer.getBuffer());
    alSourcef(source, AL_SEC_OFFSET, 0);
    alSourcePlay(source);
}

AudioBuffer::AudioBuffer() 
    :buffer(NULL),
    bitRate(0),
    frequencyRate(0),
    length(0),
    data(NULL)
{
}

AudioBuffer::~AudioBuffer() {
    alDeleteBuffers(1, &buffer);
    delete[] data;
}

void loadWAVChunkData(std::ifstream& file, std::string& name, unsigned int& size) {
    char chunk[4];
    file.read((char*)&chunk, 4);
    file.read((char*)&size, 4);

    name = std::string(chunk, 4);
}

bool AudioBuffer::loadAudioWAV(const std::string& wavFile) {
    std::ifstream file(wavFile.c_str(), std::ios::in | std::ios::binary);

    if(!file) {
        std::cout << "File not found\n";
        return false;
    }

    std::string chunkName;
    unsigned int chunkSize;

    while(!file.eof()) {
        loadWAVChunkData(file, chunkName, chunkSize);

        if(chunkName == "RIFF") {
            file.ignore(4);
        }
        else if(chunkName == "fmt ") {
            uint16_t format, channels, balign, samp;
            uint32_t srate, bps;

            file.read((char*)&format, 2);
            file.read((char*)&channels, 2);

            file.read((char*)&srate, 4);
            file.read((char*)&bps, 4);

            file.read((char*)&balign, 2);
            file.read((char*)&samp, 2);

            bitRate = samp;
            frequencyRate = (double)srate;
            channels = channels;
        }
        else if(chunkName == "data") {
            size = chunkSize;
            data = new char[chunkSize];
            file.read((char*)data, chunkSize);
        }
        else {
            file.ignore(chunkSize);
        }
    }

    file.close();
    length = (double)size / (channels * frequencyRate * (bitRate / 8.0f)) * 1000.0f;

    alGenBuffers(1, &buffer);
    alBufferData(buffer, getFormat(), data, size, (ALsizei)frequencyRate);
    return true;
}

ALenum AudioBuffer::getFormat() const {
    if(bitRate == 16) {
        return channels == 2? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16;
    }
    else if(bitRate == 8) {
        return channels == 2? AL_FORMAT_STEREO8 : AL_FORMAT_MONO8;
    }

    return AL_FORMAT_MONO8;
}

void normalizeAmp(std::vector<double>& amps) {
    float maxSignal = 0;

    for(int i = 0; i < amps.size(); ++i) {
        if(std::abs(amps[i]) > maxSignal) {
            maxSignal = std::abs(amps[i]);
        }
    }

    for(int i = 0; i < amps.size(); ++i) {
        amps[i] /= maxSignal;
    }
}

bool AudioBuffer::loadSpectograph(char* bufferData, int width, int height, int minFreq, int maxFreq, double time) {
    this->length = time;
    this->bitRate = 16;
    this->channels = 1;
    this->frequencyRate = 48 * 1000;
    int samplesCount = (frequencyRate) * time;
    this->size = (bitRate / 8) * samplesCount;
    this->data = new char[size];

    for(int i = 0; i < size; i++) {
        data[i] = 0;
    }

    std::vector<double> encodedData(samplesCount);

    for(int i = 0; i < encodedData.size(); ++i) {
        encodedData[i] = 0;
    }

    double secondsPerNote = time / width;
    int currentIndex = 0;

    if(height <= 1) {
        height = 2;
        minFreq = (maxFreq - minFreq) / 2;
    }

    std::vector<double> frequencies(height);

    for(int i = 0; i < height; ++i) {
        frequencies[i] = (((double)(maxFreq - minFreq) / std::max((height - 1), 1)) * (height - i - 1)) + minFreq;
    }

    //convert data in buffer to digital audio signal
    for(int i = 0; i < width; ++i) {
        int usedIndices = 0;

        for(int j = 0; j < height; ++j) {
            int index = (width * j) + i;

            if(bufferData[index] > 0) {
                usedIndices = encodeFreq(frequencies[j], secondsPerNote, secondsPerNote * i, currentIndex, bufferData[index] / 1, encodedData);
            }
        }

        currentIndex += usedIndices;
    }

    normalizeAmp(encodedData);

    for(int i = 0; i < encodedData.size(); ++i) {
        short value = 0x7FFF * encodedData[i];
        short* d = (short*)data;
        d[i] = value;
        //data[(2 * i) + 1] = value >> 1;
        //data[(2 * i) + 0] = value;
    }

    alGenBuffers(1, &buffer);
    alBufferData(buffer, getFormat(), data, size, (ALsizei)frequencyRate);

    return true;
}

bool AudioBuffer::loadSong(Song& song) {
    this->length = song.getDuration();
    this->frequencyRate = 48 * 1000;
    this->bitRate = 16;
    this->channels = 1;
    int samplesCount = (frequencyRate) * length;
    this->size = (bitRate / 8) * samplesCount;
    this->data = new char[size];
    std::vector<double> encodedData(samplesCount);

    for(int i = 0; i < encodedData.size(); ++i) {
        encodedData[i] = 0;
    }
    
    //load keyframe data into buffer
    //gotta greatly improve the time for this operation - too slow
    for(std::map<std::string, Part*>::iterator i = song.getParts()->begin(); i != song.getParts()->end(); ++i) {
        Part* part = i->second;
        std::map<unsigned int, Beat*>* keyframes = part->getKeyframes();

        for(std::map<unsigned int, Beat*>::iterator j = keyframes->begin(); j != keyframes->end(); ++j) {
            Beat* beat = j->second;

            for(int x = 0; x < NOTE_COUNT; ++x) {
                for(int y = 0; y < OCTAVE_COUNT; ++y) {
                    for(int z = 0; z < MAX_FRACTIONAL_BEAT; ++z) {
                        if(beat->notes[x][y][z] > 0) {
                            int rawStart = j->first;
                            int rawDuration = beat->notes[x][y][z] / MAX_FRACTIONAL_BEAT;
                            int fractionalDuration = (beat->notes[x][y][z] % MAX_FRACTIONAL_BEAT);

                            double duration = song.getTimeSignatureBottom() * (rawDuration + fractionalDuration / (double)MAX_FRACTIONAL_BEAT);
                            double start = song.getTimeSignatureBottom() * (rawStart + (z / (double)MAX_FRACTIONAL_BEAT));
                            start = 1 / (song.getBPM() / start) * 60;
                            duration = 1 / (song.getBPM() / duration) * 60;

                            int startIndex = (start / length) * samplesCount;
                            encodeFreq(NOTE(x, y), duration, start, startIndex, 1, encodedData);
                        }
                    }
                }
            }
        }
    }

    normalizeAmp(encodedData);

    for(int i = 0; i < encodedData.size(); ++i) {
        short value = 0x7FFF * encodedData[i];
        short* d = (short*)data;
        d[i] = value;
    }

    alGenBuffers(1, &buffer);
    alBufferData(buffer, getFormat(), data, size, (ALsizei)frequencyRate);

    return true;
}

bool AudioBuffer::loadFrequencies(double* frequencies, double* durations, int count) {
    this->length = 0;
    this->frequencyRate = 48 * 1000;
    this->bitRate = 16;
    this->channels = 1;

    for(int i = 0; i < count; ++i) {
        this->length += durations[i];
    }

    int samplesCount = (frequencyRate) * length;
    this->size = (bitRate / 8) * samplesCount;
    this->data = new char[size];
    std::vector<double> encodedData(samplesCount);

    for(int i = 0; i < encodedData.size(); ++i) {
        encodedData[i] = 0;
    }

    double currentTime = 0;
    int currentIndex = 0;
    int currentAddr = 0;

    for(int i = 0; i < count; ++i) {
        currentAddr = encodeFreq(frequencies[i], durations[i], currentTime, currentIndex, 1, encodedData);
        currentTime += durations[i];
        currentIndex += currentAddr;
    }

    normalizeAmp(encodedData);

    for(int i = 0; i < encodedData.size(); ++i) {
        short value = 0x7FFF * encodedData[i];
        short* d = (short*)data;
        d[i] = value;
    }

    alGenBuffers(1, &buffer);
    alBufferData(buffer, getFormat(), data, size, (ALsizei)frequencyRate);

    return true;
}

int AudioBuffer::encodeFreq(double frequency, double duration, double timeOffset, int startIndex, double amplitude, std::vector<double>& encodedData) {
    double secondsPerSample = 1 / (double)this->frequencyRate;
    int samplesCount = duration * this->frequencyRate;
    int indexBase = startIndex;

    //attenuation = e^(-2x) cause I can't think of anything better right now
    //x = time - timeOffset

    for(int i = 0; i < samplesCount; ++i) {
        double time = (secondsPerSample * i) + timeOffset;
        double attDiff = (secondsPerSample * i);
        amplitude = std::exp(-(attDiff * 1.5));

        if(i > (samplesCount * .90)) {
            double t = (i / (double)samplesCount);
            t -= .90;
            t /= (1 -.90);
            t = 1 - t;

            amplitude *= t;
        }
        else if(i < (samplesCount * .003)) {
            double maxAmp = std::exp(-(.003 * 1.5));
            double t = (i / (double)samplesCount);
            t /= .003;

            amplitude = t * maxAmp;
        }

        double y = amplitude * std::cos((2 * (double)3.141592653) * frequency * time);
        int indexInBuffer = indexBase + i;
    
        //encode y in buffer
        encodedData[indexInBuffer] += y;
    }

    return samplesCount;
}
