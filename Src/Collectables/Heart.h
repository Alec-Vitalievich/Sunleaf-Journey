#ifndef HEART_H
#define HEART_H
#include "Collectables/Collectable.h"
#include "Objects/Object.h"

// Heart collectable. Allows player to regain one health upon collection.
class Heart : public Collectable
{
protected:
    sf::Texture heart_texture;

public:
    Heart(float Heart_pos_x, float Heart_pos_y, float Heart_size_x, float Heart_size_y);
    void vertical_collision_action(Player &player);
    void horizontal_collision_action(Player &player);
    void enscapsulated_collision_action(Player &player);
    void set_collectable_position(int x, int y);
    ~Heart();
};

#endif