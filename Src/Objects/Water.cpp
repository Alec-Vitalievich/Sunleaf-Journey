#include "Objects/Water.h"
#include "Main/Player.h"

// TODO: comments
Water::Water(float Water_position_x, float Water_position_y, float Water_size_x, float Water_size_y, int health_modifer):
Obstacle(Water_position_x, Water_position_y,Water_size_x, Water_size_y, health_modifer){
    object_hitbox.setFillColor(sf::Color(0,100,255)); // Will be replaced by texture
    touched_water = false;
}

void Water::vertical_collision_action(Player& player){
    if(touched_water == false){
        player.set_player_health(player.get_player_health() + health_modifier);
        touched_water = true;
    }
    player.set_player_acceleration_x(player.get_player_acceleration_x()/3);
    player.set_player_acceleration_y(player.get_player_acceleration_y()/5);
    player.set_jump_velocity(player.get_jump_velocity()/3);
    player.set_on_platform(true);
}

void Water::horizontal_collision_action(Player& player){
    if(touched_water == false){
        player.set_player_health(player.get_player_health() + health_modifier);
        touched_water = true;
    }
    player.set_player_acceleration_x(player.get_player_acceleration_x()/3);
    player.set_player_acceleration_y(player.get_player_acceleration_y()/5);
    player.set_jump_velocity(player.get_jump_velocity()/3);
    player.set_on_platform(true);
}

void Water::enscapsulated_collision_action(Player& player){
    if(touched_water == false){
        player.set_player_health(player.get_player_health() + health_modifier);
        touched_water = true;
    }
    player.set_player_acceleration_x(player.get_player_acceleration_x()/3);
    player.set_player_acceleration_y(player.get_player_acceleration_y()/5);
    player.set_jump_velocity(player.get_jump_velocity()/3);
    player.set_on_platform(true);
}

Water::~Water() {}