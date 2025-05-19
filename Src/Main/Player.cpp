#include "Main/Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(float player_position_x, float player_position_y, float player_size_x, 
                float player_size_y, int player_health, int sun_count){
    
    
    player_hitbox.setPosition(player_position_x, player_position_y);
    player_hitbox.setSize({player_size_x, player_size_y}); // Takes a vector2f, or 2 position in {}.
    
    if (!player_texture.loadFromFile("Assets/Textures/player_texture.png")) {
        std::cerr << "Failed to load player texture";
        player_hitbox.setFillColor(sf::Color::Magenta);
    } else {
        player_hitbox.setTexture(&player_texture);
    }

    this->player_health = player_health;
    this->sun_count = sun_count;

    player_acceleration.x = 2000; // Horizontal acceleration
    player_acceleration.y = 1500; // Gravity
    max_player_velocity.x = 500;
    max_player_velocity.y = 1500; // I have no idea what this value should be, so it can just be large for now.
    friction_reduction = 750;
    jump_velocity = -600;
    on_platform = false;
}

bool Player::get_on_platform(){
    return on_platform;
}
void Player::set_on_platform(bool on_platform){
    this->on_platform = on_platform;
}

float Player::get_player_velocity_x(){
    return player_velocity.x;
}
void Player::set_player_velocity_x(float new_velocity){
    player_velocity.x = new_velocity;
}

float Player::get_player_velocity_y(){
    return player_velocity.y;
}
void Player::set_player_velocity_y(float new_velocity){
    player_velocity.y = new_velocity;
}

int Player::get_player_acceleration_x(){
    return player_acceleration.x;
}
void Player::set_player_acceleration_x(int new_acceleration){
    player_acceleration.x = new_acceleration;
}

int Player::get_player_acceleration_y(){
    return player_acceleration.y;
}
void Player::set_player_acceleration_y(int new_acceleration){
    player_acceleration.y = new_acceleration;
}

int Player::get_player_health(){
    return player_health;
}
void Player::set_player_health(int player_health){
    this->player_health = player_health;
}

int Player::get_sun_count(){
    return sun_count;
}
void Player::set_sun_count(int sun_count){
    this->sun_count = sun_count;
}

int Player::get_jump_velocity(){
    return jump_velocity;
}
void Player::set_jump_velocity(int jump_velocity){
    this->jump_velocity = jump_velocity;
}

sf::Vector2f Player::get_player_position() {
    return player_hitbox.getPosition();
}

void Player::set_player_position(float position_x, float position_y){
    player_hitbox.setPosition(position_x, position_y);
}

sf::RectangleShape& Player::get_player_hitbox(){
    return player_hitbox;
}

void Player::player_update(double dt, std::vector<Object*>& level_data){
    // Potentially move to game class
    if(player_health < 0){
        player_health = 0;
    }
    else if(player_health > 3){
        player_health = 3;
    }
    
    horizontal_movement(dt);
    horizontal_collision(dt, level_data);
    vertical_movement(dt);
    vertical_collision(dt, level_data);
    encapsulated_collision(dt, level_data);
}

void Player::horizontal_movement(double dt){
    int input = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        input = -1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        input = 1;
    }

    if(input == -1 || input == 1){
        // Apply movement.
        player_velocity.x += input * player_acceleration.x * dt; // Input changes the direction, times by the acceleration and the time passed.
    }
    else if(input == 0){
        // Apply friction reduction (since movement has stopped)
        if(player_velocity.x > 0){ // Moving to right.
            player_velocity.x += -friction_reduction * dt;
            if (player_velocity.x < 0){ // Prevents movement from oscillating back and forth if it overshoots the stopping velocity.
                player_velocity.x = 0;
            }
        }
        else if(player_velocity.x < 0){ // Moving to left.
            player_velocity.x += friction_reduction * dt;
            if(player_velocity.x > 0){
                player_velocity.x = 0;
            }
        }
    }
    else{ // Just in case. Shouldn't actually be possible for input to be any other value.
        input = 0;
    }

    player_acceleration.x = 2000;

    // Cap. speed.
    if(player_velocity.x > max_player_velocity.x){
        player_velocity.x = max_player_velocity.x;
    }
    else if(player_velocity.x < -max_player_velocity.x){
        player_velocity.x = -max_player_velocity.x;
    }
}

void Player::vertical_movement(double dt){
    // Jump
    if(on_platform == true && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))){
        player_velocity.y = jump_velocity;
        on_platform = false;
    }

    jump_velocity = -600;

    if(player_velocity.y > 0){
        on_platform = false;
    }

    // Gravity
    player_velocity.y += player_acceleration.y * dt;
    if(player_velocity.y > max_player_velocity.y){
        player_velocity.y = max_player_velocity.y;
    }
    else if(player_velocity.y < -max_player_velocity.y){ // Shouldn't really be possible, but just in case.
        player_velocity.y = -max_player_velocity.y;
    }

    player_acceleration.y = 1500;

}

