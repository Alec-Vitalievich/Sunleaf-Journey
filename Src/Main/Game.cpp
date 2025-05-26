#include "Main/Game.h"
#include "Screens/Menu.h"
#include "Screens/Story_Screen.h"
#include "Screens/End_Screen.h"
#include "Screens/Pause_Screen.h"
#include "Save/save_data.h"
#include "Save/save_manager.h"
#include <SFML/Audio.hpp>

// Game constructor.
Game::Game(std::string window_name, int max_framerate) : window(sf::VideoMode(1800, 1020), window_name), player(0, 0, 50, 50, 3, 0),
                                                         story_screen(font, sf::Vector2u(1800, 1020)),
                                                         end_screen(font, sf::Vector2u(1800, 1020)),
                                                         control_screen(font, sf::Vector2u(1800, 1020))
{

    // Load font.
    if (!font.loadFromFile("Assets/Fonts/m6x11plus.ttf"))
    {
        std::cerr << "Failed to load font";
    }

    // Initialise main variables
    this->game_name = window_name;
    this->max_framerate = max_framerate;
    this->window_size = window.getSize();

    // Set frame rate and reset clock
    window.setFramerateLimit(max_framerate);
    clock.restart();

    // Allocate memory for pointers.
    new_level = new bool;
    current_level = new int;

    // Check for existence of save file - create default if none is found.
    if (!save_manager::load_game(save_game_data, "Assets/Saves/save.txt"))
    {
        std::cerr << "Failed to load save";
        save_game_data = save_data(1, 3, 0);
    }
}

// Function to check if a new level should be loaded.
void Game::load_level(bool *new_level)
{
    if (*new_level == true)
    {
        // If a level exists, delete it.
        if (level)
        {
            delete level;
            level = nullptr;
        }

        *new_level = false;
        // Initiate end screen if the final level is completed.
        if (*current_level > 3)
        {
            window.clear();
            current_state = GameState::END;
        }
        // Load next level using the Level class.
        else
        {
            level = new Level(current_level, new_level);
        }
    }
}

