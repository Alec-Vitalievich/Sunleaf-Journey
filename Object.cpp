#include "Object.h"

        Object::Object(float object_position_x, float object_position_y, float object_size_x, float object_size_y){
            object_hitbox.setPosition(object_position_x, object_position_y);
            object_hitbox.setSize({object_size_x, object_size_y}); // Takes a vector2f, or 2 position in {}.
        }
        sf::RectangleShape& Object::get_object_hitbox(){
            return object_hitbox;
        }
        Object::~Object(){
            // Nothin' to see here
        }