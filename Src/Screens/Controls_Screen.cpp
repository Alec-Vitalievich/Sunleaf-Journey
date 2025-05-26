#include "Screens/Controls_Screen.h"

Controls_Screen::Controls_Screen(sf::Font &font, sf::Vector2u window_size)
{
    // Setting controls text attributes and string explaining the mechanics of the game.
    controls_text.setFont(font);
    controls_text.setString("CONTROLS:\n"
                            " - A: Move Left\n"
                            " - D: Move Right\n"
                            " - Space: Jump\n"
                            " - E Interact (Next level portal)\n"
                            " - R: Manual game reset\n"
                            " - Esc: Pause\n"
                            "\n"
                            "ENVIRONMENT FUNCTIONS:\n"
                            "Hazards:\n"
                            " - Lava (red): Hazard that damages you heavily\n"
                            " - Spike: Hazard that damages you\n"
                            "\n"
                            "Objects:\n"
                            " - Next level portal (light purple): Transports player to next level\n"
                            " - Water (blue): Heals the player the first time. Allows you to swim but slows you down\n"
                            " - Jump Pad (green): Boosts the player's vertical jump\n"
                            " - Platform (brown): Regular platform with collision on all sides."
                            " - One Way Platform (beige): Platform that allows for the player to jump through the bottom\n"
                            "\n"
                            "Collectables:\n"
                            " - Heart: Increase player health by one\n"
                            " - Sun: Score for the playery\n");
    controls_text.setCharacterSize(38);
    controls_text.setFillColor(sf::Color::White);
    controls_text.setPosition(100, 65);

    // Setting return text attributes and string for how to return to menu.
    return_text.setFont(font);
    return_text.setString("...Press ENTER to return to main menu");
    return_text.setCharacterSize(38);
    return_text.setFillColor(sf::Color::Yellow);
    float return_text_x = 100;
    float return_text_y = window_size.y - 100;
    return_text.setPosition(return_text_x, return_text_y);
}

void Controls_Screen::draw(sf::RenderWindow &window)
{
    // Draw information in the GUI (window).
    window.draw(controls_text);
    window.draw(return_text);
}

bool Controls_Screen::handle_event(const sf::Event &event)
{
    // Return true if the correct event has occured (pressing Enter key).
    return (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter);
}