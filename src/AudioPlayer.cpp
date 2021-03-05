
#include "AudioPlayer.h"
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
    alListenerf(AL_GAIN, volume);
    alListener3f(AL_POSITION, listenerX, listenerY, listenerZ);
    //alSource3f(AL_POSITION, soundX, soundY, soundZ);

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
    delete data;
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
            frequencyRate = (float)srate;
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
    length = (float)size / (channels * frequencyRate * (bitRate / 8.0f)) * 1000.0f;

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