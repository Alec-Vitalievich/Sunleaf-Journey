#include "Objects/Obstacle.h"

Obstacle::Obstacle(float Obstacle_position_x, float Obstacle_position_y, float Obstacle_size_x, float Obstacle_size_y, int health_modifier):
Object(Obstacle_position_x, Obstacle_position_y,Obstacle_size_x, Obstacle_size_y),health_modifier(health_modifier){
}

Obstacle::~Obstacle(){
    // Nothin' to see here.
}