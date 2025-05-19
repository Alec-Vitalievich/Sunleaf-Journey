#ifndef ONE_WAY_PLATFORM_H
#define ONE_WAY_PLATFORM_H
#include "Src/Objects/Platform.h"

class One_Way_Platform : public Platform{
    protected:
    public:
        One_Way_Platform(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y);
        void vertical_collision_action(Player& player);
        void horizontal_collision_action(Player& player);
        ~One_Way_Platform();
};

#endif