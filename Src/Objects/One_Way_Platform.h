#ifndef ONE_WAY_PLATFORM_H
#define ONE_WAY_PLATFORM_H
#include "Objects/Platform.h"

// Uni-directional platform (Collision only detected from the top).
class One_Way_Platform : public Platform
{
protected:
public:

    // One way platform constructor
    One_Way_Platform(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y);

    // Collision constructors
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);

    // Destructor
    ~One_Way_Platform();
};

#endif