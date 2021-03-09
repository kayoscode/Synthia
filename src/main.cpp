#include <iostream>
#include "AudioPlayer.h"
#include "Timer.h"
#include "HollowKnightMusic.h"
#include "GeneralMusic.h"

int main() {
    AudioBuffer audio;
    AudioPlayer audioPlayer;
    Song song;
    Timer timer;

    if(audioPlayer.init(NULL) != AudioPlayerInitStatus::AUDIO_PLAYER_LOAD_SUCCESS) {
        std::cout << "failed to load audio player\n";
    }

    /**
    Part* p = song.addPart("piano1", new LofiPiano());
    int duration = 0;
    duration = p->addHalfNote(duration, F, OCTAVE3);
    duration = p->addHalfNote(duration, D, OCTAVE3);
    duration = p->addHalfNote(duration, E, OCTAVE4);
    duration = p->addHalfNote(duration, F, OCTAVE4);
    duration = p->addHalfNote(duration, G, OCTAVE4);
    duration = p->addHalfNote(duration, A, OCTAVE4);
    duration = p->addHalfNote(duration, B, OCTAVE4);
    duration = p->addHalfNote(duration, C, OCTAVE5);
    */

    timer.reset();
    createHornetTheme(song);
    std::cout << song.getDuration() << "\n";
    std::cout << "Loaded song - took : " << timer.milliseconds() << " milliseconds\n";

    song.saveAsWav("song");
    //audio.loadAudioWAV("song.wav");
    //audio.loadSong(song);

    //audioPlayer.playAudio(audio);
    //while(audioPlayer.isPlaying());

    //getchar();
    //delete song.getPart("piano1");
}