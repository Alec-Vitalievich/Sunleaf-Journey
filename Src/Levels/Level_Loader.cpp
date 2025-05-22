#include "Levels/Level_Loader.h"
#include "Main/Player.h"

Level_Loader::Level_Loader(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y, bool* new_level, int* current_level):
Object(platform_position_x, platform_position_y,platform_size_x, platform_size_y),new_level(new_level),current_level(current_level){
    object_hitbox.setFillColor(sf::Color::White); // Will be replaced by texture
}

void Level_Loader::vertical_collision_action(Player& player){}

void Level_Loader::horizontal_collision_action(Player& player){}

void Level_Loader::enscapsulated_collision_action(Player& player){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        *new_level = true;
        (*current_level)++;
        player.set_player_position(0,800); // Change to wherever the player's starting position is.
        player.set_player_velocity_x(0);
        player.set_player_velocity_y(0);
        player.set_player_health(player.get_player_health() + 1);
    }
}

Level_Loader::~Level_Loader(){
    // Nothin' to see here.
}