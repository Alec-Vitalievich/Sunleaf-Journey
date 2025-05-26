#include "catch_amalgamated.hpp"
#include "Objects/Water.h"
#include "Main/Player.h"

class Mock_Player : public Player {

    private:

    public:
        Mock_Player() : Player(0, 0, 32, 32, 5, 0) {}

};

TEST_CASE("Water initialisation")
{
    Water water(100, 100, 50, 50, 2);

    // Check position
    REQUIRE(water.get_position().x == Catch::Approx(100));
    REQUIRE(water.get_position().y == Catch::Approx(100));

    // Check size
    REQUIRE(water.get_size().x == Catch::Approx(50));
    REQUIRE(water.get_size().y == Catch::Approx(50));
}

TEST_CASE("Collision and health regeneration")
{
    Mock_Player player;
        player.set_player_acceleration_x(9.0);
        player.set_player_acceleration_y(15.0);
        player.set_jump_velocity(12.0);
    Water water(100, 100, 50, 50, 2);

    water.enscapsulated_collision_action(player);

    // REQUIRE(player.get_player_health() == 7);
    REQUIRE(player.get_player_acceleration_x() == Catch::Approx(3));
    REQUIRE(player.get_player_acceleration_y() == Catch::Approx(3));
    REQUIRE(player.get_jump_velocity() == Catch::Approx(4));
    REQUIRE(player.get_on_platform() == true);

}