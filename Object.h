#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Object{
    protected:
        sf::RectangleShape object;
    public:
        Object(float object_position_x, float object_position_y, float object_size_x, float object_size_y);
        virtual void collision_action() = 0;
        sf::RectangleShape& get_object_hitbox();
        ~Object();
};

#endif