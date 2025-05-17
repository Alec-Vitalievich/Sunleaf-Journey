#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Platform.h"
#include "Level_Loader.h"
#include "Spike.h"
#include "Water.h"
#include "Lava.h"
#include "One_Way_Platform.h"
#include "Jump_Pad.h"

class Level{
    protected:
        std::vector<Object*> level_data;
        // bool* new_level = nullptr; maybe not neccessary

        //Textures for levels
        sf::Texture background_texture1;
        sf::Sprite background_sprite1;
        sf::Texture background_texture2;
        sf::Sprite background_sprite2;
        sf::Texture background_texture3;
        sf::Sprite background_sprite3;

        int current_level_number;
        
    public:
        Level(int level_number, bool* new_level);
        std::vector<Object*>& get_level_vector();
        void draw_background(sf::RenderWindow& window);
        ~Level();
};

#endif