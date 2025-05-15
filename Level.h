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

class Level{
    protected:
        std::vector<Object*> level_data;
        // bool* new_level = nullptr; maybe not neccessary

        //Textures
        sf::Texture background_texture1;
        sf::Sprite background_sprite1;
    public:
        Level(int level_number, bool* new_level);
        std::vector<Object*>& get_level_vector();
        void draw_background(sf::RenderWindow& window);
        ~Level();
};

#endif