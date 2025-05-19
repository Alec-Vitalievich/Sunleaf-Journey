#ifndef LAVA_H
#define LAVA_H
#include "Src/Objects/Obstacle.h"

class Lava : public Obstacle{
    protected:
    public:
        Lava(float Lava_position_x, float Lava_position_y, float Lava_size_x, float Lava_size_y, int health_modifier);
        void vertical_collision_action(Player& player);
        void horizontal_collision_action(Player& player);
        void enscapsulated_collision_action(Player& player);
        ~Lava();
};

#endif