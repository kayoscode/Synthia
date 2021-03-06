#include <iostream>
#include "AudioPlayer.h"

int main() {
    AudioBuffer audio;
    AudioPlayer audioPlayer;

    if(audioPlayer.init(NULL) != AudioPlayerInitStatus::AUDIO_PLAYER_LOAD_SUCCESS) {
        std::cout << "failed to load audio player\n";
    }

    audioPlayer.playAudio(audio);
    while(audioPlayer.isPlaying());
    getchar();
}