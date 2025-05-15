#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow& window){
    //Load background
    if (!menuTexture.loadFromFile("Textures/MenuTextures/menu.png")) {
        std::cerr << "Can't load texture";
    }
    menu.setTexture(menuTexture);

    //Scale background texture to fit window size
    sf::Vector2u textureSize = menuTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;
    menu.setScale(scaleX, scaleY);

    //Buttons
        //Check for textures
        if (!startTexture.loadFromFile("Textures/MenuTextures/startButton.png")) {
        std::cerr << "Can't load start texture";
        }
        if (!load_texture.loadFromFile("Textures/MenuTextures/load_button.png")) {
        std::cerr << "Can't load load texture";
        }
        if (!controls_texture.loadFromFile("Textures/MenuTextures/controls_button.png")) {
        std::cerr << "Can't load controls texture";
        }
        if (!exitTexture.loadFromFile("Textures/MenuTextures/quitButton.png")) {
        std::cerr << "Can't load quit texture";
        }
        
        //Textures
        start.setTexture(startTexture);
        exit.setTexture(exitTexture);
        load_sprite.setTexture(load_texture);
        controls_sprite.setTexture(controls_texture);

        //Button scaling (too large originally)
        const float button_scale = 0.6;
        start.setScale(button_scale, button_scale);
        exit.setScale(button_scale, button_scale);
        load_sprite.setScale(button_scale, button_scale);
        controls_sprite.setScale(button_scale, button_scale);

        start.setPosition(window.getSize().x / 2 - start.getGlobalBounds(). width / 2, window.getSize().y / 2 - start.getGlobalBounds().height - 200);
        load_sprite.setPosition(window.getSize().x / 2 - load_sprite.getGlobalBounds(). width / 2, window.getSize().y / 2 - load_sprite.getGlobalBounds().height - 50);
        controls_sprite.setPosition(window.getSize().x / 2 - controls_sprite.getGlobalBounds(). width / 2, window.getSize().y / 2 - controls_sprite.getGlobalBounds().height + 150);
        exit.setPosition(window.getSize().x / 2 - exit.getGlobalBounds(). width / 2, window.getSize().y / 2 - exit.getGlobalBounds().height + 300);


}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(menu);
    window.draw(start);
    window.draw(exit);
    window.draw(load_sprite);
    window.draw(controls_sprite);
}

void Menu::update(sf::Vector2i mousePosition) {
    auto hover_effect = [&](sf::Sprite& sprite) {
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            sprite.setScale(0.65f, 0.65f);
        } else {
            sprite.setScale(0.6f, 0.6f);
        }
    };

    hover_effect(start);
    hover_effect(exit);
    hover_effect(load_sprite);
    hover_effect(controls_sprite);

}

bool Menu::is_start_clicked(sf::Vector2i mousePosition) {
    return start.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

bool Menu::is_exit_clicked(sf::Vector2i mousePosition) {
    return exit.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

bool Menu::is_load_clicked(sf::Vector2i mousePosition) {
    return load_sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

bool Menu::is_controls_clicked(sf::Vector2i mousePosition) {
    return controls_sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}



