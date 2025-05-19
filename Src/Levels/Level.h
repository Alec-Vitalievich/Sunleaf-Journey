#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Src/Objects/Object.h"
#include "Src/Objects/Platform.h"
#include "Src/Levels/Level_Loader.h"
#include "Src/Objects/Spike.h"
#include "Src/Objects/Water.h"
#include "Src/Objects/Lava.h"
#include "Src/Objects/One_Way_Platform.h"
#include "Src/Objects/Jump_Pad.h"


#include "Src/Collectables/Collectable.h"
#include "Src/Collectables/Sun.h"
#include "Src/Collectables/Sun.h"

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