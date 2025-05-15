#include "Game.h"
#include "Player.h"

int main(){
    Game game(1920,1080,"Sunflower Journey: The Quest For Sun",60,1);
    game.update();
    return 0;
}