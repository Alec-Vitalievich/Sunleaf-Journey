#include "Levels/Level.h"
#include "Main/Game.h"
#include "Collectables/Heart.h"
#include <iostream>
#include <string>

Level::Level(int *level_number, bool *new_level)
{
    // Get window size
    sf::Vector2u windowSize = sf::Vector2u(1800, 1020); // Remember to change when window is scaled.

    // Level logic
    if (*level_number > 3)
        *level_number = 3; // Game only has 3 levels
    else if (*level_number < 0)
        *level_number = 0;

    // Load textures for custom display.
    if (!sun_display_texture.loadFromFile("Assets/Textures/ObjectTextures/sun.png"))
    {
        std::cout << "Failed to load sun texture (display function)!" << std::endl;
    }
    else
    {
        sun_display_sprite.setTexture(sun_display_texture);
        sun_display_sprite.setScale(2, 2);
    }

    if (!health_display_texture.loadFromFile("Assets/Textures/ObjectTextures/heart.png"))
    {
        std::cout << "Failed to load heart texture (display function)!" << std::endl;
    }
    else
    {
        health_display_sprite.setTexture(health_display_texture);
        health_display_sprite.setScale(2, 2);
    }

    // Switch for each level
    switch (*level_number)
    {
    case 1:

        current_level_number = *level_number;

        // Load textures
        if (!background_texture1.loadFromFile("Assets/Textures/LevelTextures/cave.png"))
        {
            std::cerr << "Failed to load textures!\n";
        }
        else
        {
            background_sprite1.setTexture(background_texture1);

            // Scale background texture to match window size
            sf::Vector2u textureSize = background_texture1.getSize();
            float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
            float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
            background_sprite1.setScale(scaleX, scaleY);
        }

        // Level entities
        // Base platform (start area)
        level_data.push_back(new Platform(30, 980, 300, 20)); // Start platform at bottom left

        // Zig-zag platforms
        level_data.push_back(new Platform(400, 880, 300, 20)); // Right
        level_data.push_back(new Platform(100, 780, 300, 20)); // Left
        level_data.push_back(new Platform(500, 680, 300, 20)); // Right
        level_data.push_back(new Platform(200, 580, 300, 20)); // Left
        level_data.push_back(new Platform(600, 480, 300, 20)); // Right
        level_data.push_back(new Platform(300, 380, 300, 20)); // Left
        level_data.push_back(new Platform(700, 280, 300, 20)); // Right
        level_data.push_back(new Platform(400, 180, 300, 20)); // Left

        // Final platform with portal at top-right
        level_data.push_back(new Platform(1200, 200, 200, 20));                               // Final platform
        level_data.push_back(new Level_Loader(1550, 100, 100, 100, new_level, level_number)); // End portal
        level_data.push_back(new Water(1550, 200, 100, 900, 2));                              // Water beneath portal (added by Isabella)

        // Obstacles
        level_data.push_back(new Spike(555, 660, 21, 20, 1));    // Spike on a rightward platform
        level_data.push_back(new Water(650, 960, 100, 40, 2));   // Water hazard near bottom
        level_data.push_back(new Lava(900, 260, 100, 20, 2));    // Lava near the top
        level_data.push_back(new Jump_Pad(330, 940, 80, 40, 2)); // Jump pad at start to help

        // One-way platform
        level_data.push_back(new One_Way_Platform(850, 180, 100, 20)); // Near final jump

        // Border to keep player falling out of bounds
        level_data.push_back(new Platform(0, -1, 1800, 1));
        level_data.push_back(new Platform(0, 1020, 1800, 1));
        level_data.push_back(new Platform(-1, 0, 1, 1020));
        level_data.push_back(new Platform(1800, 0, 1, 1020));

        // Testing new sun texture
        level_data.push_back(new Sun(550, 550, 20, 20));
        level_data.push_back(new Heart(500, 550, 20, 20));
        break;

    case 2:

        current_level_number = *level_number;

        // Load textures
        if (!background_texture2.loadFromFile("Assets/Textures/LevelTextures/forest.png"))
        {
            std::cerr << "Failed to load textures!\n";
        }
        else
        {
            background_sprite2.setTexture(background_texture2);

            // Get size
            sf::Vector2u textureSize = background_texture2.getSize();
            float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
            float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

            background_sprite2.setScale(scaleX, scaleY);
        }

        // Level  (consider moving to save file, can iterate through file using loop.)
        // Base platform (start area)
        level_data.push_back(new Platform(30, 980, 300, 20)); // Start platform at bottom left

        // Zig-zag platforms
        level_data.push_back(new Platform(400, 880, 300, 20)); // Right
        level_data.push_back(new Platform(100, 780, 300, 20)); // Left
        level_data.push_back(new Platform(500, 680, 300, 20)); // Right
        level_data.push_back(new Platform(200, 580, 300, 20)); // Left
        level_data.push_back(new Platform(600, 480, 300, 20)); // Right
        level_data.push_back(new Platform(300, 380, 300, 20)); // Left
        level_data.push_back(new Platform(700, 280, 300, 20)); // Right
        level_data.push_back(new Platform(400, 180, 300, 20)); // Left

        // Final platform with portal at top-right
        level_data.push_back(new Platform(1200, 200, 200, 20));                               // Final platform
        level_data.push_back(new Level_Loader(1550, 100, 100, 100, new_level, level_number)); // End portal
        level_data.push_back(new Water(1550, 200, 100, 900, 2));                              // Water beneath portal (added by Isabella)

        // Obstacles
        level_data.push_back(new Spike(555, 660, 100, 20, 1));   // Spike on a rightward platform
        level_data.push_back(new Water(850, 400, 100, 500, 2));  // Water hazard near bottom
        level_data.push_back(new Lava(900, 260, 100, 20, 2));    // Lava near the top
        level_data.push_back(new Jump_Pad(330, 940, 80, 40, 2)); // Jump pad at start to help

        // One-way platform
        level_data.push_back(new One_Way_Platform(850, 180, 100, 20)); // Near final jump

        // Border to keep player falling out of bounds
        level_data.push_back(new Platform(0, -1, 1800, 1));
        level_data.push_back(new Platform(0, 1020, 1800, 1));
        level_data.push_back(new Platform(-1, 0, 1, 1020));
        level_data.push_back(new Platform(1800, 0, 1, 1020));

        // Testing new sun texture
        level_data.push_back(new Sun(550, 550, 20, 20));
        level_data.push_back(new Heart(500, 550, 20, 20));
        break;

    case 3:

        current_level_number = *level_number;

        // Check for texture
        if (!background_texture3.loadFromFile("Assets/Textures/LevelTextures/garden.png"))
        {
            std::cerr << "Failed to load textures!\n";
        }
        else
        {
            background_sprite3.setTexture(background_texture3);

            // Get size
            sf::Vector2u textureSize = background_texture3.getSize();
            float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
            float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

            background_sprite3.setScale(scaleX, scaleY);
        }

        // Level entities
        // Base platform (start area)
        level_data.push_back(new Platform(30, 980, 300, 20)); // Start platform at bottom left

        // Zig-zag platforms
        level_data.push_back(new Platform(400, 880, 300, 20)); // Right
        level_data.push_back(new Platform(100, 780, 300, 20)); // Left
        level_data.push_back(new Platform(500, 680, 300, 20)); // Right
        level_data.push_back(new Platform(200, 580, 300, 20)); // Left
        level_data.push_back(new Platform(600, 480, 300, 20)); // Right
        level_data.push_back(new Platform(300, 380, 300, 20)); // Left
        level_data.push_back(new Platform(700, 280, 300, 20)); // Right
        level_data.push_back(new Platform(400, 180, 300, 20)); // Left

        // Final platform with portal at top-right
        level_data.push_back(new Platform(1200, 200, 200, 20));                               // Final platform
        level_data.push_back(new Level_Loader(1550, 100, 100, 100, new_level, level_number)); // End portal
        level_data.push_back(new Water(1550, 200, 100, 900, 2));                              // Water beneath portal (added by Isabella)

        // Obstacles
        level_data.push_back(new Spike(555, 660, 100, 20, 1));   // Spike on a rightward platform
        level_data.push_back(new Water(650, 960, 100, 40, 2));   // Water hazard near bottom
        level_data.push_back(new Lava(900, 260, 100, 20, 2));    // Lava near the top
        level_data.push_back(new Jump_Pad(330, 940, 80, 40, 2)); // Jump pad at start to help

        // One-way platform
        level_data.push_back(new One_Way_Platform(850, 180, 100, 20)); // Near final jump

        // Border to keep player falling out of bounds
        level_data.push_back(new Platform(0, -1, 1800, 1));
        level_data.push_back(new Platform(0, 1020, 1800, 1));
        level_data.push_back(new Platform(-1, 0, 1, 1020));
        level_data.push_back(new Platform(1800, 0, 1, 1020));

        // Testing new sun texture
        level_data.push_back(new Sun(550, 550, 20, 20));
        level_data.push_back(new Heart(500, 550, 20, 20));
        break;
    }
}

