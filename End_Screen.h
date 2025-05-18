#ifndef END_SCREEN_H
#define END_SCREEN_H

#include <SFML/Graphics.hpp>

class end_screen{
    private:
        sf::Text end_text;
        sf::Text return_text;

    public:
        end_screen(sf::Font& font, const sf::Vector2u window_size);

        void draw(sf::RenderWindow& window);
        bool handle_event(const sf::Event& event);

};

#endif