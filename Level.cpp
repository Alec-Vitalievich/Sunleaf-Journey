#include "Level.h"
#include <iostream>

Level::Level(int level_number){

    //Get window size
    sf::Vector2u windowSize = sf::Vector2u(1000, 800);

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
            level_data.push_back(new Platform(30, 750, 200, 20));
            level_data.push_back(new Platform(30, 650, 200, 20));
            level_data.push_back(new Platform(230, 650, 20, 120));
            level_data.push_back(new Platform(10, 650, 20, 120));
            break;
        case 2:
            break;
        case 3:
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