// Constructor to draw background
void Level::draw_background(sf::RenderWindow &window)
{

    // Switch case to draw background sprite depending on level
    switch (current_level_number)
    {
    case 1:
        window.draw(background_sprite1);
        break;

    case 2:
        window.draw(background_sprite2);
        break;

    case 3:
        window.draw(background_sprite3);
        break;

    default:
        break;
    }
    window.draw(background_sprite1);
}

void Level::custom_stats_display(sf::RenderWindow &window, sf::Font &font, Player &player)
{
    // Set position of the sprites (rectangles with textures).
    sun_display_sprite.setPosition(20, 20);
    health_display_sprite.setPosition(20, 80);

    // Set string & position of sun count.
    std::string sun_text_string = "#: " + std::to_string(player.get_sun_count());
    sf::Text sun_text(sun_text_string, font, 32);
    sun_text.setPosition(70, 20);

    // Set string & position of player health.
    std::string health_text_string = "#: " + std::to_string(player.get_player_health()) + "/3";
    sf::Text health_text(health_text_string, font, 32);
    health_text.setPosition(70, 80);

    // Draw sprites and text in the GUI (window).
    window.draw(sun_display_sprite);
    window.draw(health_display_sprite);
    window.draw(sun_text);
    window.draw(health_text);
}

// getter for vector containing all level objects.
std::vector<Object *> &Level::get_level_vector()
{
    return level_data;
}

Level::~Level()
{
    // Iterate through each element of the vector to release the memory.
    for (int i = 0; i < level_data.size(); i++)
    {
        delete level_data[i];
    }
}