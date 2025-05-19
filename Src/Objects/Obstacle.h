#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Src/Objects/Object.h"

class Obstacle : public Object{
    protected:
        int health_modifier;
    public:
    Obstacle(float Obstacle_position_x, float Obstacle_position_y, float Obstacle_size_x, float Obstacle_size_y, int health_modifer);
    ~Obstacle();
};

#endif