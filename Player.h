#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Player{ // Maybe add a name attribute?
    protected:
        sf::RectangleShape player_hitbox;
        sf::Vector2f player_velocity;
        sf::Vector2f player_acceleration;
        sf::Vector2f max_speed;
        float friction_reduction;
        bool on_platform;
    public:
        Player(float player_position_x, float player_position_y, float player_size_x, 
               float player_size_y); // Some of these can probably be changed to constant variables.

        bool get_on_platform();
        void set_on_platform(bool on_platform);

        sf::RectangleShape& get_player_hitbox();
        // void set_player_hitbox(); ^ Shouldn't be needed when passing by reference.

        void player_update(double dt);

        ~Player();
};

#endif