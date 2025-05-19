#ifndef PLATFORM_H
#define PLATFORM_H
#include "Objects/Object.h"
class Platform : public Object{
    protected:
    public:
    Platform(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y);
    void vertical_collision_action(Player& player);
    void horizontal_collision_action(Player& player);
    void enscapsulated_collision_action(Player& player);
    ~Platform();
};

#endif