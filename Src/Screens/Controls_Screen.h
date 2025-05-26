#ifndef CONTROLS_SCREEN_H
#define CONTROLS_SCREEN_H

#include <SFML/Graphics.hpp>

// Screen for displaying information on game mechanics.
class Controls_Screen
{
private:

    // Controls screen text
    sf::Text controls_text;
    sf::Text return_text;

public:

    // Constrols screen constructor
    Controls_Screen(sf::Font &font, const sf::Vector2u window_size);

    // Drawing and handling event constructors
    void draw(sf::RenderWindow &window);
    bool handle_event(const sf::Event &event);
};

#endif