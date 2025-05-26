#include "Screens/Story_Screen.h"

Story_Screen::Story_Screen(sf::Font &font, sf::Vector2u window_size)
{
    // Set story text attributes and set story
    story_text.setFont(font);
    story_text.setString("Buried in the darkness below,\n"
                         "a small seedling sprouts,\n"
                         "unfurling its leaves in a strange new world.\n\n"

                         "You don't know how you got here,\n"
                         "but you sense something is missing.\n"
                         "Whilst the soil is lush with nutrients\n"
                         "and water abounds, there's little light\n"
                         "to be found. How will you grow without the sun?\n\n"

                         "You must begin your journey to find the light\n"
                         "and find a home a place to set down roots.\n"
                         "Collect little slices of sun whilst traversing\n"
                         "through a whole new world from dim caves full\n"
                         "of dangerous obstacles to forests full of\n"
                         "dappled light and shadow to reach your perfect\n"
                         "patch of sun. But beware, it's a dangerous world\n"
                         "out there for a small Sunleaf.\n"
                         "\n");
    story_text.setCharacterSize(38);
    story_text.setFillColor(sf::Color::White);
    story_text.setPosition(100, 65);

    // Set continue text attributes and explain how to contine or return to menu.
    continue_text.setFont(font);
    continue_text.setString("...Press ENTER to continue, ...BACKSPACE to return to main menu");
    continue_text.setCharacterSize(38);
    continue_text.setFillColor(sf::Color::Yellow);
    float continue_text_x = 100;
    float continue_text_y = window_size.y - 100;
    continue_text.setPosition(continue_text_x, continue_text_y);
}

void Story_Screen::draw(sf::RenderWindow &window)
{
    // Draw text elements to GUI (window).
    window.draw(story_text);
    window.draw(continue_text);
}

bool Story_Screen::handle_event(const sf::Event &event)
{
    // Return true if the correct event has occured (Enter key pressed)
    return (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter);
}