#ifndef SPIKE_H
#define SPIKE_H
#include "Objects/Obstacle.h"

// Spike class. Acts as an obstacle for the player. Reduces health when collision is detected from the top.
class Spike : public Obstacle
{
protected:

    // Spike texture
    sf::Texture spike_texture;

public:

    // Spike constructor
    Spike(float spike_position_x, float spike_position_y, float spike_size_x, float spike_size_y, int health_modifier);

    // Collision constructors
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);
    void enscapsulated_collision_action(Player &player);

    // Destructor
    ~Spike();
};

#endif