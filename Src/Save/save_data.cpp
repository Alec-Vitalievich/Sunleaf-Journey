#include "Save/save_data.h"

save_data::save_data(int level, int health, int sun) : level_number(level), player_health(health), sun_count(sun) {}

// Getters
int save_data::get_level_number() const
{
    return level_number;
}

int save_data::get_player_health() const
{
    return player_health;
}

int save_data::get_sun_count() const
{
    return sun_count;
}

// Setters
void save_data::set_level_number(int level)
{
    if (level < 1)
    {
        level_number = 1;
    }
    else if (level > 3)
    {
        level_number = 3;
    }
    else
    {
        level_number = level;
    }
}

void save_data::set_player_health(int health)
{
    if (health < 1)
    {
        player_health = 1;
    }
    else if (health > 3)
    {
        player_health = 3;
    }
    else
    {
        player_health = health;
    }
}

void save_data::set_sun_count(int sun)
{
    if (sun < 0)
    {
        sun_count = 0;
    }
    else
    {
        sun_count = sun;
    }
}