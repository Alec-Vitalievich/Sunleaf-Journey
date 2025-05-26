#include "Screens/Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow &window)
{
    // Load background textures 
    if (!menuTexture.loadFromFile("Assets/Textures/ScreenTextures/menu.png"))
    {
        std::cerr << "Can't load menu texture"; //Error message if texture can't load
    }
    menu.setTexture(menuTexture);

    // Scale background texture to fit window size.
    sf::Vector2u textureSize = menuTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;
    menu.setScale(scaleX, scaleY);

    // Buttons:
    // Check and load textures.
    if (!startTexture.loadFromFile("Assets/Textures/ScreenTextures/startButton.png"))
    {
        std::cerr << "Can't load start button texture"; //Error message if texture can't load
    }
    if (!load_texture.loadFromFile("Assets/Textures/ScreenTextures/load_button.png"))
    {
        std::cerr << "Can't load load button texture"; //Error message if texture can't load
    }
    if (!controls_texture.loadFromFile("Assets/Textures/ScreenTextures/controls_button.png"))
    {
        std::cerr << "Can't load controls button texture"; //Error message if texture can't load
    }
    if (!exitTexture.loadFromFile("Assets/Textures/ScreenTextures/quitButton.png"))
    {
        std::cerr << "Can't load quit button texture"; //Error message if texture can't load
    }

    // Set textures
    start.setTexture(startTexture);
    exit.setTexture(exitTexture);
    load_sprite.setTexture(load_texture);
    controls_sprite.setTexture(controls_texture);

    // Button scaling (too large without modification).
    const float button_scale = 0.5;
    start.setScale(button_scale, button_scale);
    exit.setScale(button_scale, button_scale);
    load_sprite.setScale(button_scale, button_scale);
    controls_sprite.setScale(button_scale, button_scale);

    // Center the origin position of the buttons.
    auto centre_origin = [](sf::Sprite &sprite)
    {
        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    };

    // Modify centre position.
    centre_origin(start);
    centre_origin(load_sprite);
    centre_origin(controls_sprite);
    centre_origin(exit);

    float centreX = windowSize.x / 2.0;
    float centreY = windowSize.y / 2.0;
    float spacing = 100.0;

    // Set position based on the centre position and the spacing factor.
    start.setPosition(centreX, centreY - spacing * 1);
    load_sprite.setPosition(centreX, centreY + spacing * 0.25);
    controls_sprite.setPosition(centreX, centreY + spacing * 1.75);
    exit.setPosition(centreX, centreY + spacing * 3);

    // Title screen
    // Load font
    if (!font.loadFromFile("Assets/Fonts/m6x11plus.ttf"))
    {
        std::cerr << "Error loading font";  //Error message if font can't load
    }

    // Set title text attributes and string
    title_text.setFont(font);
    title_text.setString("Sunleaf Journey: The Quest For The Sun");
    title_text.setCharacterSize(50);
    title_text.setFillColor(sf::Color::Black);
    title_text.setStyle(sf::Text::Bold);

    // Centre buttons
    sf::FloatRect text_bounds = title_text.getLocalBounds();
    title_text.setOrigin(text_bounds.width / 2, text_bounds.height / 2);
    title_text.setPosition(window.getSize().x / 2, 100);
}

void Menu::draw(sf::RenderWindow &window)
{
    // Draw all elements of the menu in the GUI (window).
    window.draw(menu);
    window.draw(title_text);
    window.draw(start);
    window.draw(exit);
    window.draw(load_sprite);
    window.draw(controls_sprite);
}

void Menu::update(sf::Vector2i mousePosition)
{
    // Hover effect to provide feedback 
    auto hover_effect = [&](sf::Sprite &sprite)
    {
        // Check if mouse position is within a given button.
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            sprite.setScale(0.55, 0.55);
        }
        else
        {
            sprite.setScale(0.5, 0.5);
        }
    };

    hover_effect(start);
    hover_effect(exit);
    hover_effect(load_sprite);
    hover_effect(controls_sprite);
}

// Button checking functions.
bool Menu::is_start_clicked(sf::Vector2i mousePosition)
{
    return start.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

bool Menu::is_exit_clicked(sf::Vector2i mousePosition)
{
    return exit.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

bool Menu::is_load_clicked(sf::Vector2i mousePosition)
{
    return load_sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

bool Menu::is_controls_clicked(sf::Vector2i mousePosition)
{
    return controls_sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}
