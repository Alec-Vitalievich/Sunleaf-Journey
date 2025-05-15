#include "Music.h"
#include <iostream>

bool Music::play(const std::string& filename, bool loop) {
    if (!background_music.openFromFile("Music/menu_music.ogg")) {
        return false;
    } else {
        background_music.setLoop(loop);
        background_music.play();
        return true;
    }

}

void Music::stop() {
    background_music.stop();
}

void Music::set_volume(float volume) {
    background_music.setVolume(volume);

}

bool Music::is_playing() const {
    return background_music.getStatus() == sf::SoundSource::Playing;
}

