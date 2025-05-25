#ifndef END_SCREEN_H
#define END_SCREEN_H

#include <SFML/Graphics.hpp>

// Screen displayed to user when win condition is met (beating all three levels).
class End_Screen
{
private:
    sf::Text end_text;
    sf::Text return_text;

public:
    End_Screen(sf::Font &font, const sf::Vector2u window_size);

    void draw(sf::RenderWindow &window);
    bool handle_event(const sf::Event &event);
};

#endif