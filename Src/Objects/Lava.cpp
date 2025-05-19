#include "Lava.h"
#include "Player.h"

Lava::Lava(float Lava_position_x, float Lava_position_y, float Lava_size_x, float Lava_size_y, int health_modifer):
Obstacle(Lava_position_x, Lava_position_y,Lava_size_x, Lava_size_y, health_modifer){
    object_hitbox.setFillColor(sf::Color::Red); // Will be replaced by texture
}

void Lava::vertical_collision_action(Player& player){ // This could be moved to player, in a way? We could call on functions in player anyways. But I think that's... a not so great idea.
    player.set_player_position(0,800);
    player.set_player_health(player.get_player_health() - health_modifier);
    player.set_on_platform(true);
    player.set_player_velocity_x(0);
    player.set_player_velocity_y(0);
}

void Lava::horizontal_collision_action(Player& player){
    player.set_player_position(0,800);
    player.set_player_health(player.get_player_health() - health_modifier);
    player.set_on_platform(true);
    player.set_player_velocity_x(0);
    player.set_player_velocity_y(0);
}

void Lava::enscapsulated_collision_action(Player& player){
    player.set_player_position(0,800);
    player.set_player_health(player.get_player_health() - health_modifier);
    player.set_on_platform(true);
    player.set_player_velocity_x(0);
    player.set_player_velocity_y(0);
}

Lava::~Lava(){
    // Nothin' to see here.
}