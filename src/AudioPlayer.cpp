
#include "AudioPlayer.h"
#include <fstream>

double noteFrequencies[OCTAVE_COUNT][NOTE_COUNT] {
    { 16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87 },
    { 32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74 },
    { 65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47 },
    { 130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94 },
    { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 },
    { 523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77 },
    { 1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53 },
    { 2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07 },
    { 4186.01, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040.00, 7458.62, 7902.13 }
};

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
    this->frequencyRate = 88 * 1000;
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

bool AudioBuffer::loadSong(double* frequencies, double* durations, int count) {
    this->length = 0;
    this->frequencyRate = 48000;
    this->bitRate = 8;
    this->channels = 1;

    for(int i = 0; i < count; ++i) {
        this->length += durations[i];
    }

    int samplesCount = (frequencyRate) * length;
    this->size = samplesCount;
    this->data = new char[bitRate / 8 * samplesCount];
    std::vector<double> encodedData(samplesCount);

    for(int i = 0; i < encodedData.size(); ++i) {
        encodedData[i] = 0;
    }

    double currentTime = 0;

    for(int i = 0; i < count; ++i) {
        encodeFreq(frequencies[i], durations[i], currentTime, 1, 0, encodedData);
        currentTime += durations[i];
    }

    normalizeAmp(encodedData);

    for(int i = 0; i < size; ++i) {
        char value = 0x7F * encodedData[i];
        data[(i) + 0] = value;
    }

    alGenBuffers(1, &buffer);
    alBufferData(buffer, getFormat(), data, size, (ALsizei)frequencyRate);

    return true;
}

int AudioBuffer::encodeFreq(double frequency, double duration, double timeOffset, int startIndex, double amplitude, std::vector<double>& encodedData) {
    double secondsPerSample = 1 / (double)this->frequencyRate;
    int samplesCount = duration * this->frequencyRate;
    int indexBase = startIndex;

    for(int i = 0; i < samplesCount; ++i) {
        double time = (secondsPerSample * i) + timeOffset;
        double y = amplitude * std::sin((2 * (double)3.141592653) * frequency * time);
        int indexInBuffer = indexBase + i;
    
        //encode y in buffer
        encodedData[indexInBuffer] += y;
    }

    return samplesCount;
}