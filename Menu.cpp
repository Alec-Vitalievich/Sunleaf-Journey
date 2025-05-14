#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow& window){
    //Load background
    if (!menuTexture.loadFromFile("Textures/MenuTextures/menu.png")) {
        std::cerr << "Can't load texture";
    }

    menu.setTexture(menuTexture);

    //Scale
    sf::Vector2u textureSize = menuTexture.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;

    menu.setScale(scaleX, scaleY);

    //Start button
    if (!startTexture.loadFromFile("Textures/MenuTextures/startButton.png")) {
        std::cerr << "Can't load texture";
    }

    start.setTexture(startTexture);
    start.setPosition(window.getSize().x / 2 - start.getGlobalBounds(). width / 2, window.getSize().y / 2 - start.getGlobalBounds().height - 20);


    //Exit button
    if (!exitTexture.loadFromFile("Textures/MenuTextures/quitButton.png")) {
        std::cerr << "Can't load texture";
    }

    exit.setTexture(exitTexture);
    exit.setPosition(window.getSize().x / 2 - start.getGlobalBounds(). width / 2, window.getSize().y / 2 + start.getGlobalBounds().height - 80);

}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(menu);
    window.draw(start);
    window.draw(exit);
}

bool Menu::is_start_clicked(sf::Vector2i mousePosition) {
    return start.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

bool Menu::is_exit_clicked(sf::Vector2i mousePosition) {
    return exit.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

