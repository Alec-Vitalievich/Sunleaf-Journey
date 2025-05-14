#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Menu {
    public:
        Menu(sf::RenderWindow& window);

        void draw(sf::RenderWindow& window);

        bool is_start_clicked(sf::Vector2i mousePosition);

        bool is_exit_clicked(sf::Vector2i mousePosition);
        
    private:
        //Textures
        sf::Texture menuTexture;
        sf::Texture startTexture;
        sf::Texture exitTexture;

        //Sprites
        sf::Sprite menu;
        sf::Sprite start;
        sf::Sprite exit;

};

#endif