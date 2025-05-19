#ifndef SUN_H
#define SUN_H
#include "Src/Collectables/Collectable.h"
#include "Src/Objects/Object.h"

class Sun: public Collectable{
    protected:
        sf::Texture sun_texture;
    public:
        Sun(float Sun_pos_x, float Sun_pos_y, float Sun_size_x, float Sun_size_y);
        void vertical_collision_action(Player& player);
        void horizontal_collision_action(Player& player);
        void enscapsulated_collision_action(Player& player);
        void set_collectable_position(int x, int y);
        ~Sun();
        
};


#endif