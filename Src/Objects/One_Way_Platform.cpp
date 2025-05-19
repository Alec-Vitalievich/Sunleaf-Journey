#include "Src/Objects/One_Way_Platform.h"
#include "Src/Main/Player.h"

One_Way_Platform::One_Way_Platform(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y):
Platform(platform_position_x, platform_position_y, platform_size_x, platform_size_y){
    object_hitbox.setFillColor(sf::Color(0,0,0,200));
}

void One_Way_Platform::vertical_collision_action(Player& player){
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect platform_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();
    if(player.get_player_velocity_y() > 0){
        player.set_player_position(player_hitbox_boundaries.left, platform_hitbox_boundaries.top - player_hitbox_boundaries.height);
        player.set_on_platform(true);
        player.set_player_velocity_y(0);
    }
}

void One_Way_Platform::horizontal_collision_action(Player& player){}

One_Way_Platform::~One_Way_Platform(){}