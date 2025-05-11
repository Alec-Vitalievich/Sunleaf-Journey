#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Level.h"
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>
// #include <SFML/System.hpp>

class Game {
    protected:
        sf::Vector2u window_size;
        std::string game_name;
        int max_framerate;

        sf::RenderWindow window;
        sf::Clock clock; 
        double dt; // Delta time (time elapsed since last frame)
        Player player;
        Level* level = nullptr; // was getting seg faults if it wasn't initialised as a nullptr.
    public:
        Game(int window_x_size, int window_y_size, std::string name, int max_framerate);
        void load_level(int level_number);
        void update(); // Removed parameter: sf::RectangleShape& player_hitbox
        double get_dt();
        ~Game();
};

#endif