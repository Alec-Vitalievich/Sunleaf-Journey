#include "Levels/Level.h"
#include "Main/Game.h"
#include "Collectables/Heart.h"
#include <iostream>
#include <string>

Level::Level(int *level_number, bool *new_level)
{

    // Dynamically allocate memory for level_loader bool.
    // (Checks if the player is in the level loader so it can call the on-screen text prompt)
    display_interactive_text = new bool(false);

    // Get window size
    sf::Vector2u windowSize = sf::Vector2u(1800, 1020);

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
        level_data.push_back(new Platform(550, 680, 300, 20)); // Right
        level_data.push_back(new Platform(200, 580, 300, 20)); // Left
        level_data.push_back(new Platform(650, 480, 300, 20)); // Right
        level_data.push_back(new Platform(300, 380, 300, 20)); // Left
        level_data.push_back(new Platform(700, 280, 300, 20)); // Right
        level_data.push_back(new Platform(400, 180, 300, 20)); // Left

        // Final platform with portal at top-right
        level_data.push_back(new Platform(1200, 200, 200, 20));                                                         // Final platform
        level_data.push_back(new Level_Loader(1550, 100, 100, 100, new_level, display_interactive_text, level_number)); // End portal
        level_data.push_back(new Platform(1450, 200, 300, 20));                                                        // Water beneath portal (added by Isabella)

        // Obstacles
        level_data.push_back(new Lava(900, 260, 100, 20, 2));    // Lava near the top
        level_data.push_back(new Jump_Pad(330, 940, 80, 40, 2)); // Jump pad at start to help

        // Collectables
        level_data.push_back(new One_Way_Platform(850, 180, 100, 20)); // Near final jump
        level_data.push_back(new Sun(70, 630, 35, 35)); // Sun 1
        level_data.push_back(new Sun(900, 130, 35, 35)); // Sun 2   
        level_data.push_back(new Heart(1350, 150, 35, 35)); // Heart above final platform

        // Border to keep player falling out of bounds
        level_data.push_back(new Platform(0, -1, 1800, 1));
        level_data.push_back(new Platform(0, 1020, 1800, 1));
        level_data.push_back(new Platform(-1, 0, 1, 1020));
        level_data.push_back(new Platform(1800, 0, 1, 1020));

        // Testing new sun texture
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
        level_data.push_back(new Platform(30, 980, 350, 20)); // Start platform at bottom left

        // Final platform with portal at top-right
        level_data.push_back(new One_Way_Platform(1200, 200, 200, 20));                                                         // Final platform
        level_data.push_back(new Level_Loader(1550, 100, 100, 100, new_level, display_interactive_text, level_number)); // End portal
        level_data.push_back(new Platform(1400, 200, 300, 20));                                                        // Water beneath portal (added by Isabella)

        // Part 1: water climb   
        level_data.push_back(new Water(330, 640, 80, 340, 2)); // Waterfall
        level_data.push_back(new Platform(240, 640, 20, 260)); // Platform left of waterfall
        level_data.push_back(new Platform(480, 640, 20, 260)); // Platform left of waterfall
        level_data.push_back(new Spike(260, 810, 70, 70, 1)); // left spike
        level_data.push_back(new Platform(240, 880, 90, 20)); //left spike underside
        level_data.push_back(new Spike(410, 810, 70, 70, 1)); // right spike
        level_data.push_back(new Platform(410, 880, 90, 20)); //right spike underside

        // Part 2 - lava jumps
        
        level_data.push_back(new Platform(480, 640, 300, 20));
        level_data.push_back(new Platform(780, 640, 300, 20));
        level_data.push_back(new Platform(1080, 640, 300, 20));
        level_data.push_back(new Lava(680, 620, 100, 20, 2));
        level_data.push_back(new Lava(920, 620, 100, 20, 2));
        level_data.push_back(new Lava(1160, 620, 100, 20, 2));

        level_data.push_back(new Platform(480, 360, 300, 20));
        level_data.push_back(new Platform(780, 360, 300, 20));

        level_data.push_back(new Jump_Pad(1280, 600, 80, 40,2));

        // Lava floors 
        level_data.push_back(new Lava(480, 1000, 300, 20, 2));
        level_data.push_back(new Lava(780, 1000, 300, 20, 2));
        level_data.push_back(new Lava(1080, 1000, 300, 20, 2));
        level_data.push_back(new Lava(1380, 1000, 300, 20, 3));
        level_data.push_back(new Lava(1680, 1000, 300, 20, 2));

        // Border to keep player falling out of bounds
        level_data.push_back(new Platform(0, -1, 1800, 1));
        level_data.push_back(new Platform(0, 1020, 1800, 1));
        level_data.push_back(new Platform(-1, 0, 1, 1020));
        level_data.push_back(new Platform(1800, 0, 1, 1020));

        // Collectables
        level_data.push_back(new Sun(800, 570, 35, 35));
        level_data.push_back(new Sun(1040, 570, 35, 35));
        level_data.push_back(new Heart(800, 310, 35, 35));
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

        // Part 1: Jump pad spike gap
        level_data.push_back(new Platform(610, 980, 300, 20));
        level_data.push_back(new Spike(330, 980, 70, 70, 1));
        level_data.push_back(new Spike(400, 980, 70, 70, 1));
        level_data.push_back(new Spike(470, 980, 70, 70, 1));
        level_data.push_back(new Spike(540, 980, 70, 70, 1));
        level_data.push_back(new Platform(700, 980, 300, 20));
        level_data.push_back(new Jump_Pad(250, 940, 80, 40, 2));

        level_data.push_back(new One_Way_Platform(100, 750, 200, 20));
        level_data.push_back(new Platform(610, 760, 200, 20));
        level_data.push_back(new Lava(100, 730, 100, 20, 2));
        level_data.push_back(new Lava(200, 730, 100, 20, 2));
        level_data.push_back(new Lava(710, 740, 100, 20, 2));
        level_data.push_back(new Platform(810, 500, 20, 260));

        //Lava under water columns
        level_data.push_back(new Lava(1000, 1000, 300, 20, 3));
        level_data.push_back(new Lava(1300, 1000, 300, 20, 3));
        level_data.push_back(new Lava(1600, 1000, 300, 20, 3));
        // Part 2: Water column catching
        level_data.push_back(new Water(1000, 450, 100, 350, 2));
        level_data.push_back(new Water(1210, 300, 100, 250, 2));
        level_data.push_back(new Water(1025, 200, 100, 100, 2));

        // Final platform with portal at top-right
        level_data.push_back(new Platform(1200, 200, 200, 20));
        level_data.push_back(new Platform(1400, 200, 300, 20));                                                           // Final platform
        level_data.push_back(new Level_Loader(1550, 100, 100, 100, new_level, display_interactive_text, level_number)); // End portal

        // Collectables
        level_data.push_back(new Sun(550, 550, 35, 35)); // Reachable by jump pad
        level_data.push_back(new Heart(630, 710, 35, 35)); // Upper Platform reachable by jump pad
        level_data.push_back(new Sun(1036, 310, 35, 35)); // Just under the third waterfall
        level_data.push_back(new Sun(1300, 150, 35, 35)); // Near the level loader

        // Border to keep player falling out of bounds
        level_data.push_back(new Platform(0, -1, 1800, 1));
        level_data.push_back(new Platform(0, 1020, 1800, 1));
        level_data.push_back(new Platform(-1, 0, 1, 1020));
        level_data.push_back(new Platform(1800, 0, 1, 1020));

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
    sf::Text sun_text(sun_text_string, font, 38);
    sun_text.setPosition(70, 20);

    // Set string & position of player health.
    std::string health_text_string = "#: " + std::to_string(player.get_player_health()) + "/3";
    sf::Text health_text(health_text_string, font, 38);
    health_text.setPosition(70, 80);

    // Draw sprites and text in the GUI (window).
    window.draw(sun_display_sprite);
    window.draw(health_display_sprite);
    window.draw(sun_text);
    window.draw(health_text);
}

// Function to write text in the GUI to prompt player to move to next level when in the level_loader hitbox.
void Level::draw_interactive_text(sf::RenderWindow &window, sf::Font &font)
{
    // Create text element.
    sf::Text interaction_text;
    interaction_text.setFont(font);
    interaction_text.setCharacterSize(50);
    interaction_text.setFillColor(sf::Color::White);
    interaction_text.setPosition(600, 50);

    // Check if the player is within the level_loader's hitbox.
    if (*display_interactive_text == true)
    {
        // Set text string and draw the text to the window.
        interaction_text.setString("Press E to continue to next level!");
        window.draw(interaction_text);
        *display_interactive_text = false;
    }
}

// getter for vector containing all level objects.
std::vector<Object *> &Level::get_level_vector()
{
    return level_data;
}

int Level::get_current_level()
{
    return current_level_number;
}

void Level::set_current_level(int level)
{
    current_level_number = level;
}

Level::~Level()
{
    // Iterate through each element of the vector to release the memory.
    for (int i = 0; i < level_data.size(); i++)
    {
        delete level_data[i];
    }

    if (display_interactive_text)
    {
        delete display_interactive_text;
    }
}