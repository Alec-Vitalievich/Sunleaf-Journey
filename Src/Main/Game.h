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

// Different game states to handle events
enum class GameState
{
    MENU,
    STORY,
    PLAYING,
    CONTROLS,
    PAUSE,
    END,
};

// Main class - manages all other classes and processes.
class Game
{
protected:

    // General game variables.
    sf::Vector2u window_size;
    std::string game_name;
    int max_framerate;

    // Clock/time object & variable.
    sf::Clock clock;
    double dt; // Delta time (time elapsed since last frame)

    // Player object and level-related pointers.
    Player player;
    Level *level = nullptr;
    int *current_level;
    bool *new_level = nullptr;

    // Default gamestate.
    GameState current_state = GameState::MENU;

    // Other objects.
    sf::RenderWindow window;
    save_data save_game_data;

    // Music background_music;
    // OS specific

    // Screens
    Story_Screen story_screen;
    Controls_Screen control_screen;
    End_Screen end_screen;

    // Font
    sf::Font font;

public:

    // Game constructor
    Game(int window_x_size, int window_y_size, std::string name, int max_framerate); // Update to remove window size variables

    // Game state handling
    void load_level(bool *new_level);
    void update();
    double get_dt();
    void game_reset();
<<<<<<< HEAD
    void on_close_action(sf::Event event);
=======

    // Destructor
>>>>>>> refs/remotes/origin/v1.1
    ~Game();
};

#endif