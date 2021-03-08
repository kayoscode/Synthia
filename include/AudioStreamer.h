
#ifndef INCLUDE_AUDIO_STREAMER_H
#define INCLUDE_AUDIO_STREAMER_H

#include "Song.h"

/**
 * Base class for loading audio into memory in smaller buffers
 * */
class AudioStream {
    public:
        AudioStream(Song& song, float sampleRate, int bufferSize = 4096);

        //bool loadNextBuffer()

        float* getBufferData() {
            return currentBuffer;
        }

    private:
    protected:
        float* currentBuffer;
        float** buffers;
};

class AudioStreamer {
    public:
        /**
         * Receives a base class audio stream
         * Loads individual buffers into memory, then sends them to 
         * Openal for rendering
         * */
        void streamSong(AudioStream& song);

    private:
};

#endif