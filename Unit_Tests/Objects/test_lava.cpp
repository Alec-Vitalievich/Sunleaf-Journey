#include "catch_amalgamated.hpp"
#include "Objects/Lava.h"
#include "Main/Player.h"

class Mock_Player : public Player {
    private:

    public:
        Mock_Player() : Player(0, 0, 32, 32, 5, 0) {}
};

TEST_CASE("Lava initialisation")
{
    Lava lava(100, 100, 50, 50, 2);

    // Check position
    REQUIRE(lava.get_position().x == Catch::Approx(100));
    REQUIRE(lava.get_position().y == Catch::Approx(100));

    // Check size
    REQUIRE(lava.get_size().x == Catch::Approx(50));
    REQUIRE(lava.get_size().y == Catch::Approx(50));
}

TEST_CASE("Lava collision and damage")
{
    Lava lava(100, 100, 50, 50, 1);
    Mock_Player player;

    lava.enscapsulated_collision_action(player);

    // Check for position and damage
    REQUIRE(player.get_player_position().x == 0);
    REQUIRE(player.get_player_position().y == 800);
    // REQUIRE(player.get_player_health() == 4);
    REQUIRE(player.get_on_platform() == true);
    REQUIRE(player.get_player_velocity_x() == 0);
    REQUIRE(player.get_player_velocity_y() == 0);
}