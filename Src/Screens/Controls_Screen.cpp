#include "Screens/Controls_Screen.h"

Controls_Screen::Controls_Screen(sf::Font& font, sf::Vector2u window_size) {
    controls_text.setFont(font);
    controls_text.setString("CONTROLS:\n"
                            "\n"
                            " - W: Move Up\n"
                            " - A: Move Left\n"
                            " - S: Move Down\n"
                            " - D: Move Right\n"
                            " - E Interact (Next level portal)\n"
                            " - Esc: Pause\n"
                            "\n"
                            "OBJECT FUNCTIIONS:\n"
                            "Hazards:\n"
                            " - Lava: Hazard that kills you\n"
                            " - Spike: Hazard that kills you\n"
                            "\n"
                            "Objects:\n"
                            " - Water: Heals the player but slows you down\n"
                            " - Jump Pad: Boosts the players vertical jump\n"
                            " - One Way Platform: Platform that only allows for vertical passthrough\n"
                            "\n"
                            "Collectables:\n"
                            " - Heart: Health for the player\n"
                            " - Sun: Score for the playery\n");
    controls_text.setCharacterSize(24);
    controls_text.setFillColor(sf::Color::White);
    controls_text.setPosition(100, 65);

    return_text.setFont(font);
    return_text.setString("...Press ENTER to return to main menu");
    return_text.setCharacterSize(24);
    return_text.setFillColor(sf::Color::Yellow);
    float return_text_x = 100;
    float return_text_y = window_size.y - 100;
    return_text.setPosition(return_text_x, return_text_y);

}

void Controls_Screen::draw(sf::RenderWindow& window) {
    window.draw(controls_text);
    window.draw(return_text);
}

bool Controls_Screen::handle_event(const sf::Event& event) {
    return (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter);
}