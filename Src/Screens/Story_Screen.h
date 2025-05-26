#ifndef STORY_SCREEN_H
#define STORY_SCREEN_H

#include <SFML/Graphics.hpp>

// Screen for displaying the game's story to the user.
class Story_Screen
{
private:

    // Text 
    sf::Text story_text;
    sf::Text continue_text;

public:

    // Constructor
    Story_Screen(sf::Font &font, const sf::Vector2u window_size);

    // Constructor for drawing screen and handle event when key/mouse pressed
    void draw(sf::RenderWindow &window);
    bool handle_event(const sf::Event &event);
};

#endif