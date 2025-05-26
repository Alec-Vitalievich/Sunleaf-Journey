#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Objects/Object.h"

// Base (abstract) class for all drawable obstacles.
class Obstacle : public Object
{
protected:

    // Health modifier to reduce player health
    int health_modifier;

public:

    // Obstacle constructor
    Obstacle(float Obstacle_position_x, float Obstacle_position_y, float Obstacle_size_x, float Obstacle_size_y, int health_modifer);

    // Destructor
    ~Obstacle();
};

#endif