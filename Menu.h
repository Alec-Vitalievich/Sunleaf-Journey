#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Menu {
    public:
        Menu(sf::RenderWindow& window);

        void draw(sf::RenderWindow& window);
        void update(sf::Vector2i mousePosition);

        bool is_start_clicked(sf::Vector2i mousePosition);
        bool is_exit_clicked(sf::Vector2i mousePosition);
        bool is_load_clicked(sf::Vector2i mousePosition);
        bool is_controls_clicked(sf::Vector2i mousePosition);
        
    private:
        //Textures
        sf::Texture menuTexture;
        sf::Texture startTexture;
        sf::Texture exitTexture;
        sf::Texture load_texture;
        sf::Texture controls_texture;

        //Sprites
        sf::Sprite menu;
        sf::Sprite start;
        sf::Sprite exit;
        sf::Sprite load_sprite;
        sf::Sprite controls_sprite;

        //Title
        sf::Font font;
        sf::Text title_text;

};

#endif