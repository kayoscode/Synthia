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

    timer.reset();
    createFurElise(song);
    std::cout << song.getDuration() << "\n";

    std::cout << "Loaded song - took : " << timer.milliseconds() << " milliseconds\n";

    audio.loadSong(song);

    audioPlayer.playAudio(audio);
    while(audioPlayer.isPlaying());
    getchar();
}