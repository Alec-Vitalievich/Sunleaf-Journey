#include "Screens/Pause_Screen.h"
#include <iostream>

Pause_Screen::Pause_Screen(sf::RenderWindow &window)
{

    // Get window size to allow for texture scaling
    sf::Vector2u windowSize = window.getSize();

    // Buttons for pause screen
    // Button textures
    if (!resume_texture.loadFromFile("Assets/Textures/ScreenTextures/resumeButton.png"))
    {
        std::cerr << "Can't load resume button texture";
    }
    if (!quit_texture.loadFromFile("Assets/Textures/ScreenTextures/quitButton.png"))
    {
        std::cerr << "Can't load resume button texture";
    }

    // Set textures
    resume_sprite.setTexture(resume_texture);
    quit_sprite.setTexture(quit_texture);

    // Button scaling (too large without modification)
    const float button_scale = 0.4;
    resume_sprite.setScale(button_scale, button_scale);
    quit_sprite.setScale(button_scale, button_scale);

    // Center button function
    auto centre_origin = [](sf::Sprite &sprite)
    {
        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    };

    // Center the origin position of the buttons.
    centre_origin(resume_sprite);
    centre_origin(quit_sprite);

    float centreX = windowSize.x / 2.0;
    float centreY = windowSize.y / 2.0;
    float spacing = 100.0;

    // Set position of button based on centre position and spacing factor
    resume_sprite.setPosition(centreX, centreY - spacing * 1);
    quit_sprite.setPosition(centreX, centreY + spacing * 0.25);
}

void Pause_Screen::draw(sf::RenderWindow &window)
{
    // Draw buttons in GUI (window).
    window.draw(resume_sprite);
    window.draw(quit_sprite);
}

void Pause_Screen::update(sf::Vector2i mouse_position)
{
    // Hover effect to provide feedback to player
    auto hover_effect = [&](sf::Sprite &sprite)
    {
        // Check if the mouse position is within the bounds of the button
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_position)))
        {
            sprite.setScale(0.45, 0.45);
        }
        else
        {
            sprite.setScale(0.4, 0.4);
        }
    };

    // Apply effect when hovering over buttons
    hover_effect(resume_sprite);
    hover_effect(quit_sprite);
}

// Functions for checking if buttons are clicked
bool Pause_Screen::is_resume_clicked(sf::Vector2i mouse_position)
{
    return resume_sprite.getGlobalBounds().contains(sf::Vector2f(mouse_position));
}

bool Pause_Screen::is_quit_clicked(sf::Vector2i mouse_position)
{
    return quit_sprite.getGlobalBounds().contains(sf::Vector2f(mouse_position));
}
