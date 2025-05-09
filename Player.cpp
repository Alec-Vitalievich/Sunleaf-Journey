#include "Player.h"

Player::Player(float player_position_x, float player_position_y, float player_size_x, float player_size_y){
    player_hitbox.setPosition(player_position_x, player_position_y);
    player_hitbox.setSize({player_size_x, player_size_y}); // Takes a vector2f, or 2 position in {}.
    player_hitbox.setFillColor(sf::Color::Cyan); // Will be replaced by texture

    player_acceleration.x = 2000; // Horiztonal acceleration
    player_acceleration.y = 1500; // Gravity
    max_speed.x = 500;
    max_speed.y = 5000; // I have no idea what this value should be, so it can just be large for now.
    friction_reduction = 750;
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
    // Detect movement using sf::Keyboard::isKeyPressed(...)
    // Calculate velocities (appropriately, sign changes),
    // apply friction appropriately (sign changes) when horizontal movement is not occuring.
    // apply maximum and minimum vertical velocities.
    // Add jump when space is pressed & the character is detected on the ground

    // Applying the movement may need to be considered? Was being done in the collision function for vertical, 
    // but we haven't done horizontal yet either.. 
    // I think we'll need to call on the aggregated platforms/obstacles collision's to check before moving.
}

Player::~Player(){
    // Nothin' to see here.
}