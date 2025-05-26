#include "Save/save_manager.h"

bool save_manager::save_game(save_data &data, const std::string &file_name)
{
    // Open file, and check it opened correctly.
    std::ofstream file(file_name);
    if (!file.is_open())
    {
        return false;
    }

    // Save game data to save file.
    file << data.get_level_number() << '\n';
    file << data.get_player_health() << '\n';
    file << data.get_sun_count() << '\n';

    file.close();
    return true;
}

bool save_manager::load_game(save_data &data, const std::string &file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        return false;
    }

    int level, health, sun;

    // Retrieve values.
    file >> level >> health >> sun;

    // Save the values to the save data class.
    data.set_level_number(level);
    data.set_player_health(health);
    data.set_sun_count(sun);

    file.close();
    return true;
}
