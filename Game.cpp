#include "Game.h"
#include "Menu.h"
#include "save_data.h"
#include "save_manager.h"
#include <SFML/Audio.hpp>

// Game constructor
Game::Game(int window_size_x, int window_size_y, std::string window_name, int max_framerate, int current_level):window(sf::VideoMode(window_size_x, window_size_y), window_name),player(10,400,50,50,3,0){
    
    // Initialise main variables
    this->game_name = window_name;
    this->max_framerate = max_framerate;
    this->current_level = current_level;
    this->window_size = window.getSize();
    

    // Set frame rate and reset clock
    window.setFramerateLimit(max_framerate);
    clock.restart();

    // Load first level
    new_level = new bool;
    *new_level = true;
    load_level(new_level);

    // Save handling
    if (!save_manager::load_game(save_game_data, "Assets/Saves/save.txt")) {
        std::cerr << "Failed to load save";
        save_game_data = save_data(0, 10, 400, 3, 0);
    }

    // Extract and apply sava data to current game
    current_level = save_game_data.get_level_number();
    player.set_player_position(save_game_data.get_player_position_x(), save_game_data.get_player_position_y());
    player.set_player_health(save_game_data.get_player_health());
    player.set_sun_count(save_game_data.get_sun_count());
    }       


// Level loading handling
void Game::load_level(bool* new_level){
        if(*new_level == true){
            if(level){ // Checks if the pointer is not null. level != nullptr could be used for clarity?
                delete level;
            }
            *new_level = false;
            level = new Level(current_level, new_level);
     }
}


// Game update handling
void Game::update(){ 

    // Load main menu
    Menu menu(window);

        /* if (!background_music.play("Music/menu_music.ogg", true)) {
            std::cerr << "Error loading music\n";
        } */
        
    // Logic when game is running
    while(window.isOpen()){

        // Check current gamestate
        if (current_state == GameState::MENU) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) window.close();

                // Get mouse position when clicking for button functionality
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Menu buttons leading to respective gamestate
                    if (menu.is_start_clicked(mousePos)) current_state = GameState::STORY;
                    if (menu.is_controls_clicked(mousePos)) current_state = GameState::CONTROLS;

                    // Load clicked -> load game from save
                    if (menu.is_load_clicked(mousePos)) {
                        if (save_manager::load_game(save_game_data, "Assets/Saves/save.txt")) {
                            current_level = save_game_data.get_level_number();
                            player.set_player_position(save_game_data.get_player_position_x(), save_game_data.get_player_position_y());
                            player.set_player_health(save_game_data.get_player_health());
                            player.set_sun_count(save_game_data.get_sun_count());

                            *new_level = true;
                            load_level(new_level);
                            current_state = GameState::PLAYING;

                        } else {
                            std::cerr << "Failed to load game";
                        }
                    }

                    // If exit clicked -> quit/exit the game
                    if (menu.is_exit_clicked(mousePos)) window.close();
                        
                }
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            menu.update(mousePos);

            window.clear();
            menu.draw(window);
            window.display();
            }

        // Story screen gamestate logic
        else if (current_state == GameState::STORY) {
            sf::Event event;
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Change gamestates depending on key pressed
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    current_state = GameState::PLAYING;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
                    current_state = GameState::MENU;
                }
            }
                
        window.clear();

        sf::Font font;
        font.loadFromFile("Assets/Fonts/antiquity-print.ttf");
        sf::Text story_text;
        story_text.setFont(font);
        story_text.setString("Buried in the darkness below,\n"
                            "a small seedling sprouts,\n"
                            "unfurling its leaves in a strange new world.\n\n"

                            "You don't know how you got here,\n"
                            "but you sense something is missing.\n"
                            "Whilst the soil is lush with nutrients\n"
                            "and water abounds, there's little light\n"
                            "to be found. How will you grow without the sun?\n\n"

                            "You must begin your journey to find the light\n"
                            "and find a home a place to set down roots.\n"
                            "Collect little slices of sun whilst traversing\n"
                            "through a whole new world from dim caves full\n"
                            "of dangerous obstacles to forests full of\n"
                            "dappled light and shadow to reach your perfect\n"
                            "patch of sun. But beware, it's a dangerous world\n"
                            "out there for a small Sunleaf.\n"
                            "\n");
        story_text.setCharacterSize(24);
        story_text.setFillColor(sf::Color::White);
        story_text.setPosition(100, 65);

        //Separate text for continuing the game
        sf::Text continue_text;
        continue_text.setFont(font);
        continue_text.setString("...Press ENTER to continue");
        continue_text.setCharacterSize(24);
        continue_text.setFillColor(sf::Color::Yellow);

        //Position text
        sf::Vector2u window_size = window.getSize();
        float continue_text_x = 100;
        float continue_text_y = window_size.y - 70;
        continue_text.setPosition(continue_text_x, continue_text_y);

        window.draw(story_text);
        window.draw(continue_text);
        window.display();

        }

    // Controls gamestate
    else if (current_state == GameState::CONTROLS) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Return to main menu from controls screen
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                current_state = GameState::MENU;
            }
        }

        window.clear();

        // Text to explain controls
        sf::Font font;
        font.loadFromFile("Assets/Fonts/antiquity-print.ttf");
        sf::Text controls_text;
        sf::Text return_text;
        controls_text.setFont(font);
        return_text.setFont(font);

        controls_text.setString("WASD for movement keys\n"
                                "E to interact");

        return_text.setString("... Press ENTER to return to the main menu");
        
        controls_text.setCharacterSize(24);
        controls_text.setFillColor(sf::Color::White);
        controls_text.setPosition(100, 65);

        return_text.setCharacterSize(24);
        return_text.setFillColor(sf::Color::Yellow);
        return_text.setPosition(100, 25);

        window.draw(controls_text);
        window.draw(return_text);
        window.display();

    }

    // Playing gamestate
    else if (current_state == GameState::PLAYING) {
        dt = clock.restart().asSeconds(); // Returns the time since restart was last called.
    if(dt > 0.5){ // Prevents delta time from becoming too large. (dt checks time since last frame - if the window was paused for instance, this could become huge otherwise).
        dt = 0.5; // We may want to play with this value a bit.
    }
    else if(dt < 0.0){ // Shouldn't be possible, but just in case.
        dt = 0.0;
    }

    sf::Event event; // Could be moved to constructor, but it's essentially empty so initialising every loop isn't intensive. May improve readability? To be revisited.
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
            window.close();

            //Save the game
            save_game_data.set_level_number(current_level);
            save_game_data.set_player_position(player.get_player_position().x, player.get_player_position().y);
            save_game_data.set_player_health(player.get_player_health());
            save_game_data.set_sun_count(player.get_sun_count());

            save_manager::save_game(save_game_data, "Assets/Saves/save.txt");
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace){
            current_state = GameState::MENU;
        }
    }

        load_level(new_level);

        std::vector<Object*> level_data = level->get_level_vector();
        player.player_update(dt, level_data);
        window.clear();
        level->draw_background(window);

        for(int i = 0; i < level_data.size(); i++){
            window.draw(level_data[i]->get_object_hitbox());
        }
        window.draw(player.get_player_hitbox());
        window.display();
        }
    }

        // Update player, update window, etc.
}

// Game dt getter
    double Game::get_dt(){
        return dt;
    }

// Game destructor
    Game::~Game(){
        // Delete level perhaps?
    }