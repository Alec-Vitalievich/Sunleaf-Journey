#include "catch_amalgamated.hpp"
#include "Objects/Jump_Pad.h"
#include "Main/Player.h"

class Mock_Player : public Player {

    private:

    public:
        Mock_Player() : Player(0, 0, 32, 32, 5, 0) {}

};

TEST_CASE("Jump pad initialisation")
{
    Jump_Pad jump_pad(100, 100, 50, 50, 2);

    // Check position
    REQUIRE(jump_pad.get_position().x == Catch::Approx(100));
    REQUIRE(jump_pad.get_position().y == Catch::Approx(100));

    // Check size
    REQUIRE(jump_pad.get_size().x == Catch::Approx(50));
    REQUIRE(jump_pad.get_size().y == Catch::Approx(50));
}

TEST_CASE("Velocity changes")
{
    Mock_Player player;
    player.set_jump_velocity(20);

    SECTION("Doubled velocity")
    {
        Jump_Pad jump_pad(100, 100, 50, 50, 2);
        jump_pad.enscapsulated_collision_action(player);

        // Check if velocity doubled
        REQUIRE(player.get_jump_velocity() == 40);
    }

    SECTION("Same velocity")
    {
        Jump_Pad jump_pad(100, 100, 50, 50, 1);
        jump_pad.enscapsulated_collision_action(player);

        // Check if velocity doubled
        REQUIRE(player.get_jump_velocity() == 20);
    }

    SECTION("Negative velocity")
    {
        Jump_Pad jump_pad(100, 100, 50, 50, -1);
        jump_pad.enscapsulated_collision_action(player);

        // Check if velocity doubled
        REQUIRE(player.get_jump_velocity() == -20);
    }

    SECTION("No velocity")
    {
        Jump_Pad jump_pad(100, 100, 50, 50, 0);
        jump_pad.enscapsulated_collision_action(player);

        // Check if velocity doubled
        REQUIRE(player.get_jump_velocity() == 0);
    }
}
