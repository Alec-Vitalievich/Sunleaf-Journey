#ifndef END_SCREEN_H
#define END_SCREEN_H

#include <SFML/Graphics.hpp>

// Screen displayed to user when win condition is met (beating all three levels).
class End_Screen
{
private:

    // End screen text
    sf::Text end_text;
    sf::Text return_text;

public:

    // End screen constructor
    End_Screen(sf::Font &font, const sf::Vector2u window_size);

    // Drawing and handling event constructors
    void draw(sf::RenderWindow &window);
    bool handle_event(const sf::Event &event);
};

#endif