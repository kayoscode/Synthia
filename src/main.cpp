#include <iostream>
#include "AudioPlayer.h"

int main() {
    AudioBuffer audio;
    AudioPlayer audioPlayer;
    Song song(87, 4, 4);

    if(audioPlayer.init(NULL) != AudioPlayerInitStatus::AUDIO_PLAYER_LOAD_SUCCESS) {
        std::cout << "failed to load audio player\n";
    }

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
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE4, 10);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 3
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE4, (MAX_FRACTIONAL_BEAT) - (MAX_FRACTIONAL_BEAT / 8));
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
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE4, 10);

    indexBass = part->addEightNote(indexBass, D, OCTAVE2);
    indexBass = part->addEightNote(indexBass, A, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, F, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 7
    indexTrebel = part->addNote(indexTrebel, E, OCTAVE4, (MAX_FRACTIONAL_BEAT) - (MAX_FRACTIONAL_BEAT / 8));
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
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, (MAX_FRACTIONAL_BEAT) - (MAX_FRACTIONAL_BEAT / 4));
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
    part->addNote(indexTrebel, FSH, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE5, 11);
    part->addNote(indexTrebel, G, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE5, 11);
    part->addNote(indexTrebel, A, OCTAVE4, 10);
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE5, 10);

    indexBass = part->addEightNote(indexBass, E, OCTAVE2);
    indexBass = part->addEightNote(indexBass, B, OCTAVE2);
    indexBass = part->addEightNote(indexBass, E, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, B, OCTAVE3);
    indexBass = part->addEightNote(indexBass, G, OCTAVE3);
    indexBass = part->addEightNote(indexBass, FSH, OCTAVE3);

    //measure 11
    part->addNote(indexTrebel, FSH, OCTAVE4, (MAX_FRACTIONAL_BEAT) - (MAX_FRACTIONAL_BEAT / 8));
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE5, (MAX_FRACTIONAL_BEAT) - (MAX_FRACTIONAL_BEAT / 8));
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
    part->addNote(indexTrebel, B, OCTAVE4, (MAX_FRACTIONAL_BEAT) - (MAX_FRACTIONAL_BEAT / 8));
    indexTrebel = part->addNote(indexTrebel, B, OCTAVE5, (MAX_FRACTIONAL_BEAT) - (MAX_FRACTIONAL_BEAT / 8));
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
    indexBass = part->addQuarterNote(indexBass, D, OCTAVE4);
    indexBass = part->addQuarterNote(indexBass, B, OCTAVE3);

    //measure 17
    part->addNote(indexTrebel + 2, B, OCTAVE4, (MAX_FRACTIONAL_BEAT) - 2);
    part->addNote(indexTrebel + 3, FSH, OCTAVE5, (MAX_FRACTIONAL_BEAT) - 1);
    indexTrebel = part->addWholeNote(indexTrebel, FSH, OCTAVE4);

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
    part->addNote(indexTrebel, FSH, OCTAVE5, 11);
    part->addNote(indexTrebel, B, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, FSH, OCTAVE4, 11);
    part->addNote(indexTrebel, G, OCTAVE5, 11);
    part->addNote(indexTrebel, C, OCTAVE4, 11);
    indexTrebel = part->addNote(indexTrebel, G, OCTAVE4, 11);
    part->addNote(indexTrebel, A, OCTAVE5, 10);
    part->addNote(indexTrebel, D, OCTAVE4, 10);
    indexTrebel = part->addNote(indexTrebel, A, OCTAVE4, 10);

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
    part->addWholeNote(indexTrebel, G, OCTAVE5);
    indexTrebel = part->addWholeNote(indexTrebel, G, OCTAVE4);

    std::cout << indexTrebel << " " << indexBass << "\n";
    std::cout << song.getDuration() << "\n";

    audio.loadSong(song);

    audioPlayer.playAudio(audio);
    while(audioPlayer.isPlaying());
    getchar();
}