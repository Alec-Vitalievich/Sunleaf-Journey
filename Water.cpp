#include "Water.h"
#include "Player.h"

Water::Water(float Water_position_x, float Water_position_y, float Water_size_x, float Water_size_y, int health_modifer):
Obstacle(Water_position_x, Water_position_y,Water_size_x, Water_size_y, health_modifer){
    object_hitbox.setFillColor(sf::Color(0,100,255)); // Will be replaced by texture
}

void Water::vertical_collision_action(Player& player){ // This could be moved to player, in a way? We could call on functions in player anyways. But I think that's... a not so great idea.
    player.set_player_position(10, 980);
    player.set_player_health(player.get_player_health() + health_modifier);
    player.set_on_platform(true);
    player.set_player_velocity_x(0);
    player.set_player_velocity_y(0);
}

void Water::horizontal_collision_action(Player& player){
    player.set_player_position(10, 980);
    player.set_player_health(player.get_player_health() + health_modifier);
    player.set_on_platform(true);
    player.set_player_velocity_x(0);
    player.set_player_velocity_y(0);
}

void Water::enscapsulated_collision_action(Player& player){
    player.set_player_position(10, 980);
    player.set_player_health(player.get_player_health() + health_modifier);
    player.set_on_platform(true);
    player.set_player_velocity_x(0);
    player.set_player_velocity_y(0);
}

Water::~Water(){
    // Nothin' to see here.
}