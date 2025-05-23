#ifndef STORY_SCREEN_H
#define STORY_SCREEN_H

#include <SFML/Graphics.hpp>

class Story_Screen
{
private:
    sf::Text story_text;
    sf::Text continue_text;

public:
    Story_Screen(sf::Font &font, const sf::Vector2u window_size);

    void draw(sf::RenderWindow &window);
    bool handle_event(const sf::Event &event);
};

#endif