#include "Objects/Obstacle.h"
#include "Main/Player.h"

// TODO: comments
Spike::Spike(float spike_position_x, float spike_position_y, float spike_size_x, float spike_size_y, int health_modifer):
Obstacle(spike_position_x, spike_position_y,spike_size_x, spike_size_y, health_modifer){
    if(!spike_texture.loadFromFile("Assets/Textures/ObjectTextures/spike.png")){
        std::cout << "Failed to load sun texture!" << std::endl;
    }
    else{
        object_hitbox.setTexture(&spike_texture);
    }
}

void Spike::vertical_collision_action(Player& player){
    // sf::RectangleShape player_hitbox = player.get_player_hitbox();
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect spike_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();
    if(player.get_player_velocity_y() > 0){
        player.set_player_position(0,800);
        player.set_player_health(player.get_player_health() - health_modifier);
        player.set_on_platform(true);
    }
    
    if(player.get_player_velocity_y() < 0){
        player.set_player_position(player_hitbox_boundaries.left, spike_hitbox_boundaries.top + spike_hitbox_boundaries.height);
    }

    player.set_player_velocity_y(0);
}

void Spike::horizontal_collision_action(Player& player){
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect spike_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();
    if(player.get_player_velocity_x() > 0){
        player.set_player_position(spike_hitbox_boundaries.left - player_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }
    
    if(player.get_player_velocity_x() < 0){
        player.set_player_position(spike_hitbox_boundaries.left + spike_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }

    player.set_player_velocity_x(0);
}

void Spike::enscapsulated_collision_action(Player& player){
    player.set_player_position(0,800);
    player.set_player_health(player.get_player_health() - health_modifier);
    // Doesn't do anything for spikes.
}

Spike::~Spike(){
    // Nothin' to see here.
}