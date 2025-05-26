#ifndef SUN_H
#define SUN_H
#include "Collectables/Collectable.h"
#include "Objects/Object.h"

// Sun collectable. Acts as an additional goal for the player.
class Sun : public Collectable
{
protected:

    // Sun texture
    sf::Texture sun_texture;

public:

    // Sun constructor
    Sun(float Sun_pos_x, float Sun_pos_y, float Sun_size_x, float Sun_size_y);

    // Collision constructors
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);
    void enscapsulated_collision_action(Player &player);

    // Set sun position
    void set_collectable_position(int x, int y);

    // Destructor
    ~Sun();
};

#endif