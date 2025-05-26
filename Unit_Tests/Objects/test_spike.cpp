#include "catch_amalgamated.hpp"
#include "Objects/Spike.h"
#include "Main/Player.h"

class Mock_Player : public Player {

    private:

    public:
        Mock_Player() : Player(0, 0, 32, 32, 5, 0) {}

};

TEST_CASE("Spike initialisation")
{
    Spike spike(100, 100, 50, 50, 2);

    // Check position
    REQUIRE(spike.get_position().x == Catch::Approx(100));
    REQUIRE(spike.get_position().y == Catch::Approx(100));

    // Check size
    REQUIRE(spike.get_size().x == Catch::Approx(50));
    REQUIRE(spike.get_size().y == Catch::Approx(50));
}

TEST_CASE("Spike collision and damage")
{
    Mock_Player player;
    Spike spike(100, 100, 50, 50, 2);
    spike.enscapsulated_collision_action(player);

    // Check for position and damage
    REQUIRE(player.get_player_position().x == 0);
    REQUIRE(player.get_player_position().y == 800);
    // REQUIRE(player.get_player_health() == 3);
    
}