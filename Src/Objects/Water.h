#ifndef WATER_H
#define WATER_H
#include "Objects/Obstacle.h"

// Water class. Heals player when entered for the first time. Allows the player to swim but reduces movement speed.
class Water : public Obstacle
{
protected:

    // Check if water is touched
    bool touched_water;

public:

    // Water constructor
    Water(float Water_position_x, float Water_position_y, float Water_size_x, float Water_size_y, int health_modifier);

    // Collision constructors
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);
    void enscapsulated_collision_action(Player &player);

    // Destructor
    ~Water();
};

#endif