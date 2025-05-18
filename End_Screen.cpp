#include "End_Screen.h"

end_screen::end_screen(sf::Font& font, sf::Vector2u window_size) {
    end_text.setFont(font);
    end_text.setString("The young sunleaf finds the sun,\n"
                            "from a young seedling to full sprout,\n"
                            "you have completed your journey.\n");
    end_text.setCharacterSize(24);
    end_text.setFillColor(sf::Color::White);
    end_text.setPosition(100, 65);

    return_text.setFont(font);
    return_text.setString("...Press Enter to return the the main menu");
    return_text.setCharacterSize(24);
    return_text.setFillColor(sf::Color::Yellow);
    float return_text_x = 100;
    float return_text_y = window_size.y - 100;
    return_text.setPosition(return_text_x, return_text_y);
}

void end_screen::draw(sf::RenderWindow& window) {
    window.draw(end_text);
    window.draw(return_text);
}

bool end_screen::handle_event(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
        return true;
    } else {
        return false;
    }
}