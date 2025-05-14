#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Platform.h"
class Level{
    protected:
        std::vector<Object*> level_data;

        //Textures
        sf::Texture background_texture1;
        sf::Sprite background_sprite1;
    public:
        Level(int level_number);
        std::vector<Object*>& get_level_vector();
        void draw_background(sf::RenderWindow& window);
        ~Level();
};

#endif