#ifndef CONTROLS_SCREEN_H
#define CONTROLS_SCREEN_H

#include <SFML/Graphics.hpp>

class Controls_Screen {
    private:
        sf::Text controls_text;
        sf::Text return_text;

    public:
        Controls_Screen(sf::Font& font, const sf::Vector2u window_size);
        
        void draw(sf::RenderWindow& window);
        bool handle_event(const sf::Event& event);
};

#endif