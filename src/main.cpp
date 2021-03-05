#include <iostream>
#include "AudioPlayer.h"

int main() {
    AudioPlayer audioPlayer;
    AudioBuffer audio;
    AudioBuffer audio2;

    if(audioPlayer.init(NULL) != AudioPlayerInitStatus::AUDIO_PLAYER_LOAD_SUCCESS) {
        std::cout << "failed to load audio player\n";
    }

    audio.loadAudioWAV("./test.wav");
    audio2.loadAudioWAV("./bloop.wav");

    audioPlayer.playAudio(audio);

    while(audioPlayer.isPlaying());

    audioPlayer.playAudio(audio2);
    while(audioPlayer.isPlaying());
}