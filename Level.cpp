#include "Level.h"
#include "Game.h"
#include <iostream>

Level::Level(int level_number, bool* new_level){

    //Get window size
    sf::Vector2u windowSize = sf::Vector2u(1800, 1020); // Remember to change when window is scaled.

    //Level logic
    if(level_number > 3) level_number = 3; //Game only has 3 levels
    else if(level_number < 0) level_number = 0;

    //Switch for each level
    switch(level_number){
        case 1:

            current_level_number = level_number;

            //Load textures
            if (!background_texture1.loadFromFile("Assets/Textures/LevelTextures/cave.png")) {
                    std::cerr << "Failed to load textures!\n";
            } else {
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
                level_data.push_back(new Platform(1200, 200, 200, 20)); // Final platform
                level_data.push_back(new Level_Loader(1600, 0, 100, 100, new_level)); // End portal

                // Obstacles
                level_data.push_back(new Spike(550, 660, 100, 20, 1)); // Spike on a rightward platform
                level_data.push_back(new Water(650, 960, 100, 40, 2)); // Water hazard near bottom
                level_data.push_back(new Lava(750, 260, 100, 20, 2));  // Lava near the top
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

            current_level_number = level_number;
                
            // Load textures
            if (!background_texture2.loadFromFile("Assets/Textures/LevelTextures/forest.png")) {
                    std::cerr << "Failed to load textures!\n";
                } else {
                    background_sprite2.setTexture(background_texture2);

                //Get size
                sf::Vector2u textureSize = background_texture2.getSize();
                float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
                float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

                background_sprite2.setScale(scaleX, scaleY);
                }
                
            // Border to keep player falling out of bounds
            level_data.push_back(new Platform(0, -1, 1800, 1));
            level_data.push_back(new Platform(0, 1020, 1800, 1));
            level_data.push_back(new Platform(-1, 0, 1, 1020));
            level_data.push_back(new Platform(1800, 0, 1, 1020));
            break;

        case 3:

            current_level_number = level_number;

            //Check for texture
            if (!background_texture3.loadFromFile("Assets/Textures/LevelTextures/garden.png")) {
                    std::cerr << "Failed to load textures!\n";
                } else {
                    background_sprite3.setTexture(background_texture3);

                //Get size
                sf::Vector2u textureSize = background_texture3.getSize();
                float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
                float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

                background_sprite3.setScale(scaleX, scaleY);
                }
                

            // Border to keep player falling out of bounds
            level_data.push_back(new Platform(0, -1, 1800, 1));
            level_data.push_back(new Platform(0, 1020, 1800, 1));
            level_data.push_back(new Platform(-1, 0, 1, 1020));
            level_data.push_back(new Platform(1800, 0, 1, 1020));
            break;
    }
}

// Constructor to draw background
void Level::draw_background(sf::RenderWindow& window) {

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

std::vector<Object*>& Level::get_level_vector(){
    return level_data;
}

Level::~Level(){
    for(int i = 0; i < level_data.size(); i++){
        delete level_data[i];
    }
}