
#ifndef INCLUDE_SONG_H
#define INCLUDE_SONG_H

#include <vector>
#include <map>
#include <string>

#define NOTE(note, oct) noteFrequencies[oct][note]
#define MAX_FRACTIONAL_BEAT 64

enum Note {
    C, CSH, D, DSH, E, F, FSH, G, GSH, A, ASH, B, HOLD, NOTE_COUNT
};

enum Octave {
    OCTAVE_0, OCTAVE1, OCTAVE2, OCTAVE3, OCTAVE4, OCTAVE5, OCTAVE6, OCTAVE7, OCTAVE8, OCTAVE_COUNT
};

extern double noteFrequencies[OCTAVE_COUNT][NOTE_COUNT];

enum Instrument {
    PURE_FREQ,
    PIANO,
};

struct Beat {
    //indicates the number of fractional beats for which the note should play
    //EX: 1 beat is equivalent to 64 here
    uint32_t notes[NOTE_COUNT][OCTAVE_COUNT][MAX_FRACTIONAL_BEAT] = { 0 };
};

#define BEAT(beatCount, offset) Part::calculateBeat(beatCount, offset) 

class Part {
    public:
        Part(int bpm, int timeSigTop, int timeSigBottom) : 
            bpm(bpm), 
            timeSigTop(timeSigTop), 
            timeSigBottom(timeSigBottom)
        {}

        ~Part();

        /**
         * Add a note to the track:
         * @param beat: the beat in which it starts
         * @param beatStartOffset: the fractional distance into the beat in which the note should start
         * @return returns when the note will stop playing
         * */
        unsigned int addNote(unsigned int start, Note note, Octave octave, unsigned int duration);

        unsigned int addWholeNote(unsigned int start, Note note, Octave octave) {
            return addNote(start, note, octave, BEAT(1, 0));
        }

        unsigned int addHalfNote(unsigned int start, Note note, Octave octave) {
            return addNote(start, note, octave, BEAT(0, MAX_FRACTIONAL_BEAT / 2));
        }

        unsigned int addQuarterNote(unsigned int start, Note note, Octave octave) {
            return addNote(start, note, octave, BEAT(0, MAX_FRACTIONAL_BEAT / 4));
        }

        unsigned int addEightNote(unsigned int start, Note note, Octave octave) {
            return addNote(start, note, octave, BEAT(0, MAX_FRACTIONAL_BEAT / 8));
        }

        unsigned int add16Note(unsigned int start, Note note, Octave octave) {
            return addNote(start, note, octave, BEAT(0, MAX_FRACTIONAL_BEAT / 16));
        }

        unsigned int add32Note(unsigned int start, Note note, Octave octave) {
            return addNote(start, note, octave, BEAT(0, MAX_FRACTIONAL_BEAT / 32));
        }

        unsigned int add64Note(unsigned int start, Note note, Octave octave) {
            return addNote(start, note, octave, BEAT(0, MAX_FRACTIONAL_BEAT / 64));
        }

        /**
         * Returns a beat
         * @param beatCount: the raw beat
         * @param fractionOffset: number between 1 and MAX_FRACTIONAL_BEAT indicating the exact moment the note should stop playing
         * */
        static unsigned int calculateBeat(int beatCount, int fractionalOffset) {
            return beatCount * MAX_FRACTIONAL_BEAT + fractionalOffset;
        }

        /**
         * Returns the duration of the song in seconds
         * */
        double getDuration() const;

        std::map<unsigned int, Beat*>* getKeyframes() {
            return &keyframes;
        }

    private:
        Instrument instrument;
        std::map<unsigned int, Beat*> keyframes;
        int bpm;
        int timeSigTop;
        int timeSigBottom;
        double timeInSeconds = -1;
};

class Song {
    public:
        Song(int bpm = 60, int topSig = 4, int bottomSig = 4)
            :bpm(bpm),
            timeSigTop(topSig),
            timeSigBottom(bottomSig)
        {}
        
        ~Song();

        Part* addPart(const std::string& name, Instrument instrument);

        Part* getPart(const std::string& part) {
            return parts[part];
        }

        int getBPM() const {
            return bpm;
        }

        void setBPM(int bpm) {
            this->bpm = bpm;
        }

        int getTimeSignatureTop() const {
            return timeSigTop;
        }

        int getTimeSignatureBottom() const {
            return timeSigBottom;
        }

        void setTimeSignature(int top, int bottom) {
            this->timeSigTop = top;
            this->timeSigBottom = bottom;
        }

        double getDuration() const {
            double ret = 0;

            for(std::map<std::string, Part*>::const_iterator i = parts.begin(); i != parts.end(); ++i) {
                if(i->second->getDuration() > ret) {
                    ret = i->second->getDuration();
                }
            }

            return ret;
        }

        std::map<std::string, Part*>* getParts() {
            return &parts;
        }

    private:
        std::map<std::string, Part*> parts;
        int bpm;

        int timeSigTop, timeSigBottom;
};

#endif