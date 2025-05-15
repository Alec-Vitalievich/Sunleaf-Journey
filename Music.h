#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>

class Music {
    private:
        sf::Music background_music;
        
    public:
        bool play(const std::string& filename, bool loop = true);
        void stop();
        void set_volume(float volume);
        bool is_playing() const;
};

#endif