#include "Screens/Pause_Screen.h"
#include <iostream>

Pause_Screen::Pause_Screen(sf::RenderWindow& window){

    sf::Vector2u windowSize = window.getSize();

    // Buttons
        // Button textures
        if (!resume_texture.loadFromFile("Assets/Textures/ScreenTextures/resumeButton.png")) {
            std::cerr << "Can't load resume button texture";
        }
        if (!quit_texture.loadFromFile("Assets/Textures/ScreenTextures/quitButton.png")) {
            std::cerr << "Can't load resume button texture";
        }

        // Set textures
        resume_sprite.setTexture(resume_texture);
        quit_sprite.setTexture(quit_texture);

        //Button scaling (too large originally)
        const float button_scale = 0.5;
        resume_sprite.setScale(button_scale, button_scale);
        quit_sprite.setScale(button_scale, button_scale);

        auto center_origin = [](sf::Sprite& sprite) {
            sf::FloatRect bounds = sprite.getLocalBounds();
            sprite.setOrigin(bounds.width / 2, bounds.height / 2);
        };

        center_origin(resume_sprite);
        center_origin(quit_sprite);

        float centerX = windowSize.x / 2.0;
        float centerY = windowSize.y / 2.0;

        const float spacing = 100.0;

        resume_sprite.setPosition(centerX, centerY - spacing * 1);
        quit_sprite.setPosition(centerX, centerY + spacing * 0.25);

}

void Pause_Screen::draw(sf::RenderWindow& window) {
    window.draw(resume_sprite);
    window.draw(quit_sprite);
}

void Pause_Screen::update(sf::Vector2i mouse_position) {
    auto hover_effect = [&](sf::Sprite& sprite) {
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_position))) {
            sprite.setScale(0.55, 0.55);
        } else {
            sprite.setScale(0.5, 0.5);
        }
    };

    hover_effect(resume_sprite);
    hover_effect(quit_sprite);
}

bool Pause_Screen::is_resume_clicked(sf::Vector2i mouse_position) {
    return resume_sprite.getGlobalBounds().contains(sf::Vector2f(mouse_position));
}

bool Pause_Screen::is_quit_clicked(sf::Vector2i mouse_position) {
    return quit_sprite.getGlobalBounds().contains(sf::Vector2f(mouse_position));
}
