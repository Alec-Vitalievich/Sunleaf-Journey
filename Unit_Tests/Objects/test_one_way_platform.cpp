#include "catch_amalgamated.hpp"
#include "Objects/One_Way_Platform.h"
#include "Main/Player.h"

class Mock_Player : public Player {

    private:

    public:
        Mock_Player() : Player(0, 0, 32, 32, 5, 0) {}

};

TEST_CASE("One way platform initialisation")
{
    One_Way_Platform platform(100, 100, 50, 50);

    // Check position
    REQUIRE(platform.get_position().x == Catch::Approx(100));
    REQUIRE(platform.get_position().y == Catch::Approx(100));

    // Check size
    REQUIRE(platform.get_size().x == Catch::Approx(50));
    REQUIRE(platform.get_size().y == Catch::Approx(50));
}