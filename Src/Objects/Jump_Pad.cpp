#include "Src/Objects/Jump_Pad.h"
#include "Src/Main/Player.h"

Jump_Pad::Jump_Pad(float jump_pad_position_x, float jump_pad_position_y, float jump_pad_size_x, float jump_pad_size_y, int jump_modifier):
Object(jump_pad_position_x, jump_pad_position_y, jump_pad_size_x, jump_pad_size_y),jump_modifier(jump_modifier){
    object_hitbox.setFillColor(sf::Color::Green);
}

void Jump_Pad::vertical_collision_action(Player& player){}
void Jump_Pad::horizontal_collision_action(Player& player){}
void Jump_Pad::enscapsulated_collision_action(Player& player){
    player.set_jump_velocity(player.get_jump_velocity() * jump_modifier);
}
Jump_Pad::~Jump_Pad(){}