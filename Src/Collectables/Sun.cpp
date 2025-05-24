#include "Collectables/Collectable.h"
#include "Objects/Object.h"
#include "Collectables/Sun.h"
#include "Main/Player.h"

// Sun class constructor
Sun::Sun(float Sun_pos_x, float Sun_pos_y, float Sun_size_x, float Sun_size_y)
    : Collectable(Sun_pos_x, Sun_pos_y, Sun_size_x, Sun_size_y)
{
    // Attempt to load & assign texture.
    if (!sun_texture.loadFromFile("Assets/Textures/ObjectTextures/sun.png"))
    {
        std::cout << "Failed to load sun texture!" << std::endl;
    }
    else
    {
        object_hitbox.setTexture(&sun_texture);
    }
}

// Implementation of virtual function to move the position of the collectable.
void Sun::set_collectable_position(int x, int y)
{
    object_hitbox.setPosition(x, y);
}

// Empty but initialised collision options.
void Sun::vertical_collision_action(Player &Player) {}

void Sun::horizontal_collision_action(Player &Player) {}

// Action taken when the player is within the boundary of the sun's hitbox.
void Sun::enscapsulated_collision_action(Player &Player)
{
    // Move out of window and increment sun count.
    object_hitbox.setPosition(2000, 2000);
    Player.set_sun_count(Player.get_sun_count() + 1);
}

Sun::~Sun()
{
    // ...
}