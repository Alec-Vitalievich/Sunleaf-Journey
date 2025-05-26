#ifndef JUMP_PAD
#define JUMP_PAD
#include "Objects/Object.h"

// Jump pad that allows players to jump significantly higher when in the hitbox.
class Jump_Pad : public Object
{
protected:

    // Jump modifier to boost players vertical jump
    int jump_modifier;
    sf::Texture jump_pad_texture;

public:

    // Jump pad constructor
    Jump_Pad(float jump_pad_position_x, float jump_pad_position_y, float jump_pad_size_x, float jump_pad_size_y, int jump_modifier);

    // Collision constructor
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);
    void enscapsulated_collision_action(Player &player);

    // Destructor
    ~Jump_Pad();
};

#endif