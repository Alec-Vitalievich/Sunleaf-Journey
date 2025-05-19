#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Player; // Forward declaration. Don't remove.

class Object{
    protected:
        sf::RectangleShape object_hitbox;
    public:
        Object(float object_position_x, float object_position_y, float object_size_x, float object_size_y);
        virtual void vertical_collision_action(Player& player) = 0;
        virtual void horizontal_collision_action(Player& player) = 0;
        virtual void enscapsulated_collision_action(Player& player) = 0;
        sf::RectangleShape& get_object_hitbox();
        virtual ~Object();
};

#endif