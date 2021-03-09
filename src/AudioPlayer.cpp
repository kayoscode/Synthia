
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
    data(NULL),
    synthesizer()
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

    std::cout << "LOADING\n\n";

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
            frequencyRate = (float)srate;
            this->channels = channels;
        }
        else if(chunkName == "data") {
            size = chunkSize;
            data = new char[chunkSize];
            file.read((char*)data, chunkSize);
            std::cout << chunkSize << "\n";
        }
        else {
            file.ignore(chunkSize);
        }
    }

    file.close();

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

bool AudioBuffer::loadSpectograph(char* bufferData, int width, int height, int minFreq, int maxFreq, float time) {
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

    float* encodedData = new float[samplesCount];

    for(int i = 0; i < samplesCount; ++i) {
        encodedData[i] = 0;
    }

    float secondsPerNote = time / width;
    int currentIndex = 0;

    if(height <= 1) {
        height = 2;
        minFreq = (maxFreq - minFreq) / 2;
    }

    std::vector<float> frequencies(height);

    for(int i = 0; i < height; ++i) {
        frequencies[i] = (((float)(maxFreq - minFreq) / std::max((height - 1), 1)) * (height - i - 1)) + minFreq;
    }

    //convert data in buffer to digital audio signal
    for(int i = 0; i < width; ++i) {
        int usedIndices = 0;

        for(int j = 0; j < height; ++j) {
            int index = (width * j) + i;

            if(bufferData[index] > 0) {
                //usedIndices = encodeFreq(frequencies[j], secondsPerNote, secondsPerNote * i, currentIndex, bufferData[index] / 1, encodedData);
            }
        }

        currentIndex += usedIndices;
    }

    //normalizeAmp(encodedData, samplesCount);

    for(int i = 0; i < samplesCount; ++i) {
        short value = 0x7FFF * encodedData[i];
        short* d = (short*)data;
        d[i] = value;
        //data[(2 * i) + 1] = value >> 1;
        //data[(2 * i) + 0] = value;
    }

    alGenBuffers(1, &buffer);
    alBufferData(buffer, getFormat(), data, size, (ALsizei)frequencyRate);

    delete[] encodedData;

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

    std::cout << size << "\n";

    SongEncoder::loadSongBinary(song, data, frequencyRate, synthesizer);

    alGenBuffers(1, &buffer);
    alBufferData(buffer, getFormat(), data, size, (ALsizei)frequencyRate);

    return true;
}

int AudioBuffer::encodeFreq(float frequency, float duration, float timeOffset, int startIndex, float volume, std::vector<float>& encodedData) {
    float secondsPerSample = 1 / (float)this->frequencyRate;
    int samplesCount = duration * this->frequencyRate;
    int indexBase = startIndex;
    float amplitude = 0;

    for(int i = 0; i < samplesCount; ++i) {
        float time = (secondsPerSample * i) + timeOffset;
        float attDiff = (secondsPerSample * i);
        amplitude = std::exp(-(attDiff * 2.0));

        if(i > (samplesCount * .94)) {
            float t = (i / (float)samplesCount);
            t -= .94;
            t /= (1 -.94);
            t = 1 - t;

            amplitude *= t;
        }
        else if(i < (samplesCount * .008)) {
            float maxAmp = std::exp(-(.008 * 2.0));
            float t = (i / (float)samplesCount);
            t /= .008;

            amplitude = t * maxAmp;
        }

        int indexInBuffer = indexBase + i;
    
        //encode y in buffer
        encodedData[indexInBuffer] += volume * amplitude * std::sin((2 * (float)3.141592653) * frequency * time);
        encodedData[indexInBuffer] += volume * amplitude * std::sin((2 * (float)3.141592653) * frequency * 2 * time) * 1.2;
        encodedData[indexInBuffer] += volume * amplitude * std::sin((2 * (float)3.141592653) * frequency * 3 * time) / 4;
        encodedData[indexInBuffer] += volume * amplitude * std::sin((2 * (float)3.141592653) * frequency * 4 * time) / 8;
        encodedData[indexInBuffer] += volume * amplitude * std::sin((2 * (float)3.141592653) * frequency * 5 * time) / 16;
        encodedData[indexInBuffer] += volume * amplitude * std::sin((2 * (float)3.141592653) * frequency * 6 * time) / 32;
    }

    return samplesCount;
}