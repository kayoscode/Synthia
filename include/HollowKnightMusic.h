
#ifndef INCLUDE_HOLLOW_KNIGHT_MUSIC_H
#define INCLUDE_HOLLOW_KNIGHT_MUSIC_H

#include "Song.h"

extern void createMainTheme(Song& song) {
    song.setBPM(55);
    song.setTimeSignature(3, 4);

    Part* part = song.addPart("piano1", Instrument::PIANO);
    int indexTrebel = BEAT(0, 0);
    int indexBass = BEAT(0, 0);

    //measure 1
    //part->enableBeatEffects(BeatEffects::BEAT_FX_SLUR);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE6);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, DSH, OCTAVE6);

    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, G, OCTAVE4);
    indexBass = part->addHalfNote(indexBass, GSH, OCTAVE4);

    //measure2
    indexTrebel = part->addHalfNote(indexTrebel, D, OCTAVE6, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, F, OCTAVE4);
    indexBass = part->addHalfNote(indexBass, G, OCTAVE4);

    //measure 3
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, GSH, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE5);

    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE4);
    indexBass = part->addHalfNote(indexBass, F, OCTAVE4);

    //measure 4
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, D, OCTAVE4);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE4);
    indexBass = part->addEightNote(indexBass, D, OCTAVE4);
    indexBass = part->addQuarterNote(indexBass, ASH, OCTAVE3);

    //measure 5
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE6);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, DSH, OCTAVE6);

    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, G, OCTAVE4);
    indexBass = part->addHalfNote(indexBass, GSH, OCTAVE4);

    //measure 6
    indexTrebel = part->addHalfNote(indexTrebel, F, OCTAVE6, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, ASH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE4);
    indexBass = part->addHalfNote(indexBass, F, OCTAVE4);

    //measure 7
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, DSH, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE6);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE6);
    indexTrebel = part->addQuarterNote(indexTrebel, ASH, OCTAVE5);

    indexBass = part->addEightNote(indexBass, GSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE4);
    indexBass = part->addHalfNote(indexBass, F, OCTAVE4);

    //measure 8
    indexTrebel = part->addHalfNote(indexTrebel, C, OCTAVE6, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, F, OCTAVE4);
    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE3);

    //measure 9
    indexTrebel = part->addHalfNote(indexTrebel, HOLD, OCTAVE6, NoteEffects::NOTE_FX_EXTEND);

    part->enableBeatEffects(BeatEffects::BEAT_FX_ARPEGGIO);
    part->addHalfNote(indexBass, D, OCTAVE3);
    part->addHalfNote(indexBass, F, OCTAVE3);
    part->addHalfNote(indexBass, C, OCTAVE4);
    indexBass = part->addHalfNote(indexBass, F, OCTAVE4);
    part->enableBeatEffects(0);
    indexBass = part->addQuarterNote(indexBass, DSH, OCTAVE3);

    //measure 10
    part->addQuarterNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE4);
    part->addQuarterNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE4);
    part->addEightNote(indexTrebel, D, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE4);
    part->addEightNote(indexTrebel, DSH, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, DSH, OCTAVE4);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addHalfNote(indexBass, GSH, OCTAVE3);

    //measure 11
    part->addHalfNote(indexTrebel, D, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addHalfNote(indexTrebel, D, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addHalfNote(indexBass, G, OCTAVE3);

    //measure 12
    part->addEightNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE4);
    part->addEightNote(indexTrebel, G, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE3);
    part->addQuarterNote(indexTrebel, GSH, OCTAVE4);
    indexTrebel = part->addQuarterNote(indexTrebel, GSH, OCTAVE3);
    part->addEightNote(indexTrebel, G, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE3);
    part->addEightNote(indexTrebel, F, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE3);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, F, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, HOLD, OCTAVE5);

    //measure 13
    part->addHalfNote(indexTrebel, G, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE3, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, D, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, ASH, OCTAVE2);

    //measure 14
    part->addQuarterNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE4);
    part->addQuarterNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE4);
    part->addEightNote(indexTrebel, D, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE4);
    part->addEightNote(indexTrebel, DSH, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, DSH, OCTAVE4);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addHalfNote(indexBass, GSH, OCTAVE3);

    //measure 15
    part->addHalfNote(indexTrebel, F, OCTAVE5);
    indexTrebel = part->addHalfNote(indexTrebel, F, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, HOLD, OCTAVE5);
    part->add16Note(indexTrebel, G, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, G, OCTAVE4);
    part->add16Note(indexTrebel, GSH, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, GSH, OCTAVE4);

    indexBass = part->addEightNote(indexBass, F, OCTAVE2);
    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, GSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, C, OCTAVE4);

    //measure 16
    part->addQuarterNote(indexTrebel, G, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, G, OCTAVE4);
    part->addQuarterNote(indexTrebel, DSH, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addQuarterNote(indexTrebel, DSH, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    part->addEightNote(indexTrebel, ASH, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, ASH, OCTAVE3);

    indexBass = part->addEightNote(indexBass, DSH, OCTAVE2);
    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, C, OCTAVE4);

    //measure 17
    part->addQuarterNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE4);
    part->addQuarterNote(indexTrebel, ASH, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addQuarterNote(indexTrebel, ASH, OCTAVE3, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE4);

    indexBass = part->addEightNote(indexBass, GSH, OCTAVE2);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, D, OCTAVE3);

    //measure 18
    indexTrebel = part->addQuarterNote(indexTrebel, G, OCTAVE4);
    indexTrebel = part->addHalfNote(indexTrebel, C, OCTAVE4);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, GSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, GSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);

    //measure 19
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE6, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    
    //measure 20
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE4, NoteEffects::NOTE_FX_EXTEND | NoteEffects::NOTE_FX_DIMINUENDO);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);

    //measure 21
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE4, NoteEffects::NOTE_FX_DIMINUENDO);
    indexTrebel = part->addEightNote(indexTrebel, HOLD, OCTAVE4, NoteEffects::NOTE_FX_DIMINUENDO);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4, NoteEffects::NOTE_FX_DIMINUENDO);

    part->enableBeatEffects(BeatEffects::BEAT_FX_ARPEGGIO);
    part->addQuarterNote(indexBass, F, OCTAVE2);
    part->addQuarterNote(indexBass, ASH, OCTAVE2);
    indexBass = part->addQuarterNote(indexBass, D, OCTAVE3);
    part->enableBeatEffects(0);
    indexBass = part->addQuarterNote(indexBass, F, OCTAVE2);
    part->addQuarterNote(indexBass, ASH, OCTAVE2);
    indexBass = part->addQuarterNote(indexBass, D, OCTAVE3);

    //measure 22
    indexTrebel = part->addHalfNote(indexTrebel, B, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, GSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, GSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);

    //measure 23
    indexTrebel = part->addHalfNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addNote(indexTrebel, HOLD, OCTAVE5, part->getNoteFractionalDuration(3, 1, QUATER_NOTE));
    indexTrebel = part->addNote(indexTrebel, D, OCTAVE5, part->getNoteFractionalDuration(3, 2, QUATER_NOTE));
    indexTrebel = part->addNote(indexTrebel, DSH, OCTAVE5, part->getNoteFractionalDuration(3, 3, QUATER_NOTE));

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);

    //measure 24
    indexTrebel = part->addHalfNote(indexTrebel, F, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);

    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, DSH, OCTAVE3);

    //measure 25
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, ASH, OCTAVE5);

    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, D, OCTAVE4);

    //measure 26
    indexTrebel = part->addHalfNote(indexTrebel, C, OCTAVE6, NoteEffects::NOTE_FX_EXTEND);
    indexBass = part->addHalfNote(indexBass, C, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);

    std::cout << indexTrebel << " " << indexBass << "\n";
}

