
#ifndef INCLUDE_GEN_MUSIC_H
#define INCLUDE_GEN_MUSIC_H

#include "Song.h"

extern void createMinuetInG(Song& song) {
    song.setBPM(92 * 3);
    song.setTimeSignature(3, 8);

    Part* part = song.addPart("rawFreq", Instrument::PURE_FREQ);
    int indexTrebel = 0;
    int indexBass = 0;

    //measure 1

    std::cout << indexTrebel << " " << indexBass << "\n";
}

#endif