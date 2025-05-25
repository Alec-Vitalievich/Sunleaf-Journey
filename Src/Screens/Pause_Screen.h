#ifndef PAUSE_SCREEN
#define PAUSE_SCREEN

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Pause_Screen
{
private:
    // Textures
    sf::Texture resume_texture;
    sf::Texture quit_texture;

    // Sprites
    sf::Sprite resume_sprite;
    sf::Sprite quit_sprite;

public:
    Pause_Screen(sf::RenderWindow &window);

    // Draw
    void draw(sf::RenderWindow &window);
    void update(sf::Vector2i mouse_position);

    // Checking if button has been clicked.
    bool is_resume_clicked(sf::Vector2i mouse_positiion);
    bool is_quit_clicked(sf::Vector2i mouse_positiion);
};

#endif