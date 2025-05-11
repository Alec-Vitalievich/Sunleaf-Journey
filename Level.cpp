#include "Level.h"

Level::Level(int level_number){
    if(level_number > 3){
        level_number = 3;
    }
    else if(level_number < 0){
        level_number = 0;
    }
    switch(level_number){
        case 1:
            level_data.push_back(new Platform(30, 750, 200, 20));
            level_data.push_back(new Platform(30, 650, 200, 20));
            level_data.push_back(new Platform(230, 650, 20, 120));
            level_data.push_back(new Platform(10, 650, 20, 120));
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

std::vector<Object*>& Level::get_level_vector(){
    return level_data;
}

Level::~Level(){
    for(int i = 0; i < level_data.size(); i++){
        delete level_data[i];
    }
}