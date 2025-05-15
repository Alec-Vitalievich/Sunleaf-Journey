#include "Level.h"
#include <iostream>

Level::Level(int level_number, bool* new_level){

    //Get window size
    sf::Vector2u windowSize = sf::Vector2u(1920, 1080); // Remember to change when window is scaled.

    //Load background textures
    //Check for texture
    if (!background_texture1.loadFromFile("Textures/LevelTextures/plains.png")) {
            std::cerr << "Failed to load textures!\n";
        } else {
            background_sprite1.setTexture(background_texture1);

        //Get size
        sf::Vector2u textureSize = background_texture1.getSize();
        float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
        float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

        background_sprite1.setScale(scaleX, scaleY);

    }

    //Level logic
    if(level_number > 3){
        level_number = 3;
    }
    else if(level_number < 0){
        level_number = 0;
    }
    switch(level_number){
        case 1:
            // level_data.push_back(new Platform(30, 750, 200, 20));
            // level_data.push_back(new Platform(30, 650, 200, 20));
            // level_data.push_back(new Platform(230, 650, 20, 120));
            // level_data.push_back(new Platform(10, 650, 20, 120));
            level_data.push_back(new Platform(30, 750, 800, 20));
            level_data.push_back(new Platform(230, 680, 20, 100));
            level_data.push_back(new Platform(10, 680, 20, 100));
            level_data.push_back(new Spike(1000,1060,100,20,1));
            level_data.push_back(new Water(1300,1060,100,20,2));
            level_data.push_back(new Lava(1600,1060,100,20,2));
            level_data.push_back(new One_Way_Platform(800,1000,100,20));
            level_data.push_back(new Jump_Pad(600,980,100,100,2));
            level_data.push_back(new Level_Loader(700,650,100,100,new_level));
            // Keep these. Add a border to the player can't fall out the window. Will need to be changed if the window changes size.
            level_data.push_back(new Platform(0, -1, 1920, 1));
            level_data.push_back(new Platform(0, 1080, 1920, 1));
            level_data.push_back(new Platform(-1, 0, 1, 1080));
            level_data.push_back(new Platform(1920, 0, 1, 1080));
            break;
        case 2:
            level_data.push_back(new Platform(0, -1, 1920, 1));
            level_data.push_back(new Platform(0, 1080, 1920, 1));
            level_data.push_back(new Platform(-1, 0, 1, 1080));
            level_data.push_back(new Platform(1920, 0, 1, 1080));
            break;
        case 3:

            level_data.push_back(new Platform(0, -1, 1920, 1));
            level_data.push_back(new Platform(0, 1080, 1920, 1));
            level_data.push_back(new Platform(-1, 0, 1, 1080));
            level_data.push_back(new Platform(1920, 0, 1, 1080));
            break;
    }
}

void Level::draw_background(sf::RenderWindow& window) {
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