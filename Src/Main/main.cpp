#include "Main/Game.h"
#include "Main/Player.h"

int main()
{
    Game game(1800, 1020, "Sunflower Journey: The Quest For Sun", 60);
    game.update();
    return 0;
}