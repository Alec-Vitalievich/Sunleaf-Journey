#include "save_manager.h"

bool save_manager::save_game(const save_data& data, const std::string& file_name) {
            std::ofstream file(file_name);
            if (!file.is_open()) {
                return false;
            }

            file << data.get_level_number() << '\n';
            file << data.get_player_position_x() << '\n';
            file << data.get_player_position_y() << '\n';
            file << data.get_player_health() << '\n';
            file << data.get_sun_count() << '\n';

            file.close();
            return true;
        }

bool save_manager::load_game(save_data& data, const std::string& file_name) {
            std::ifstream file(file_name);
            if (!file.is_open()) {
                return false;
            }

            int level, health, sun;
            float x, y;

            file >> level >> x >> y >> health >> sun;

            data.set_level_number(level);
            data.set_player_position(x, y);
            data.set_player_health(health);
            data.set_sun_count(sun);

            file.close();
            return true;
        }
