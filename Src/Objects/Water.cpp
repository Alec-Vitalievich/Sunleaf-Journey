#include "Objects/Water.h"
#include "Main/Player.h"

Water::Water(float Water_position_x, float Water_position_y, float Water_size_x, float Water_size_y, int health_modifer) : Obstacle(Water_position_x, Water_position_y, Water_size_x, Water_size_y, health_modifer)
{
    object_hitbox.setFillColor(sf::Color(0, 100, 255)); // Will be replaced by texture
    touched_water = false;
}

// Action when vertical-axis collision is detected.
void Water::vertical_collision_action(Player &player)
{
    // Check if the water has been touched already.
    if (touched_water == false)
    {
        // Increase health if never touched.
        player.set_player_health(player.get_player_health() + health_modifier);
        touched_water = true;
    }

    // Slow down (reduce acceleration & jump velocity) of player.
    player.set_player_acceleration_x(player.get_player_acceleration_x() / 3);
    player.set_player_acceleration_y(player.get_player_acceleration_y() / 5);
    player.set_jump_velocity(player.get_jump_velocity() / 3);
    player.set_on_platform(true);
}

// Action when horizontal-axis collision is detected.
void Water::horizontal_collision_action(Player &player)
{
    if (touched_water == false)
    {
        player.set_player_health(player.get_player_health() + health_modifier);
        touched_water = true;
    }
    player.set_player_acceleration_x(player.get_player_acceleration_x() / 3);
    player.set_player_acceleration_y(player.get_player_acceleration_y() / 5);
    player.set_jump_velocity(player.get_jump_velocity() / 3);
    player.set_on_platform(true);
}

// Action when it is detected that the player hitbox is within the water's hitbox.
void Water::enscapsulated_collision_action(Player &player)
{
    if (touched_water == false)
    {
        player.set_player_health(player.get_player_health() + health_modifier);
        touched_water = true;
    }
    player.set_player_acceleration_x(player.get_player_acceleration_x() / 3);
    player.set_player_acceleration_y(player.get_player_acceleration_y() / 5);
    player.set_jump_velocity(player.get_jump_velocity() / 3);
    player.set_on_platform(true);
}

Water::~Water() {}