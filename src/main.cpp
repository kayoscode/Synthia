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

    //Part* p = song.addPart("piano1", new LofiPiano());
    //int duration = 0;
    //duration = p->addHalfNote(duration, F, OCTAVE3);
    //duration = p->add16Note(duration, D, OCTAVE3);
    //duration = p->add16Note(duration, E, OCTAVE4);
    //duration = p->add16Note(duration, F, OCTAVE4);
    //duration = p->add16Note(duration, G, OCTAVE4);
    //duration = p->add16Note(duration, A, OCTAVE4);
    //duration = p->add16Note(duration, B, OCTAVE4);
    //duration = p->add16Note(duration, C, OCTAVE5);

    timer.reset();
    createDirtmouthTheme(song);
    std::cout << song.getDuration() << "\n";
    audio.loadSong(song);
    std::cout << "Loaded song - took : " << timer.milliseconds() << " milliseconds\n";

    audioPlayer.playAudio(audio);
    while(audioPlayer.isPlaying());

    getchar();
    //delete song.getPart("piano1");
}