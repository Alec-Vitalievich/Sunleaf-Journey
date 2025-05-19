#ifndef JUMP_PAD
#define JUMP_PAD
#include "Objects/Object.h"

class Jump_Pad : public Object{
    protected:
        int jump_modifier;
    public:
        Jump_Pad(float jump_pad_position_x, float jump_pad_position_y, float jump_pad_size_x, float jump_pad_size_y, int jump_modifier);
        void vertical_collision_action(Player& player);
        void horizontal_collision_action(Player& player);
        void enscapsulated_collision_action(Player& player);
        ~Jump_Pad();
};

#endif