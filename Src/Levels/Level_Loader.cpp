#include "Levels/Level_Loader.h"
#include "Main/Player.h"

// Constructor for in-game portal to next level.
Level_Loader::Level_Loader(float platform_position_x, float platform_position_y, float platform_size_x, float platform_size_y, bool *new_level, int *current_level) : 
                            Object(platform_position_x, platform_position_y, platform_size_x, platform_size_y), new_level(new_level), current_level(current_level)
{
    object_hitbox.setFillColor(sf::Color::White); // Will be replaced by texture
}

// Empty implementations for unused collision types.
void Level_Loader::vertical_collision_action(Player &player) {}

void Level_Loader::horizontal_collision_action(Player &player) {}

// Action taken when player is within the boundary of the level_loader's hitbox.
void Level_Loader::enscapsulated_collision_action(Player &player)
{
    // Check if the player is pressing the E key.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        // Set the new level pointer to true, and increment the current_level.
        *new_level = true;
        (*current_level)++;

        // Reset player position, increment health (as a reward for getting to the next level), 
        // and set the new values to be saved if the player exits the level.
        player.set_player_position(0, 800);
        player.set_player_velocity_x(0);
        player.set_player_velocity_y(0);
        player.set_player_health(player.get_player_health() + 1);
        player.set_saved_player_health(player.get_player_health());
        player.set_saved_sun_count(player.get_sun_count());
    }
}

Level_Loader::~Level_Loader() {}