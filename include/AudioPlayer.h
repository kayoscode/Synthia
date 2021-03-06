#ifndef INCLUDE_AUDIO_PLAYER_H
#define INCLUDE_AUDIO_PLAYER_H

#include <al.h>
#include <alc.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Song.h"

enum class AudioPlayerInitStatus {
    AUDIO_PLAYER_LOAD_SUCCESS,
    AUDIO_PLAYER_DEVICE_LOAD_FAILED,
    AUDIO_PLAYER_CONTEXT_LOAD_FAILED,
    AUDIO_PLAYER_SOURCE_GEN_FAILED
};

class AudioBuffer {
    public:
        AudioBuffer();
        ~AudioBuffer();

        bool loadAudioWAV(const std::string& wavFile);
        bool loadSpectograph(char* data, int width, int height, int minFreq, int maxFreq, double time);
        bool loadFrequencies(double* frequencies, double* durations, int size);
        bool loadSong(Song& song);

        char* getData() const {
            return data;
        }

        int getBitRate() const {
            return bitRate;
        }

        int getFrequency() const {
            return frequencyRate;
        }

        int getChannels() const {
            return channels;
        }

        int getSize() const {
            return size;
        }

        ALuint getBuffer() const {
            return buffer;
        }

        ALenum getFormat() const;

        double getLength() const {
            return length;
        }

    private:
        int encodeFreq(double frequency, double duration, double timeOffset, int startIndex, double amplitude, std::vector<double>& encodedData);

        ALuint buffer;
        char* data;
        int bitRate;
        double frequencyRate;
        int size;
        int channels;
        double length;
};

class AudioPlayer {
    public:
        /**
         * constructor
         * */
        AudioPlayer();

        /**
         * initializes the audio device
         * */
        AudioPlayerInitStatus init(ALCchar* deviceName);

        /**
         * Creates a list of the names of each audio renderer
         * */
        static std::vector<std::string> enumerateAudioDevices();

        /**
         * Plays audio from a specific location to a specific location
         * */
        void playAudio(const AudioBuffer& buffer, float listenerX = 0, float listenerY = 0, float listenerZ = 0, float soundX = 0, float soundY = 0, float soundZ = 0);

        /**
         * Pauses the audio
         * */
        void pause() {
            alSourcePause(source);
        }

        void stop() {
            alSourceStop(source);
        }

        bool isPaused() {
            ALint currentState;
            alGetSourcei(source, AL_SOURCE_STATE, &currentState);
            return currentState == AL_PAUSED;
        }

        bool isPlaying() {
            ALint currentState;
            alGetSourcei(source, AL_SOURCE_STATE, &currentState);
            return currentState == AL_PLAYING;
        }
        
        bool isStopped() {
            ALint currentState;
            alGetSourcei(source, AL_SOURCE_STATE, &currentState);
            return currentState == AL_STOPPED;
        }

        /**
         * Destructor
         * */
        ~AudioPlayer();

        /**
         * Sets the volume of the system
         * */
        void setVolume(float volume) {
            this->volume = std::max(0.0f, volume);
            this->volume = std::min(1.0f, volume);
        }

        float getVolume() {
            return volume;
        }
        
        ALuint getSource() {
            return source;
        }

    private:
        ALCdevice* device;
        ALCcontext* deviceContext;
        ALuint source = 0;
        float volume = 1.0;
};

#endif