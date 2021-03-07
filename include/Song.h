
#ifndef INCLUDE_SONG_H
#define INCLUDE_SONG_H

#include <vector>
#include <map>
#include <string>
#include <iostream>

#define NOTE(note, oct) noteFrequencies[oct][note]
#define BEAT_SUBDIVIDE 128
#define ARPEGGIO_OFFSET (rand() % 16)

#define WHOLE_NOTE 1
#define HALF_NOTE 2
#define QUATER_NOTE 4
#define EIGHT_NOTE 8
#define SIXTEENTH_NOTE 16
#define THIRTYSECOND_NOTE 32
#define SIXTYFORTH_NOTE 64

enum Note {
    C, CSH, D, DSH, E, F, FSH, G, GSH, A, ASH, B, HOLD, NOTE_COUNT
};

enum Octave {
    OCTAVE_0, OCTAVE1, OCTAVE2, OCTAVE3, OCTAVE4, OCTAVE5, OCTAVE6, OCTAVE7, OCTAVE8, OCTAVE_COUNT
};

extern double noteFrequencies[OCTAVE_COUNT][NOTE_COUNT];

enum NoteEffects {
    NOTE_FX_NONE = 0,
    NOTE_FX_EXTEND = 1,
    NOTE_FX_STACCATO = 2,
    NOTE_FX_CRESCENDO = 4,
    NOTE_FX_DIMINUENDO = 8,
};

enum BeatEffects {
    BEAT_FX_NONE = 0,
    BEAT_FX_ARPEGGIO = 1,
    BEAT_FX_SLUR = 2,
};

enum Instrument {
    PURE_FREQ,
    PIANO,
};

struct NoteStruct {
    Note note;
    Octave oct;
    unsigned int duration;
    unsigned int noteFX;
    unsigned char startOffset = 0;
};

struct Beat {
    //indicates the number of fractional beats for which the note should play
    //EX: 1 beat is equivalent to 64 here
    std::map<unsigned short, std::vector<NoteStruct>> notes;
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
        unsigned int addNote(unsigned int start, Note note, Octave octave, unsigned int duration, unsigned int noteFX = 0);

        unsigned int addWholeNote(unsigned int start, Note note, Octave octave, unsigned int noteFX = 0) {
            //bottom note of the score represents the type of note that counts as a beat
            //4/4 time would indicate a measure has 4 beats and a quarter note is a beat
            //beat subdivide is the max number of times a beat can be subdivided

            unsigned int beatCount = timeSigBottom;
            return addNote(start, note, octave, calculateBeat(beatCount, 0), noteFX);
        }

        unsigned int addHalfNote(unsigned int start, Note note, Octave octave, unsigned int noteFX = 0) {
            unsigned int beatCount = timeSigBottom / HALF_NOTE;
            unsigned int fractionalBeat = ((timeSigBottom % HALF_NOTE) * (BEAT_SUBDIVIDE / HALF_NOTE));
            return addNote(start, note, octave, calculateBeat(beatCount, fractionalBeat), noteFX);
        }

        unsigned int addQuarterNote(unsigned int start, Note note, Octave octave, unsigned int noteFX = 0) {
            unsigned int beatCount = timeSigBottom / QUATER_NOTE;
            unsigned int fractionalBeat = ((timeSigBottom % QUATER_NOTE) * (BEAT_SUBDIVIDE / QUATER_NOTE));

            return addNote(start, note, octave, calculateBeat(beatCount, fractionalBeat), noteFX);
        }

        unsigned int addEightNote(unsigned int start, Note note, Octave octave, unsigned int noteFX = 0) {
            unsigned int beatCount = timeSigBottom / EIGHT_NOTE;
            unsigned int fractionalBeat = ((timeSigBottom % EIGHT_NOTE) * (BEAT_SUBDIVIDE / EIGHT_NOTE));

            return addNote(start, note, octave, calculateBeat(beatCount, fractionalBeat), noteFX);
        }

        unsigned int add16Note(unsigned int start, Note note, Octave octave, unsigned int noteFX = 0) {
            unsigned int beatCount = timeSigBottom / SIXTEENTH_NOTE;
            unsigned int fractionalBeat = ((timeSigBottom % SIXTEENTH_NOTE) * (BEAT_SUBDIVIDE / SIXTEENTH_NOTE));

            return addNote(start, note, octave, calculateBeat(beatCount, fractionalBeat), noteFX);
        }

        unsigned int add32Note(unsigned int start, Note note, Octave octave, unsigned int noteFX = 0) {
            unsigned int beatCount = timeSigBottom / THIRTYSECOND_NOTE;
            unsigned int fractionalBeat = ((timeSigBottom % THIRTYSECOND_NOTE) * (BEAT_SUBDIVIDE / THIRTYSECOND_NOTE));

            return addNote(start, note, octave, calculateBeat(beatCount, fractionalBeat), noteFX);
        }

        unsigned int add64Note(unsigned int start, Note note, Octave octave, unsigned int noteFX) {
            unsigned int beatCount = timeSigBottom / SIXTYFORTH_NOTE;
            unsigned int fractionalBeat = ((timeSigBottom % SIXTYFORTH_NOTE) * (BEAT_SUBDIVIDE / SIXTYFORTH_NOTE));

            return addNote(start, note, octave, calculateBeat(beatCount, fractionalBeat), noteFX);
        }

        void enableBeatEffects(unsigned int beatEffects);

        /**
         * If you have n notes that need to
         * take up a note that takes n time, sometimes the fractional divide can cause misalignment 
         * from beat boundaries
         * to fix that, use this function to obtain the duration of that note, it will automatically align it to fill exactly 
         * that note's space
         * @param subDivisions: indicates the number of times the note should be broken down
         * @param noteLen: 1, 2, 4, 8, 16, 32, 64
         * @param noteIndex: indicates the current note in the sequence - indexed from 1 to subdivisions inclusive
         * */
        unsigned int getNoteFractionalDuration(unsigned int subDivisions, int noteIndex, int noteType) {
            unsigned int beatCount = timeSigBottom / noteType;
            unsigned int fractionalBeat = ((timeSigBottom % noteType) * (BEAT_SUBDIVIDE / noteType));
            double totalBeats = beatCount + (fractionalBeat / (double)BEAT_SUBDIVIDE);

            double duration = totalBeats / (double)subDivisions;
            unsigned int rawNoteLength = BEAT_SUBDIVIDE * duration;

            if(noteIndex < subDivisions) {
                return rawNoteLength;
            }
            else {
                int expectedFractionalLen = BEAT_SUBDIVIDE * beatCount + fractionalBeat;
                int currentFractionalLen = rawNoteLength * subDivisions;

                return rawNoteLength + (expectedFractionalLen - currentFractionalLen);
            }
        }

        /**
         * Returns a beat
         * @param beatCount: the raw beat
         * @param fractionOffset: number between 1 and MAX_FRACTIONAL_BEAT indicating the exact moment the note should stop playing
         * */
        static unsigned int calculateBeat(int beatCount, int fractionalOffset) {
            return beatCount * BEAT_SUBDIVIDE + fractionalOffset;
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
        unsigned int activeBeatFX = BeatEffects::BEAT_FX_NONE;
        unsigned int arpeggioCounter = 0;
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