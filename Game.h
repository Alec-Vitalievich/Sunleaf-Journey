#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Level.h"
#include "Menu.h"
#include "Music.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include "Level.h"
#include "save_data.h"
#include "Story_Screen.h"
#include "End_Screen.h"
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>
// #include <SFML/System.hpp>

//Different game states
enum class GameState {
    MENU,
    STORY,
    PLAYING,
    CONTROLS,
    PAUSE,
    END,
};

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
        int current_level;
        bool* new_level = nullptr;

        GameState current_state = GameState::MENU;

        save_data save_game_data;

        // Music background_music;

        // Screens
        story_screen story_screen;
        end_screen end_screen;

        // Font
        sf::Font font;

    public:
        Game(int window_x_size, int window_y_size, std::string name, int max_framerate, int current_level);
        void load_level(bool* new_level);
        void update(); // Removed parameter: sf::RectangleShape& player_hitbox
        double get_dt();
        ~Game();
};

#endif