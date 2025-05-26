#ifndef COLLECT_H
#define COLLECT_H
#include "Objects/Object.h"

// Base (abstract) class for objects the player can pick up (like health containers or sun.)
class Collectable : public Object
{
protected:
public:

    // Collectable constructor
    Collectable(float collectable_pos_x, float collectable_pos_y, float collectable_size_x, float collectable_size_y);
    
    // Pure virtual function to move the collectable out of the window once interacted with.
    virtual void set_collectable_position(int x, int y) = 0;
};

#endif