#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Objects/Object.h"
#include "Objects/Platform.h"
#include "Levels/Level_Loader.h"
#include "Objects/Spike.h"
#include "Objects/Water.h"
#include "Objects/Lava.h"
#include "Objects/One_Way_Platform.h"
#include "Objects/Jump_Pad.h"

#include "Collectables/Collectable.h"
#include "Collectables/Sun.h"
#include "Collectables/Sun.h"

#include "Main/Player.h"

// Class to create & manage each level.
class Level
{
protected:
    // Vector to store all objects in the level.
    std::vector<Object *> level_data;

    // Textures for levels
    sf::Texture background_texture1;
    sf::Sprite background_sprite1;
    sf::Texture background_texture2;
    sf::Sprite background_sprite2;
    sf::Texture background_texture3;
    sf::Sprite background_sprite3;

    // Textures for custom display.
    sf::Texture sun_display_texture;
    sf::Sprite sun_display_sprite;
    sf::Texture health_display_texture;
    sf::Sprite health_display_sprite;

    int current_level_number;

public:
    Level(int *level_number, bool *new_level);
    std::vector<Object *> &get_level_vector();
    void draw_background(sf::RenderWindow &window);
    void custom_stats_display(sf::RenderWindow &window, sf::Font &font, Player &player);
    ~Level();
};

#endif