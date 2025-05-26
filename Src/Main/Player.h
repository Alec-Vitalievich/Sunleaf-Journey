#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Levels/Level.h"

class Player
{ // Maybe add a name attribute?
protected:

    // Player attributes
    sf::RectangleShape player_hitbox;
    sf::Vector2f player_velocity;
    sf::Vector2i player_acceleration;
    sf::Vector2i max_player_velocity; // Maybe change to max velocity for consistency?
    int player_health;
    int saved_player_health;
    int sun_count;
    int saved_sun_count;
    int friction_reduction;
    int jump_velocity;
    bool on_platform;

    // Player texture
    sf::Texture player_texture;

public:

    // Player constructor
    Player(float player_position_x, float player_position_y, float player_size_x,
           float player_size_y, int player_health, int sun_count); // Some of these can probably be changed to constant variables.

    // Getters and setters
    bool get_on_platform();
    void set_on_platform(bool on_platform);

    float get_player_velocity_x();
    void set_player_velocity_x(float new_velocity);

    float get_player_velocity_y();
    void set_player_velocity_y(float new_velocity);

    int get_player_acceleration_x();
    void set_player_acceleration_x(int new_acceleration);

    int get_player_acceleration_y();
    void set_player_acceleration_y(int new_acceleration);

    int get_player_health();
    void set_player_health(int player_health);

    int get_sun_count();
    void set_sun_count(int sun_count);

    int get_saved_player_health();
    void set_saved_player_health(int saved_player_health);

    int get_saved_sun_count();
    void set_saved_sun_count(int saved_sun_count);

    int get_jump_velocity();
    void set_jump_velocity(int jump_velocity);

    sf::Vector2f get_player_position();

    void set_player_position(float position_x, float position_y);

    sf::RectangleShape &get_player_hitbox();
    // void set_player_hitbox(); ^ Shouldn't be needed when passing by reference.

    // Movement and collision constructors
    void horizontal_movement(double dt);
    void vertical_movement(double dt);
    void horizontal_collision(double dt, std::vector<Object *> &level_data);
    void vertical_collision(double dt, std::vector<Object *> &level_data);
    void encapsulated_collision(double dt, std::vector<Object *> &level_data);
    void player_update(double dt, std::vector<Object *> &level_data);

    // Destructor
    ~Player();
};

#endif