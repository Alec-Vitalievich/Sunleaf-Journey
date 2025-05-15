#include "Game.h"
#include "Menu.h"

// NOTE: Comments will be cleaned up, this is just for now so we can all understand what parts are doing what and why.

Game::Game(int window_size_x, int window_size_y, std::string window_name, int max_framerate, int current_level):window(sf::VideoMode(window_size_x, window_size_y), window_name),player(50,700,50,50,3,0){
    // Initialise variables.
    this->game_name = window_name;
    this->max_framerate = max_framerate;
    this->current_level = current_level;
    this->window_size = window.getSize();
    // Initialise clock cycle & player object. Set framerate limit (adjust per your machine).
    window.setFramerateLimit(max_framerate);
    clock.restart();
    // Start loading the first level. This may get weird with the menu and loading a previous save? 
    // My thought was we would have a set up function in main that came first and updated the first level number. 
    // Not sure how to make it work now. Call it after all the menu stuff I suppose? it needed to happen anyways.
    new_level = new bool;
    *new_level = true;
    load_level(new_level);
}

void Game::load_level(bool* new_level){
    if(*new_level == true){
        if(level){ // Checks if the pointer is not null. level != nullptr could be used for clarity?
            delete level;
            current_level++;
        }
        *new_level = false;
        level = new Level(current_level, new_level);
    }
}

void Game::update(){ // Main gameplay loop.

    Menu menu(window);

    while(window.isOpen()){

        if (current_state == GameState::MENU) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                window.close();

                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (menu.is_start_clicked(mousePos)) {
                        current_state = GameState::STORY;
                    }
                    if (menu.is_exit_clicked(mousePos)) {
                        window.close();
                    }
                }
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            menu.update(mousePos);

            window.clear();
            menu.draw(window);
            window.display();
        }

        else if (current_state == GameState::STORY) {
            sf::Event event;
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    current_state = GameState::PLAYING;
                }
            }

        window.clear();

        sf::Font font;
        font.loadFromFile("Fonts/antiquity-print.ttf");
        sf::Text story_text;
        story_text.setFont(font);
        story_text.setString("This game is fun");
        story_text.setCharacterSize(24);
        story_text.setFillColor(sf::Color::White);
        story_text.setPosition(100, 100);

        window.draw(story_text);
        window.display();

        }

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

double Game::get_dt(){
    return dt;
}

Game::~Game(){
    // Delete level perhaps?
}