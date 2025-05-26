#include "Objects/Object.h"

// Base constructor for all drawable level objects (abstract interface class).
Object::Object(float object_position_x, float object_position_y, float object_size_x, float object_size_y)
{
    object_hitbox.setPosition(object_position_x, object_position_y);
    object_hitbox.setSize({object_size_x, object_size_y});
}

// Function to return the object's hitbox (boundary coordinates) by reference.
sf::RectangleShape &Object::get_object_hitbox()
{
    return object_hitbox;
}

// Getters and setters
sf::Vector2f Object::get_position() const {
    return object_hitbox.getPosition();
}

sf::Vector2f Object::get_size() const {
    return object_hitbox.getSize();
}



Object::~Object() {}