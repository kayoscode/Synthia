#ifndef INCLUDE_INSTRUMENT_H
#define INCLUDE_INSTRUMENT_H

#include <cmath>

class Instrument {
    public: 
        virtual float getAttackAmpltitude(float time, float holdAmp, float velocity) = 0;
        virtual float getReleaseAmpltitude(float time, float holdAmp, float velocity) = 0;
        virtual float getSustainAmplitude(float time, float holdDuration, float velocity) = 0;
        virtual float getHoldAmplitude(float time, float holdDuration, float velocity) = 0;

        virtual float sample(float time, float frequency, float noteTime, float noteDuration) = 0;
        virtual void equalize(float* data, int size, float dt) = 0;

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

        void highPassFilter(float* data, int size, float dt, float RC) {
            float alpha = RC / (RC + dt);
            float previous = data[0];

            for(int i = 1; i < size; i++) {
                float tmp = data[i];
                data[i] = alpha * (data[i - 1] + previous - data[i]);
                previous = tmp;
            }
        }

        void lowPassFilter(float* data, int size, float dt, float RC) {
            float alpha = dt / (RC + dt);
            data[0] = alpha * data[0];

            for(int i = 1; i < size; i++) {
                data[i] = data[i - 1] + alpha * (data[i] - data[i - 1]);
            }
        }
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
            return std::exp(1.6 * -time);
        }

        float getAttackDuration() {
            return .0012;
        }

        float getReleaseDuration() {
            return .0015;
        }

        float sample(float time, float frequency, float noteTime, float noteDuration) {
            float voice = 0;
            voice += generateSinWave(time, 1 * frequency) / 1;
            voice += generateSinWave(time, 2 * frequency) / 2;
            voice += generateSinWave(time, 3 * frequency) / 4;
            voice += generateSinWave(time, 4 * frequency) / 8;
            voice += generateSawToothWave(time, 3 * frequency) / 128;
            voice += generateSawToothWave(time, 4 * frequency) / 256;

            return voice;
        }

        void equalize(float* data, int size, float freq) {
            float dt = 1 / freq;
            lowPassFilter(data, size, dt, 1/(double)5500);
        }
};

#endif