extern void createDirtmouthTheme(Song& song) {
    song.setBPM(87);
    song.setTimeSignature(4, 4);

    Part* part = song.addPart("rawFreq", Instrument::PURE_FREQ);
    int indexTrebel = BEAT(0, 0);
    int indexBass = BEAT(0, 0);
    
    //measure 1
    indexTrebel = part->addWholeNote(indexTrebel, FSH, OCTAVE4);
    
    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 2
    indexTrebel = part->addHalfNote(indexTrebel, FSH, OCTAVE4);
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE4, part->getNoteFractionalDuration(3, 1, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, part->getNoteFractionalDuration(3, 2, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE4, part->getNoteFractionalDuration(3, 3, HALF_NOTE));

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 3
    indexTrebel = part->addHalfNote(indexTrebel, FSH, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addEightNote(indexTrebel, HOLD, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE3);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 4
    indexTrebel = part->addWholeNote(indexTrebel, CSH, OCTAVE4);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 5
    indexTrebel = part->addWholeNote(indexTrebel, FSH, OCTAVE4);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 6
    indexTrebel = part->addHalfNote(indexTrebel, FSH, OCTAVE4);
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE4, part->getNoteFractionalDuration(3, 1, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, part->getNoteFractionalDuration(3, 2, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE4, part->getNoteFractionalDuration(3, 3,HALF_NOTE));

    indexBass = part->addEightNote(indexBass, D, OCTAVE2);
    indexBass = part->addEightNote(indexBass, A, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 7
    indexTrebel = part->addHalfNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addEightNote(indexTrebel, HOLD, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, G, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, FSH, OCTAVE4);

    indexBass = part->addEightNote(indexBass, C, OCTAVE2);
    indexBass = part->addEightNote(indexBass, G, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 8
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addQuarterNote(indexTrebel, B, OCTAVE3);

    indexBass = part->addEightNote(indexBass, C, OCTAVE2);
    indexBass = part->addEightNote(indexBass, G, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, D, OCTAVE2);

    //measure 9
    part->addWholeNote(indexTrebel, FSH, OCTAVE4);
    indexTrebel = part->addWholeNote(indexTrebel, FSH, OCTAVE5);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 10
    part->addHalfNote(indexTrebel, FSH, OCTAVE4);
    indexTrebel = part->addHalfNote(indexTrebel, FSH, OCTAVE5);
    part->addNote(indexTrebel, FSH, OCTAVE4, part->getNoteFractionalDuration(3, 1, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE5, part->getNoteFractionalDuration(3, 1, HALF_NOTE));
    part->addNote(indexTrebel, G, OCTAVE4, part->getNoteFractionalDuration(3, 2, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE5, part->getNoteFractionalDuration(3, 2, HALF_NOTE));
    part->addNote(indexTrebel, A, OCTAVE4, part->getNoteFractionalDuration(3, 3, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE5, part->getNoteFractionalDuration(3, 3, HALF_NOTE));

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 11
    part->addHalfNote(indexTrebel, FSH, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addHalfNote(indexTrebel, FSH, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addEightNote(indexTrebel, HOLD, OCTAVE3);
    part->addEightNote(indexTrebel, B, OCTAVE3);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 12
    part->addWholeNote(indexTrebel, CSH, OCTAVE4);
    indexTrebel = part->addWholeNote(indexTrebel, CSH, OCTAVE5);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 13
    part->addWholeNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addWholeNote(indexTrebel, E, OCTAVE5);

    indexBass = part->addEightNote(indexBass, C, OCTAVE2);
    indexBass = part->addEightNote(indexBass, G, OCTAVE2);
    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);

    //measure 14
    part->addHalfNote(indexTrebel, FSH, OCTAVE4);
    indexTrebel = part->addHalfNote(indexTrebel, FSH, OCTAVE5);
    part->addQuarterNote(indexTrebel, G, OCTAVE4);
    indexTrebel = part->addQuarterNote(indexTrebel, G, OCTAVE5);
    part->addQuarterNote(indexTrebel, A, OCTAVE4);
    indexTrebel = part->addQuarterNote(indexTrebel, A, OCTAVE5);

    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 15
    part->addHalfNote(indexTrebel, B, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addHalfNote(indexTrebel, B, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addEightNote(indexTrebel, HOLD, OCTAVE1);
    part->addEightNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE6);

    indexBass = part->addEightNote(indexBass, F, OCTAVE2);
    indexBass = part->addEightNote(indexBass, C, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, F, OCTAVE4);
    indexBass = part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 16
    part->addHalfNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addHalfNote(indexTrebel, B, OCTAVE5);
    part->addHalfNote(indexTrebel, G, OCTAVE4);
    indexTrebel = part->addHalfNote(indexTrebel, G, OCTAVE5);

    indexBass = part->addEightNote(indexBass, G, OCTAVE2);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE4);
    indexBass = part->addQuarterNote(indexBass, B, OCTAVE3, NoteEffects::NOTE_FX_EXTEND);

    //measure 17
    part->enableBeatEffects(BeatEffects::BEAT_FX_ARPEGGIO);
    part->addWholeNote(indexTrebel, FSH, OCTAVE4);
    part->addWholeNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addWholeNote(indexTrebel, FSH, OCTAVE5);
    part->enableBeatEffects(0);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 18
    part->addHalfNote(indexTrebel, FSH, OCTAVE5);
    part->addHalfNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addHalfNote(indexTrebel, FSH, OCTAVE4);
    part->addNote(indexTrebel, FSH, OCTAVE5, part->getNoteFractionalDuration(3, 1, HALF_NOTE));
    part->addNote(indexTrebel, B, OCTAVE4, part->getNoteFractionalDuration(3, 1, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE4, part->getNoteFractionalDuration(3, 1, HALF_NOTE));
    part->addNote(indexTrebel, G, OCTAVE5, part->getNoteFractionalDuration(3, 2, HALF_NOTE));
    part->addNote(indexTrebel, C, OCTAVE4, part->getNoteFractionalDuration(3, 2, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, part->getNoteFractionalDuration(3, 2, HALF_NOTE));
    part->addNote(indexTrebel, A, OCTAVE5, part->getNoteFractionalDuration(3, 3, HALF_NOTE));
    part->addNote(indexTrebel, D, OCTAVE4, part->getNoteFractionalDuration(3, 3, HALF_NOTE));
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE4, part->getNoteFractionalDuration(3, 3, HALF_NOTE));

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 19
    part->addWholeNote(indexTrebel, FSH, OCTAVE5);
    part->addWholeNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addWholeNote(indexTrebel, FSH, OCTAVE4);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 20
    part->addHalfNote(indexTrebel, CSH, OCTAVE6);
    indexTrebel = part->addHalfNote(indexTrebel, CSH, OCTAVE5);
    part->addQuarterNote(indexTrebel, CSH, OCTAVE6);
    indexTrebel = part->addQuarterNote(indexTrebel, CSH, OCTAVE5);
    part->addQuarterNote(indexTrebel, A, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, A, OCTAVE4);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 21
    /**
    part->addWholeNote(indexTrebel, G, OCTAVE5);
    indexTrebel = part->addWholeNote(indexTrebel, G, OCTAVE4);
    */

    std::cout << indexTrebel << " " << indexBass << "\n";
}

void createHornetTheme(Song& song) {
    song.setBPM(96 * 3);
    song.setTimeSignature(6, 8);

    Part* part = song.addPart("rawFreq", Instrument::PURE_FREQ);
    int indexTrebel = 0;
    int indexBass = 0;

    //measure 1
    part->addEightNote(indexTrebel, A, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexTrebel, F, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, A, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    
    part->addEightNote(indexBass, A, OCTAVE2, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 2
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE3);

    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 3
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);

    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 4
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, A, OCTAVE3);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE4);
    indexTrebel = part->addQuarterNote(indexTrebel, B, OCTAVE3);

    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, G, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);

    //measure 5
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);

    part->addEightNote(indexBass, A, OCTAVE2, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 6
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE3);

    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 7
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, F, OCTAVE4);

    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 8
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, A, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, A, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, A, OCTAVE4);
    
    part->addEightNote(indexBass, B, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    part->addEightNote(indexBass, B, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);

    //measure 9
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE5);

    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);

    //measure 10
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, A, OCTAVE4);
    
    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);

    //measure 11
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, C, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, B, OCTAVE4);
    indexTrebel = part->addEightNote(indexTrebel, A, OCTAVE4);

    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);

    //measure 12
    part->addEightNote(indexTrebel, E, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, G, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexTrebel, F, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE5);
    part->addEightNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE5);
    part->addEightNote(indexTrebel, F, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addEightNote(indexTrebel, D, OCTAVE5, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, E, OCTAVE5);
    part->addEightNote(indexTrebel, D, OCTAVE5);
    indexTrebel = part->addEightNote(indexTrebel, ASH, OCTAVE4);

    part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2);
    part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2);
    part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2);
    part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, ASH, OCTAVE2);

    //measure 13
    indexTrebel = part->addNote(indexTrebel, D, OCTAVE5, part->getNoteFractionalDuration(3, 1, QUATER_NOTE), NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addNote(indexTrebel, C, OCTAVE5, part->getNoteFractionalDuration(3, 2, QUATER_NOTE));
    indexTrebel = part->addNote(indexTrebel, ASH, OCTAVE4, part->getNoteFractionalDuration(3, 3, QUATER_NOTE));
    indexTrebel = part->addNote(indexTrebel, ASH, OCTAVE4, part->getNoteFractionalDuration(3, 1, QUATER_NOTE), NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE4, part->getNoteFractionalDuration(3, 2, QUATER_NOTE));
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, part->getNoteFractionalDuration(3, 3, QUATER_NOTE));
    indexTrebel = part->addNote(indexTrebel, F, OCTAVE4, part->getNoteFractionalDuration(3, 1, QUATER_NOTE), NoteEffects::NOTE_FX_CRESCENDO);
    indexTrebel = part->addNote(indexTrebel, E, OCTAVE4, part->getNoteFractionalDuration(3, 2, QUATER_NOTE));
    indexTrebel = part->addNote(indexTrebel, D, OCTAVE4, part->getNoteFractionalDuration(3, 3, QUATER_NOTE));

    part->addHalfNote(indexBass, ASH, OCTAVE1, NoteEffects::NOTE_FX_EXTEND);
    indexBass = part->addHalfNote(indexBass, ASH, OCTAVE2, NoteEffects::NOTE_FX_EXTEND);

    //measure 14
    part->addQuarterNote(indexTrebel, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO | NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addQuarterNote(indexTrebel, A, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO | NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addHalfNote(indexTrebel, E, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);

    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, E, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE2, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, C, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 15
    indexTrebel = part->addQuarterNote(indexTrebel, HOLD, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);

    part->addEightNote(indexBass, G, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, F, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, D, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 16
    indexTrebel = part->addQuarterNote(indexTrebel, G, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, F, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, D, OCTAVE5);

    part->addEightNote(indexBass, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 17
    indexTrebel = part->addQuarterNote(indexTrebel, E, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE5);
    indexTrebel = part->addQuarterNote(indexTrebel, B, OCTAVE4);

    part->addEightNote(indexBass, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);
    part->addEightNote(indexBass, E, OCTAVE4);
    indexBass = part->addEightNote(indexBass, A, OCTAVE3);

    //measure 18
    indexTrebel = part->addQuarterNote(indexTrebel, A, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addQuarterNote(indexTrebel, D, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);

    part->addEightNote(indexBass, C, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, C, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, C, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);

    //measure 19
    indexTrebel = part->addQuarterNote(indexTrebel, C, OCTAVE5, NoteEffects::NOTE_FX_EXTEND);
    indexTrebel = part->addQuarterNote(indexTrebel, B, OCTAVE4, NoteEffects::NOTE_FX_EXTEND);

    part->addEightNote(indexBass, E, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, D, OCTAVE4);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, C, OCTAVE4, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);

    //measure 20
    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, G, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, B, OCTAVE4);

    indexTrebel = part->add16Note(indexTrebel, G, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, B, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, C, OCTAVE5);

    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, B, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, C, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, D, OCTAVE5);
    //bass
    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);
    part->addEightNote(indexBass, A, OCTAVE3);
    indexBass = part->addEightNote(indexBass, D, OCTAVE3);

    //measure 21
    indexTrebel = part->add16Note(indexTrebel, B, OCTAVE4);
    indexTrebel = part->add16Note(indexTrebel, C, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, D, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);

    indexTrebel = part->add16Note(indexTrebel, C, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, D, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);

    indexTrebel = part->add16Note(indexTrebel, D, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, G, OCTAVE5);

    //bass
    part->addEightNote(indexBass, B, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    part->addEightNote(indexBass, B, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, C, OCTAVE4);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    part->addEightNote(indexBass, B, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3, NoteEffects::NOTE_FX_CRESCENDO);
    part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);

    //measure 22
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, GSH, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);

    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, GSH, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, GSH, OCTAVE5);

    //bass
    indexBass = part->addQuarterNote(indexBass, A, OCTAVE3, NoteEffects::NOTE_FX_EXTEND);
    indexBass = part->addHalfNote(indexBass, E, OCTAVE4);

    //measure 23
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, GSH, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);

    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, GSH, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, A, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, E, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, F, OCTAVE5);
    indexTrebel = part->add16Note(indexTrebel, GSH, OCTAVE5);

    indexBass = part->addEightNote(indexBass, HOLD, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, E, OCTAVE3);
    indexBass = part->addQuarterNote(indexBass, C, OCTAVE3);

    //measure 24
    std::cout << indexTrebel << " " << indexBass << "\n";
}

#endif