#include "Synthesizer.h"
#include <algorithm>

#include "Song.h"
#include "Instrument.h"

int Synthesizer::synthesize(float frequency, float duration, float timeOffset, int startIndex, float vol, float* data, Instrument* instrument, float sampleRate) const {
    float secondsPerSample = 1 / (float)sampleRate;
    int samplesCount = duration * sampleRate;
    int indexBase = startIndex;
    float amplitude = 0;
    float attackDuration = instrument->getAttackDuration();
    float releaseDuration = instrument->getReleaseDuration();
    float holdDuration = std::max((double)(duration - (attackDuration + releaseDuration)), 0.0);

    for(int i = 0; i < samplesCount; ++i) {
        float t = secondsPerSample * i;
        float time = t + timeOffset;
        float amplitude = 1;
        float velocity = 1;
        float remainingTime = duration - t;

        //set the amplitude based on the instruments attack/release specifications
        if(remainingTime <= releaseDuration) {
            //release
            float holdAmp = std::max(instrument->getHoldAmplitude(holdDuration, holdDuration, velocity), instrument->getSustainAmplitude(holdDuration, holdDuration, velocity));
            amplitude = instrument->getReleaseAmpltitude(releaseDuration - remainingTime, holdAmp, velocity);
        }
        else if(t <= attackDuration) {
            //attack
            float holdAmp = std::max(instrument->getHoldAmplitude(0, holdDuration, velocity), instrument->getSustainAmplitude(0, holdDuration, velocity));
            amplitude = instrument->getAttackAmpltitude(t, holdAmp, velocity);
        }
        else {
            //hold
            float p = (t - attackDuration);
            amplitude = std::max(instrument->getHoldAmplitude(p, holdDuration, velocity), instrument->getSustainAmplitude(p, holdDuration, velocity));
        }
    
        //encode y in buffer
        data[indexBase + i] += vol * amplitude * instrument->sample(time, frequency, t, duration);
    }

    return samplesCount;
}
