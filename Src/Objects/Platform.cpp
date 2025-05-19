#include "Src/Objects/Platform.h"
#include "Src/Main/Player.h"

Platform::Platform(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y):
Object(platform_position_x, platform_position_y,platform_size_x, platform_size_y){
    object_hitbox.setFillColor(sf::Color::Black); // Will be replaced by texture
}

void Platform::vertical_collision_action(Player& player){ // This could be moved to player, in a way? We could call on functions in player anyways. But I think that's... a not so great idea.
    // sf::RectangleShape player_hitbox = player.get_player_hitbox();
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect platform_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();
    if(player.get_player_velocity_y() > 0){
        player.set_player_position(player_hitbox_boundaries.left, platform_hitbox_boundaries.top - player_hitbox_boundaries.height);
        player.set_on_platform(true);
    }
    
    if(player.get_player_velocity_y() < 0){
        player.set_player_position(player_hitbox_boundaries.left, platform_hitbox_boundaries.top + platform_hitbox_boundaries.height);
    }

    player.set_player_velocity_y(0);
}

void Platform::horizontal_collision_action(Player& player){
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect platform_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();
    if(player.get_player_velocity_x() > 0){
        player.set_player_position(platform_hitbox_boundaries.left - player_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }
    
    if(player.get_player_velocity_x() < 0){
        player.set_player_position(platform_hitbox_boundaries.left + platform_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }

    player.set_player_velocity_x(0);
}

void Platform::enscapsulated_collision_action(Player& player){
    // Doesn't do anything for standard platform.
}

Platform::~Platform(){
    // Nothin' to see here.
}