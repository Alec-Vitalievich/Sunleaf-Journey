#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H

#include <SFML/Graphics.hpp>

// Screen for informing the user they've lost the game.
class Game_Over_Screen
{
private:

    // Text 
    sf::Text game_over_text;
    sf::Text exposition_text;
    sf::Text continue_text;

public:

    // Constructor
    Game_Over_Screen(sf::Font &font, const sf::Vector2u window_size);

    // Constructor for drawing screen and handle event when key/mouse pressed
    void draw(sf::RenderWindow &window);
    bool handle_event(const sf::Event &event);
};

#endif