#ifndef SPIKE_H
#define SPIKE_H
#include "Objects/Obstacle.h"

class Spike : public Obstacle{
    protected:
    public:
        Spike(float spike_position_x, float spike_position_y, float spike_size_x, float spike_size_y, int health_modifier);
        void vertical_collision_action(Player& player);
        void horizontal_collision_action(Player& player);
        void enscapsulated_collision_action(Player& player);
        ~Spike();
};

#endif