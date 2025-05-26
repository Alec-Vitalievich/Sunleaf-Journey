#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include "Objects/Object.h"

// Drawn object in the window that the user uses to move to the next level (sort of similar to a portal).
class Level_Loader : public Object
{
protected:
    // Empty pointers to store the same address as the dynamically allocated variables in 'game'.
    bool *new_level = nullptr;
    int *current_level = nullptr;

    // Empty pointer to store the same address as the dynamically allocated variable in 'level'.
    bool *display_interactive_text = nullptr;

public:
    // Level loader constructor
    Level_Loader(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y, bool *new_level, bool *display_interactive_text, int *current_level);

    // Collision constructors
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);
    void enscapsulated_collision_action(Player &player);

    // Destructor
    ~Level_Loader();
};

#endif