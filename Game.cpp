#include "Game.h"


// NOTE: Comments will be cleaned up, this is just for now so we can all understand what parts are doing what and why.

Game::Game(int window_size_x, int window_size_y, std::string window_name, int max_framerate):window(sf::VideoMode(window_size_x, window_size_y), window_name),player(100,100,50,50){
    // Initialise variables.
    this->game_name = window_name;
    this->max_framerate = max_framerate;
    this->window_size = window.getSize();
    // Initialise clock cycle & player object. Set framerate limit (adjust per your machine).
    window.setFramerateLimit(max_framerate);
    clock.restart();
}
void Game::update(){ // Main gameplay loop.
    while(window.isOpen()){
        dt = clock.restart().asSeconds(); // Returns the time since restart was last called.
        if(dt > 0.5){ // Prevents delta time from becoming too large. (dt checks time since last frame - if the window was paused for instance, this could become huge otherwise).
            dt = 0.5; // We may want to play with this value a bit.
        }

        sf::Event event; // Could be moved to constructor, but it's essentially empty so initialising every loop isn't intensive. May improve readability? To be revisited.
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
                window.close();
            }
        }

        window.clear();
        window.draw(player.get_player_hitbox());
        window.display();
    }

    // Update player, update window, etc.
}

double Game::get_dt(){
    return dt;
}

Game::~Game(){
    // Nothin' to see here. We will need something with a pointer though, hm.
    // If collision is a virtual function of... whatever parent class is handling platforms & obstacles,
    // aggregate those using pointer to iterate through?? We still need dynamic memory allocation though.
}