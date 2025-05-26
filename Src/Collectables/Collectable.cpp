#include "Objects/Object.h"
#include "Collectables/Collectable.h"

// Constructor for collectable class.
Collectable::Collectable(float collectable_pos_x, float collectable_pos_y, float collectable_size_x, float collectable_size_y)
    : Object(collectable_pos_x, collectable_pos_y, collectable_size_x, collectable_size_y) {}

// Getters and setters
sf::Vector2f Collectable::get_position() const {
    return object_hitbox.getPosition();
}

sf::Vector2f Collectable::get_size() const {
    return object_hitbox.getSize();
}