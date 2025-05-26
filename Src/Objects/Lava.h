#ifndef LAVA_H
#define LAVA_H
#include "Objects/Obstacle.h"

// Lava is a drawn object that acts as an obstacle for the player.
class Lava : public Obstacle
{
protected:
public:

    // Lava constructor
    Lava(float Lava_position_x, float Lava_position_y, float Lava_size_x, float Lava_size_y, int health_modifier);

    // Constructors for collision
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);
    void enscapsulated_collision_action(Player &player);

    // Destructor
    ~Lava();
};

#endif