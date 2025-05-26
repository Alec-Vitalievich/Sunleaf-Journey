#include "Objects/Platform.h"
#include "Main/Player.h"


Platform::Platform(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y) : Object(platform_position_x, platform_position_y, platform_size_x, platform_size_y)
{
    object_hitbox.setFillColor(sf::Color(74, 44, 42)); // Will be replaced by texture
}

// Action when vertical-axis collision is detected.
void Platform::vertical_collision_action(Player &player)
{
    // Retrieve player & platform hitbox boundaries.
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect platform_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();
    
    // Check if the player is moving downwards (positive y-velocity).
    if (player.get_player_velocity_y() > 0)
    {
        // Snap player to top boundary of platform.
        player.set_player_position(player_hitbox_boundaries.left, platform_hitbox_boundaries.top - player_hitbox_boundaries.height);
        player.set_on_platform(true);
    }

    // Check if the player is moving upwards (negative y-velocity).
    if (player.get_player_velocity_y() < 0)
    {
        // Snap player to bottom boundary of platform.
        player.set_player_position(player_hitbox_boundaries.left, platform_hitbox_boundaries.top + platform_hitbox_boundaries.height);
    }

    player.set_player_velocity_y(0);
}

// Action when horizontal-axis collision is detected.
void Platform::horizontal_collision_action(Player &player)
{
    // Retrieve player & platform hitbox boundaries.
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect platform_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();
    
    // Check if player is moving to the right.
    if (player.get_player_velocity_x() > 0)
    {
        // Snap player to left boundary of platform.
        player.set_player_position(platform_hitbox_boundaries.left - player_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }

    // Check if player is moving to the left.
    if (player.get_player_velocity_x() < 0)
    {
        // Snap player to the right boundary of platform.
        player.set_player_position(platform_hitbox_boundaries.left + platform_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }

    player.set_player_velocity_x(0);
}

// Empty implementation for unused collision.
void Platform::enscapsulated_collision_action(Player &player) {}

Platform::~Platform() {}