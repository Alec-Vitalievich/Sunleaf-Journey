#include "Objects/Obstacle.h"
#include "Main/Player.h"

// TODO: comments
Spike::Spike(float spike_position_x, float spike_position_y, float spike_size_x, float spike_size_y, int health_modifer) : Obstacle(spike_position_x, spike_position_y, spike_size_x, spike_size_y, health_modifer)
{
    // Attempt to load spike texture.
    if (!spike_texture.loadFromFile("Assets/Textures/ObjectTextures/spike.png"))
    {
        std::cout << "Failed to load spike texture!" << std::endl;
        object_hitbox.setFillColor(sf::Color::White);
    }
    else
    {
        object_hitbox.setTexture(&spike_texture);
    }
}

// Action when vertical-axis collision is detected.
void Spike::vertical_collision_action(Player &player)
{
    // Get player & spike hitbox boundaries.
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect spike_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();

    // Check if player is moving down (positive velocity.)
    if (player.get_player_velocity_y() > 0)
    {
        // Reduce player health by the health modifier and reset player back to the start of the level.
        player.set_player_position(0, 800);
        player.set_player_health(player.get_player_health() - health_modifier);
        player.set_on_platform(false);
    }

    // Check if player is moving up (negative velocity).
    if (player.get_player_velocity_y() < 0)
    {
        // Snap player to bottom of spike.
        player.set_player_position(player_hitbox_boundaries.left, spike_hitbox_boundaries.top + spike_hitbox_boundaries.height);
    }

    player.set_player_velocity_y(0);
}

// Action when horizontal-axis collision is detected.
void Spike::horizontal_collision_action(Player &player)
{
    // Retrieve player & spike's hitbox boundaries.
    sf::FloatRect player_hitbox_boundaries = player.get_player_hitbox().getGlobalBounds();
    sf::FloatRect spike_hitbox_boundaries = this->get_object_hitbox().getGlobalBounds();

    // Check if player is moving left.
    if (player.get_player_velocity_x() > 0)
    {
        // Snap player to right boundary of spike.
        player.set_player_position(spike_hitbox_boundaries.left - player_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }

    // Check if player is moving right.
    if (player.get_player_velocity_x() < 0)
    {
        // Snap player to left boundary of spike.
        player.set_player_position(spike_hitbox_boundaries.left + spike_hitbox_boundaries.width, player_hitbox_boundaries.top);
    }

    player.set_player_velocity_x(0);
}

// Action if the player enters the spike's hitbox:
void Spike::enscapsulated_collision_action(Player &player)
{
    // Teleport player to start of level and reduce health by modifier.
    player.set_player_position(0, 800);
    player.set_player_health(player.get_player_health() - health_modifier);
}

Spike::~Spike() {}