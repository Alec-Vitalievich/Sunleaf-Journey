#include "Main/Game.h"
#include "Screens/Menu.h"
#include "Screens/Story_Screen.h"
#include "Screens/End_Screen.h"
#include "Screens/Pause_Screen.h"
#include "Save/save_data.h"
#include "Save/save_manager.h"
#include <SFML/Audio.hpp>

/*pause_screen(font, sf::Vector2u(window_size_x, window_size_y))*/

// Game constructor
Game::Game(int window_size_x, int window_size_y, std::string window_name, int max_framerate,
           int current_level):window(sf::VideoMode(window_size_x, window_size_y), window_name)
           ,player(0,0,50,50,3,0), 
           story_screen(font, sf::Vector2u(window_size_x, window_size_y)),
           end_screen(font, sf::Vector2u(window_size_x, window_size_y)),
           control_screen(font, sf::Vector2u(window_size_x, window_size_y)){
    
    // Load font
    if (!font.loadFromFile("Assets/Fonts/antiquity-print.ttf")) {
        std::cerr << "Failed to load font";
    }
    
    // Initialise main variables
    this->game_name = window_name;
    this->max_framerate = max_framerate;
    this->current_level = current_level;
    this->window_size = window.getSize();
    

    // Set frame rate and reset clock
    window.setFramerateLimit(max_framerate);
    clock.restart();


    new_level = new bool;

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
                current_level++;
            }
            *new_level = false;

            if (current_level > 3) {
                window.clear();
                current_state = GameState::END;
            } else {
                level = new Level(current_level, new_level);
            }
     }
}


// Game update handling
void Game::update(){ 

    // Load main menu
    Menu menu(window);
    Pause_Screen pause_screen(window);

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
                current_level = 1;
                *new_level = true;
                load_level(new_level);
                player.set_sun_count(0);
                player.set_player_health(3);
                player.set_player_position(0,800);
                current_state = GameState::PLAYING;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
                current_state = GameState::MENU;
            }
        }
            
    window.clear();
    story_screen.draw(window);
    window.display();


    }

    // Controls gamestate
    else if (current_state == GameState::CONTROLS) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Return to main menu from controls screen
            if (control_screen.handle_event(event)) {
                current_state = GameState::MENU;
            }
        }

        window.clear();
        control_screen.draw(window);
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

        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace){
            current_state = GameState::MENU;
        }
        if(event.type == sf::Event::Closed) window.close();
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
            current_state = GameState::PAUSE;

            save_game_data.set_level_number(current_level);
            save_game_data.set_player_position(player.get_player_position().x, player.get_player_position().y);
            save_game_data.set_player_health(player.get_player_health());
            save_game_data.set_sun_count(player.get_sun_count());

            save_manager::save_game(save_game_data, "Assets/Saves/save.txt");
        }
    }

        load_level(new_level);

        std::vector<Object*> level_data = level->get_level_vector();
        player.player_update(dt, level_data);
        window.clear();
        level->draw_background(window);
        level->custom_stats_display(window, font, player);
        // std::cout << "Health: " << player.get_player_health() << " | Sun: " << player.get_sun_count() << std::endl;

        for(int i = 0; i < level_data.size(); i++){
            window.draw(level_data[i]->get_object_hitbox());
        }
        window.draw(player.get_player_hitbox());
        window.display();
        }

    // End screen gamestate
    else if (current_state == GameState::END){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

            if (end_screen.handle_event(event)) {
            current_state = GameState::MENU;
            current_level = 0;
            }
        }

        window.clear();
        end_screen.draw(window);
        window.display();
    }

    // Pause gamestate
    else if (current_state == GameState::PAUSE){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();

            // Get mouse pos
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

                // Buttons
                if (pause_screen.is_resume_clicked(mouse_position)) current_state = GameState::PLAYING;
                if (pause_screen.is_quit_clicked(mouse_position)) current_state = GameState::MENU;
                }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) current_state = GameState::PLAYING;


        }

        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
        pause_screen.update(mouse_position);

        // Block of code to make the pause menu transparent so you can still see the level
        std::vector<Object*> level_data = level->get_level_vector();
        window.clear();
        level->draw_background(window);
        level->custom_stats_display(window, font, player);
        for(int i = 0; i < level_data.size(); i++){
            window.draw(level_data[i]->get_object_hitbox());
        }
        window.draw(player.get_player_hitbox());

        sf::RectangleShape transparent_overlay;
        transparent_overlay.setSize(sf::Vector2f(window_size.x, window_size.y));
        transparent_overlay.setFillColor(sf::Color(0, 0, 0, 150)); // RGBA - 150 alpha for ~50% opacity
        window.draw(transparent_overlay);

        // Pause window
        pause_screen.draw(window);  
        window.display();
    
    }


    /* Pause gamestate
    else if (current_state == GameState::PAUSE) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                pause_screen.update_hover(mouse_position);
            }

                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                    pause_screen.handle_event(event, mouse_position);

                    if (pause_screen.is_resume_clicked()) {
                        current_state = GameState::PLAYING;
                    }

                    if (pause_screen.is_quit_clicked()) {

                        // Save game
                        save_game_data.set_level_number(current_level);
                        save_game_data.set_player_position(player.get_player_position().x, player.get_player_position().y);
                        save_game_data.set_player_health(player.get_player_health());
                        save_game_data.set_sun_count(player.get_sun_count());

                        save_manager::save_game(save_game_data, "Assets/Saves/save.txt");

                        current_state = GameState::MENU;
                    }
}
            
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::P){
                current_state = GameState::PLAYING;
                }
        }

        // Draw window
        window.clear(sf::Color(0, 0, 0, 150));
        pause_screen.draw(window);
        window.display();
    }

    } 
    */
        // Update player, update window, etc.   
    }
}

// Game dt getter
    double Game::get_dt(){
        return dt;
    }

// Game destructor
    Game::~Game(){
        if (level) delete level;
        if (new_level) delete new_level;
    }