#include "Screens/Game_Over_Screen.h"

Game_Over_Screen::Game_Over_Screen(sf::Font &font, sf::Vector2u window_size)
{
    // Set Game_Over text attributes and set Game_Over
    game_over_text.setFont(font);
    game_over_text.setString("GAME OVER\n");
    game_over_text.setCharacterSize(200);
    game_over_text.setFillColor(sf::Color::White);
    game_over_text.setPosition(550, 200);

    exposition_text.setFont(font);
    exposition_text.setString("You may have fallen, but your journey must not end here...\n");
    exposition_text.setCharacterSize(38);
    exposition_text.setFillColor(sf::Color::White);
    exposition_text.setPosition(500, 500);

    // Set continue text attributes and explain how to contine or return to menu.
    continue_text.setFont(font);
    continue_text.setString("...Press ENTER to restart game...");
    continue_text.setCharacterSize(38);
    continue_text.setFillColor(sf::Color::Yellow);
    continue_text.setPosition(700, 800);
}

void Game_Over_Screen::draw(sf::RenderWindow &window)
{
    // Draw text elements to GUI (window).
    window.draw(game_over_text);
    window.draw(exposition_text);
    window.draw(continue_text);
}

bool Game_Over_Screen::handle_event(const sf::Event &event)
{
    // Return true if the correct event has occured (Enter key pressed)
    return (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter);
}