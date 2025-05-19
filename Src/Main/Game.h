#ifndef GAME_H
#define GAME_H
#include "Main/Player.h"
#include "Levels/Level.h"
#include "Screens/Menu.h"
// #include "Audio/Music.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include "Levels/Level.h"
#include "Save/save_data.h"
#include "Screens/Story_Screen.h"
#include "Screens/End_Screen.h"
#include "Screens/Controls_Screen.h"
#include "Screens/Pause_Screen.h"
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
        Story_Screen story_screen;
        Controls_Screen control_screen;
        End_Screen end_screen;

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