#ifndef STORY_SCREEN_H
#define STORY_SCREEN_H

#include <SFML/Graphics.hpp>

class story_screen {
    private:
        sf::Text story_text;
        sf::Text continue_text;

    public:
        story_screen(sf::Font& font, const sf::Vector2u window_size);
        
        void draw(sf::RenderWindow& window);
        bool handle_event(const sf::Event& event);
};

#endif