void Player::horizontal_collision(double dt, std::vector<Object*>& level_data){
    sf::FloatRect player_boundary = player_hitbox.getGlobalBounds(); // Get the boundary coordinates of the current hitbox.
    float player_bottom = player_boundary.top + player_boundary.height;
    float player_right = player_boundary.left + player_boundary.width;

    // Predict where the player's hitbox will be in the next frame (for swept collision)
    sf::FloatRect future_player_boundary = player_hitbox.getGlobalBounds();
    future_player_boundary.left += player_velocity.x * dt; // Predict where player will be next frame.
    float future_player_right = future_player_boundary.left + future_player_boundary.width;

    for(int i = 0; i < level_data.size(); i++){
        sf::RectangleShape current_object = level_data[i]->get_object_hitbox();
        sf::FloatRect object_boundary = current_object.getGlobalBounds();
        float object_bottom = object_boundary.top + object_boundary.height;
        float object_right = object_boundary.left + object_boundary.width;

        // Moving to right
        if(player_velocity.x > 0 && (player_right <= object_boundary.left && future_player_right >= object_boundary.left
        && player_bottom > object_boundary.top && player_boundary.top < object_bottom)){
            level_data[i]->horizontal_collision_action(*this); // Passes the object that called the function (player) into the function.
            break;
        }

        // Moving to left
        if(player_velocity.x < 0 && (player_boundary.left >= object_right && future_player_boundary.left <= object_right
        && player_bottom > object_boundary.top && player_boundary.top < object_bottom)){
            level_data[i]->horizontal_collision_action(*this); // Passes the object that called the function (player) into the function.
            break;
        }
    }
    player_hitbox.move(player_velocity.x * dt, 0);
}

void Player::vertical_collision(double dt, std::vector<Object*>& level_data){
    sf::FloatRect player_boundary = player_hitbox.getGlobalBounds(); // Get the boundary coordinates of the current hitbox.
    float player_bottom = player_boundary.top + player_boundary.height;
    float player_right = player_boundary.left + player_boundary.width;

    // Predict where the player's hitbox will be in the next frame (for swept collision)
    sf::FloatRect future_player_boundary = player_hitbox.getGlobalBounds();
    future_player_boundary.top += player_velocity.y * dt; // Predict where player will be next frame.
    float future_player_bottom = future_player_boundary.top + future_player_boundary.height;

    for(int i = 0; i < level_data.size(); i++){
        sf::RectangleShape current_object = level_data[i]->get_object_hitbox();
        sf::FloatRect object_boundary = current_object.getGlobalBounds();
        float object_bottom = object_boundary.top + object_boundary.height;
        float object_right = object_boundary.left + object_boundary.width;

        // might be worth splitting the following if statement up a little for readability reasons.
        if(player_velocity.y > 0 && (player_bottom <= object_boundary.top && future_player_bottom >= object_boundary.top
        && player_right > object_boundary.left && player_boundary.left < object_right)){
            level_data[i]->vertical_collision_action(*this); // Passes the object that called the function (player) into the function.
            break;
        }

        // What comes up, must go down.
        if(player_velocity.y < 0 && (player_boundary.top >= object_bottom && future_player_boundary.top <= object_bottom
        && player_right > object_boundary.left && player_boundary.left < object_right)){
            level_data[i]->vertical_collision_action(*this); // Passes the object that called the function (player) into the function.
            break;
        }
    }
    player_hitbox.move(0, player_velocity.y * dt);
}

void Player::encapsulated_collision(double dt, std::vector<Object*>& level_data){
    sf::FloatRect player_boundary = player_hitbox.getGlobalBounds(); // Get the boundary coordinates of the current hitbox.
    float player_bottom = player_boundary.top + player_boundary.height;
    float player_right = player_boundary.left + player_boundary.width;

    for(int i = 0; i < level_data.size(); i++){
        sf::RectangleShape current_object = level_data[i]->get_object_hitbox();
        sf::FloatRect object_boundary = current_object.getGlobalBounds();
        float object_bottom = object_boundary.top + object_boundary.height;
        float object_right = object_boundary.left + object_boundary.width;

        // might be worth splitting the following if statement up a little for readability reasons. Removing the velocity requirement may be a good idea too? unsure.
        if(player_boundary.left < object_right && player_right > object_boundary.left && player_boundary.top < object_bottom &&
        player_bottom > object_boundary.top){
            level_data[i]->enscapsulated_collision_action(*this); // Passes the object that called the function (player) into the function.
            break;
        }
    }
}

Player::~Player(){
    // Nothin' to see here.
}