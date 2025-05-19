#include "Src/Collectables/Collectable.h"
#include "Src/Objects/Object.h"
#include "Src/Collectables/Sun.h"
#include "Src/Main/Player.h"


Sun::Sun(float Sun_pos_x, float Sun_pos_y, float Sun_size_x, float Sun_size_y)
: Collectable(Sun_pos_x,Sun_pos_y,Sun_size_x,Sun_size_y) {
   if (!sun_texture.loadFromFile("Assets/Textures/ObjectTextures/sun.png")){
    std::cout << "Failed to load sun texture!" << std::endl;
   }
   else{
        object_hitbox.setTexture(&sun_texture);
   }
}

void Sun::set_collectable_position(int x, int y){
    object_hitbox.setPosition(x, y);
}

void Sun::vertical_collision_action(Player &Player){

}

void Sun::horizontal_collision_action(Player &Player){

}

void Sun::enscapsulated_collision_action(Player& Player){
    object_hitbox.setPosition(2000, 2000);
    Player.set_sun_count(Player.get_sun_count() + 1);
}

Sun::~Sun(){
    // ...
}