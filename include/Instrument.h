#ifndef INCLUDE_INSTRUMENT_H
#define INCLUDE_INSTRUMENT_H

#include <cmath>

class Instrument {
    public: 
        virtual float getAttackAmpltitude(float time, float holdAmp, float velocity) = 0;
        virtual float getReleaseAmpltitude(float time, float holdAmp, float velocity) = 0;
        virtual float getSustainAmplitude(float time, float holdDuration, float velocity) = 0;
        virtual float getHoldAmplitude(float time, float holdDuration, float velocity) = 0;

        virtual float sample(float time, float frequency) = 0;
        virtual float equalize(float y) = 0;

        virtual float getAttackDuration() = 0;
        virtual float getReleaseDuration() = 0;

        float generateSinWave(float time, float frequency) {
            return std::sin(time * frequency * 2 * 3.141592653);
        }

        /**
         * |-----|      |
         * |     |      |
         * |     |------|
         * */
        float generatePulseWave(float time, float frequency) {
            float ret = generateSinWave(time, frequency);
            return ret < 0? -1 : 1;
        }

        /**
         * Essentially just the integral of the box wave form
         * */
        float generateTriangleWave(float time, float frequency) {
            float res = 0.0;
            float fullPeriodTime = 1.0 / frequency;
            float localTime = fmod(time, fullPeriodTime);
            
            float value = localTime / fullPeriodTime;
            
            if (value < 0.25) {
                res = value * 4;
            }
            else if (value < 0.75) {
                res = 2.0 - (value * 4.0);
            }
            else {
                res = value * 4 - 4.0;
            }
            
            return res;
        }

        float generateSawToothWave(float time, float frequency) {
            double t = std::fmod(time, 1 / frequency);
            return ((t / (1 / frequency)) * 2 - 1);
        }

        float linearInterpolation(float start, float target, float t) {
            return start * (1 - t) + target * t;
        }

        //float filter() - eq helper function
};

class LofiPiano : public Instrument {
    public:
        float getAttackAmpltitude(float time, float holdAmp, float velocity) {
            return linearInterpolation(0, holdAmp, time / getAttackDuration());
        }

        float getReleaseAmpltitude(float t, float holdAmp, float velocity) {
            return linearInterpolation(holdAmp, 0, t / getReleaseDuration());
        }

        float getSustainAmplitude(float progress, float holdDuration, float velocity) {
            return 0;
        }

        float getHoldAmplitude(float time, float holdDuration, float velocity) {
            return std::exp(1.5 * -time);
        }

        float getAttackDuration() {
            return .01;
        }

        float getReleaseDuration() {
            return .009;
        }

        float sample(float time, float frequency) {
            float voice = 0;
            voice += generateSinWave(time, 1 * frequency) * 2;
            voice += generateSawToothWave(time, 1 * frequency) / 12;

            voice += generateTriangleWave(time, 2 * frequency) / 4;
            voice += generateSinWave(time, 2 * frequency) / 8;

            voice += generateSinWave(time, 3 * frequency) / 16;
            voice += generateSinWave(time, 4 * frequency) / 32;

            voice += voice * voice * voice;

            return voice;
        }

        float equalize(float y) {
            return y;
        }
};

class ElectricGuitar : public Instrument {
    public:
        float getAttackAmpltitude(float time, float holdAmp, float velocity) {
            return linearInterpolation(0, holdAmp, time / getAttackDuration());
        }

        float getReleaseAmpltitude(float t, float holdAmp, float velocity) {
            return linearInterpolation(holdAmp, 0, t / getReleaseDuration());
        }

        float getSustainAmplitude(float progress, float holdDuration, float velocity) {
            return 0;
        }

        float getHoldAmplitude(float time, float holdDuration, float velocity) {
            return std::exp(1.5 * -time);
        }

        float getAttackDuration() {
            return .01;
        }

        float getReleaseDuration() {
            return .009;
        }

        float sample(float time, float frequency) {
            float voice = 0;
            voice += generateSawToothWave(time, 1 * frequency);

            return voice;
        }

        float equalize(float y) {
            return y;
        }
};

#endif