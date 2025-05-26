#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Player; // Forward declaration so the compiler known the Player class exists.

// Base class (abstract, interface) for all drawable level objects (Obstacles, Collectables, etc)
class Object
{
protected:

    // Object hitbox 
    sf::RectangleShape object_hitbox;

public:

    // Object constructor
    Object(float object_position_x, float object_position_y, float object_size_x, float object_size_y);

    // Pure virtual functions for each derived class to implement individually.
    virtual void vertical_collision_action(Player &player) = 0;
    virtual void horizontal_collision_action(Player &player) = 0;
    virtual void enscapsulated_collision_action(Player &player) = 0;
    sf::RectangleShape &get_object_hitbox();

    // Getters and setters
    sf::Vector2f get_position() const;
    sf::Vector2f set_position() const;

    sf::Vector2f get_size() const;
    sf::Vector2f set_size() const;

    // Destructor
    virtual ~Object();
};

#endif