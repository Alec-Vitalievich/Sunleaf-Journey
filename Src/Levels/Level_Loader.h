#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include "Objects/Object.h"

class Level_Loader : public Object{
    protected:
        bool* new_level = nullptr;
        int* current_level = nullptr;
    public:
        Level_Loader(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y, bool* new_level, int* current_level);
        void vertical_collision_action(Player& player);
        void horizontal_collision_action(Player& player);
        void enscapsulated_collision_action(Player& player);
        ~Level_Loader();
};

#endif