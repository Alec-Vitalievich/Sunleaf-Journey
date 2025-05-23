#include "Collectables/Heart.h"
#include "Collectables/Collectable.h"
#include "Objects/Object.h"
#include "Main/Player.h"

Heart::Heart(float Heart_pos_x, float Heart_pos_y, float Heart_size_x, float Heart_size_y)
    : Collectable(Heart_pos_x, Heart_pos_y, Heart_size_x, Heart_size_y)
{
    if (!heart_texture.loadFromFile("Assets/Textures/ObjectTextures/heart.png"))
    {
        std::cout << "Failed to load heart texture!" << std::endl;
    }
    else
    {
        object_hitbox.setTexture(&heart_texture);
    }
}

void Heart::set_collectable_position(int x, int y)
{
    object_hitbox.setPosition(x, y);
}

void Heart::vertical_collision_action(Player &Player)
{
}

void Heart::horizontal_collision_action(Player &Player)
{
}

void Heart::enscapsulated_collision_action(Player &Player)
{
    object_hitbox.setPosition(2000, 2000);
    Player.set_player_health(Player.get_player_health() + 1);
}

Heart::~Heart()
{
    // ...
}