// Function handling the game loop/updating all values and windows.
void Game::update()
{

    // Load main menu.
    Menu menu(window);
    Pause_Screen pause_screen(window);

    /* if (!background_music.play("Music/menu_music.ogg", true)) {
        std::cerr << "Error loading music\n";
    } */

    // Logic when game is running.
    while (window.isOpen())
    {
        // Check current gamestate.
        if (current_state == GameState::MENU)
        {
            if (level)
            {
                delete level;
                level = nullptr;
            }

            // Check if the window has detected any events (key presses, mouse clicks, etc).
            sf::Event event;
            while (window.pollEvent(event))
            {
                on_close_action(event);

                // Check if a mouse click has occured (for the menu buttons).
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

                    // Menu buttons leading to respective gamestate.
                    if (menu.is_start_clicked(mouse_position))
                    {
                        current_state = GameState::STORY;
                    }
                    if (menu.is_controls_clicked(mouse_position))
                    {
                        current_state = GameState::CONTROLS;
                    }

                    // Functionality of Load button. Retrieves data from the save file.
                    if (menu.is_load_clicked(mouse_position))
                    {
                        // Attempt to retrieve data from save file.
                        if (save_manager::load_game(save_game_data, "Assets/Saves/save.txt"))
                        {
                            // Set player attributes & load the appropriate level.
                            *current_level = save_game_data.get_level_number();
                            player.set_player_position(0, 800);
                            player.set_player_health(save_game_data.get_player_health());
                            player.set_sun_count(save_game_data.get_sun_count());
                            player.set_saved_player_health(save_game_data.get_player_health());
                            player.set_saved_sun_count(save_game_data.get_sun_count());

                            *new_level = true;
                            load_level(new_level);
                            current_state = GameState::PLAYING;
                        }
                        else
                        {
                            std::cerr << "Failed to load game";
                        }
                    }

                    // Close the window when the quit button is pressed, ending the program.
                    if (menu.is_exit_clicked(mouse_position))
                    {
                        window.close();
                    }
                }
            }

            // Pass mouse position to menu to increase button size when hovering over them.
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
            menu.update(mouse_position);

            // Draw menu assets in window.
            window.clear();
            menu.draw(window);
            window.display();
        }

        // 'Story screen' gamestate logic.
        else if (current_state == GameState::STORY)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                on_close_action(event);

                // Change gamestates depending on key pressed
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    // Load first level if user chooses to continue.
                    *current_level = 1;
                    *new_level = true;
                    load_level(new_level);
                    player.set_sun_count(0);
                    player.set_player_health(3);
                    player.set_player_position(0, 800);
                    current_state = GameState::PLAYING;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace)
                {
                    // Return to menu screen.
                    current_state = GameState::MENU;
                }
            }

            // Draw story assets in window.
            window.clear();
            story_screen.draw(window);
            window.display();
        }

        // 'Controls' screen gamestate.
        else if (current_state == GameState::CONTROLS)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                on_close_action(event);

                // Return to main menu from controls screen.
                if (control_screen.handle_event(event))
                {
                    current_state = GameState::MENU;
                }
            }

            // Draw 'Controls' screen assets in window.
            window.clear();
            control_screen.draw(window);
            window.display();
        }

        // Playing gamestate
        else if (current_state == GameState::PLAYING)
        {
            dt = clock.restart().asSeconds(); // Returns the time since last restart of the clock.
            // Prevent deltatime (dt - time since last frame) from becoming too large, such as when pausing.
            if (dt > 0.2)
            {
                dt = 0.2;
            }
            else if (dt < 0.0)
            {
                dt = 0.0;
            }

            // Check if the user exits, returns to menu, or pauses the game.
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace)
                {
                    current_state = GameState::MENU;
                }
                if (event.type == sf::Event::Closed)
                {
                    // Save data and close game.
                    save_game_data.set_level_number(*current_level);
                    save_game_data.set_player_health(player.get_saved_player_health());
                    save_game_data.set_sun_count(player.get_saved_sun_count());
                    save_manager::save_game(save_game_data, "Assets/Saves/save.txt");
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    // Save data and pause game.
                    current_state = GameState::PAUSE;

                    save_game_data.set_level_number(*current_level);
                    save_game_data.set_player_health(player.get_saved_player_health());
                    save_game_data.set_sun_count(player.get_saved_sun_count());
                    save_manager::save_game(save_game_data, "Assets/Saves/save.txt");
                }
            }

            // Retrieve level data, and update player sprite.
            std::vector<Object *> level_data = level->get_level_vector();
            player.player_update(dt, level_data);

            // Draw game data/assets (background, level, player, etc) in window.
            window.clear();
            level->draw_background(window);
            level->custom_stats_display(window, font, player);
            level->draw_interactive_text(window, font);
            for (int i = 0; i < level_data.size(); i++)
            {
                window.draw(level_data[i]->get_object_hitbox());
            }
            window.draw(player.get_player_hitbox());
            window.display();

            // Call function to check if the next level needs to be loaded.
            load_level(new_level);
            // Game reset if health is less than one.
            if (player.get_player_health() < 1)
            {
                game_reset();
            }
        }

        // End screen gamestate
        else if (current_state == GameState::END)
        {
            // If a level exists, delete it.
            if (level)
            {
                delete level;
                level = nullptr;
            }

            // Reset save data to default.
            save_game_data.set_level_number(1);
            save_game_data.set_player_health(3);
            save_game_data.set_sun_count(0);
            save_manager::save_game(save_game_data, "Assets/Saves/save.txt");

            // Check for keyboard events.
            sf::Event event;
            while (window.pollEvent(event))
            {
                on_close_action(event);

                if (end_screen.handle_event(event))
                {
                    current_state = GameState::MENU;
                }
            }

            // Draw 'end sreen' assets in window
            window.clear();
            end_screen.draw(window);
            window.display();
        }

        // Pause gamestate
        else if (current_state == GameState::PAUSE)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                on_close_action(event);
                // Check if mouse event has occured.
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

                    // Check if a button has been pressed.
                    if (pause_screen.is_resume_clicked(mouse_position))
                        current_state = GameState::PLAYING;
                    if (pause_screen.is_quit_clicked(mouse_position))
                        current_state = GameState::MENU;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    current_state = GameState::PLAYING;
            }

            // Pass mouse position to menu to increase button size when hovering over them.
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
            pause_screen.update(mouse_position);

            // Block of code to make the pause menu transparent so you can still see the level (see Playing for more information).
            std::vector<Object *> level_data = level->get_level_vector();
            window.clear();
            level->draw_background(window);
            level->custom_stats_display(window, font, player);
            level->draw_interactive_text(window, font);
            for (int i = 0; i < level_data.size(); i++)
            {
                window.draw(level_data[i]->get_object_hitbox());
            }
            window.draw(player.get_player_hitbox());

            // Create transparent overlay.
            sf::RectangleShape transparent_overlay;
            transparent_overlay.setSize(sf::Vector2f(window_size.x, window_size.y));
            transparent_overlay.setFillColor(sf::Color(0, 0, 0, 150)); // RGBA - 150 alpha for ~50% opacity
            window.draw(transparent_overlay);

            // Draw 'Pause' assets in window.
            pause_screen.draw(window);
            window.display();
        }
    }
}
// Game reset
void Game::game_reset()
{
    *current_level = 1;
    *new_level = true;
    load_level(new_level);
    player.set_sun_count(0);
    player.set_player_health(3);
    player.set_player_position(0, 800);
}

void Game::on_close_action(sf::Event event)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}

// dt getter
double Game::get_dt()
{
    return dt;
}

// Game destructor
Game::~Game()
{
    if (level)
    {
        delete level;
    }
    if (new_level)
    {
        delete new_level;
    }
    if (current_level)
    {
        delete current_level;
    }
}