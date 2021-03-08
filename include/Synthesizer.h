
#ifndef INCLUDE_SYNTHESIZER_H
#define INCLUDE_SYNTHESIZER_H

#include "Song.h"
#include "Instrument.h"

class Synthesizer {
    public:
        int synthesize(float frequency, float duration, float timeOffset, int startIndex, float vol, float* data, Instrument* instrument, float sampleRate);
};

#endif