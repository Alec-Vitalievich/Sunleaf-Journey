#include "Src/Save/save_data.h"

save_data::save_data(int level, float x, float y, int health, int sun) : level_number(level),
    player_position_x(x), player_position_y(y), player_health(health), sun_count(sun) {}

//Getters  
int save_data::get_level_number() const {
    return level_number;
}

float save_data::get_player_position_x() const {
    return player_position_x;
}

float save_data::get_player_position_y() const {
    return player_position_y;
}

int save_data::get_player_health() const {
    return player_health;
}

int save_data::get_sun_count() const {
    return sun_count;
}

//Setters
void save_data::set_level_number(int level) {
    level_number = level;
}

void save_data::set_player_position(float x, float y) {
    player_position_x = x;
    player_position_y = y;
}

void save_data::set_player_health(int health) {
    player_health = health;
}

void save_data::set_sun_count(int sun) {
    sun_count = sun;
}