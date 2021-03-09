
#ifndef INCLUDE_SYNTHESIZER_H
#define INCLUDE_SYNTHESIZER_H

class Instrument;

class Synthesizer {
    public:
        int synthesize(float frequency, float duration, float timeOffset, int startIndex, float vol, float* data, Instrument* instrument, float sampleRate) const;
};

#endif