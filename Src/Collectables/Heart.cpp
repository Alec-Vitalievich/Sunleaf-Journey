#include "Collectables/Heart.h"
#include "Collectables/Collectable.h"
#include "Objects/Object.h"
#include "Main/Player.h"

// Heart class constructor.
Heart::Heart(float Heart_pos_x, float Heart_pos_y, float Heart_size_x, float Heart_size_y)
    : Collectable(Heart_pos_x, Heart_pos_y, Heart_size_x, Heart_size_y)
{
    // Attempt to load & assign texture.
    if (!heart_texture.loadFromFile("Assets/Textures/ObjectTextures/heart.png"))
    {
        std::cout << "Failed to load heart texture!" << std::endl;
        object_hitbox.setFillColor(sf::Color::Red);
    }
    else
    {
        object_hitbox.setTexture(&heart_texture);
    }
}

// Implementation of virtual function to move the position of the collectable.
void Heart::set_collectable_position(int x, int y)
{
    object_hitbox.setPosition(x, y);
}

// Empty but initialised collision options.
void Heart::vertical_collision_action(Player &Player) {}

void Heart::horizontal_collision_action(Player &Player) {}

// Action taken when the player is within the boundary of the heart's hitbox.
void Heart::enscapsulated_collision_action(Player &Player)
{
    // Move out of window and increment health.
    object_hitbox.setPosition(2000, 2000);
    Player.set_player_health(Player.get_player_health() + 1);
}

Heart::~Heart()
{
    // ...
}