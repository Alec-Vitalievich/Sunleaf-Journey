#include "Screens/End_Screen.h"

End_Screen::End_Screen(sf::Font &font, sf::Vector2u window_size)
{
    // Setting end screen (win screen) text attributes and string.
    end_text.setFont(font);
    end_text.setString("The young sunleaf finds the sun,\n"
                       "from a young seedling to full sprout,\n"
                       "you have completed your journey.\n");
    end_text.setCharacterSize(24);
    end_text.setFillColor(sf::Color::White);
    end_text.setPosition(100, 65);

    // Setting return text attributes and string explaining how to return to menu.
    return_text.setFont(font);
    return_text.setString("...Press Enter to return the the main menu");
    return_text.setCharacterSize(24);
    return_text.setFillColor(sf::Color::Yellow);
    float return_text_x = 100;
    float return_text_y = window_size.y - 100;
    return_text.setPosition(return_text_x, return_text_y);
}

void End_Screen::draw(sf::RenderWindow &window)
{
    // Drawing screen & text in GUI (window).
    window.draw(end_text);
    window.draw(return_text);
}

bool End_Screen::handle_event(const sf::Event &event)
{
    // Return true if the correct event has occured (pressing Enter key).
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
    {
        return true;
    }
    else
    {
        return false;
    }
}