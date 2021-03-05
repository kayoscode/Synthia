#include <iostream>
#include "AudioPlayer.h"

int main() {
    char spectograph[] {
        1,0,0,0,0,0,0,0,0,0,0,
        0,1,0,0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,0,0,0,0,0,
        0,0,0,1,0,0,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,1,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,
        0,0,0,0,0,0,0,1,0,0,0,
        0,0,0,0,0,0,0,0,1,0,0,
        0,0,0,0,0,0,0,0,0,1,0,
        0,0,0,0,0,0,0,0,0,0,1,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0
    };

    AudioBuffer audio;
    AudioPlayer audioPlayer;

    if(audioPlayer.init(NULL) != AudioPlayerInitStatus::AUDIO_PLAYER_LOAD_SUCCESS) {
        std::cout << "failed to load audio player\n";
    }
    
    audio.loadSpectograph(spectograph, 11, 22, 100, 1000, .1);

    audioPlayer.playAudio(audio);
    while(audioPlayer.isPlaying());
}