#include "Player.h"

Player::Player(float player_position_x, float player_position_y, float player_size_x, float player_size_y){
    player_hitbox.setPosition(player_position_x, player_position_y);
    player_hitbox.setSize({player_size_x, player_size_y}); // Takes a vector2f, or 2 position in {}.
    player_hitbox.setFillColor(sf::Color::Cyan); // Will be replaced by texture

    player_acceleration.x = 2000; // Horizontal acceleration
    player_acceleration.y = 1500; // Gravity
    max_player_velocity.x = 500;
    max_player_velocity.y = 5000; // I have no idea what this value should be, so it can just be large for now.
    friction_reduction = 750;
    jump_velocity = -500;
    on_platform = false;
}

bool Player::get_on_platform(){
    return on_platform;
}
void Player::set_on_platform(bool on_platform){
    this->on_platform = on_platform;
}

sf::RectangleShape& Player::get_player_hitbox(){
    return player_hitbox;
}

void Player::player_update(double dt){
    horizontal_movement(dt);
    vertical_movement(dt);
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

    // Cap. speed.
    if(player_velocity.x > max_player_velocity.x){
        player_velocity.x = max_player_velocity.x;
    }
    else if(player_velocity.x < -max_player_velocity.x){
        player_velocity.x = -max_player_velocity.x;
    }

    player_hitbox.move(player_velocity.x * dt, 0); // Will be moved to collision function.
}
void Player::vertical_movement(double dt){
    // Jump
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        player_velocity.y = jump_velocity;
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

    player_hitbox.move(0, player_velocity.y * dt); // Will be moved to collision function.
}
void Player::horizontal_collision(){
    //
}
void Player::vertical_collision(){
    //
}

Player::~Player(){
    // Nothin' to see here.
}