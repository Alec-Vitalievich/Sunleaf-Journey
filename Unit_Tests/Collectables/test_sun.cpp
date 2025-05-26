#include "catch_amalgamated.hpp"
#include "Collectables/Sun.h"
#include "Main/Player.h"

class Mock_Player : public Player {
    int mock_health;

    private:
        int health = 0;

    public:
        Mock_Player() : Player(0, 0, 32, 32, 5, 0), mock_health(5) {}

        int get_player_health() {
            return health;
        }
    
        void set_player_health(int h) {
            health = h;
        }
};

TEST_CASE("Sun initialsation") {
    Sun sun(100, 150, 32, 32);

    // Check position set correctly
    REQUIRE(sun.get_position().x == Catch::Approx(100));
    REQUIRE(sun.get_position().y == Catch::Approx(150));

    // Check size set correctly
    REQUIRE(sun.get_size().x == Catch::Approx(32));
    REQUIRE(sun.get_size().y == Catch::Approx(32));

}

TEST_CASE("Sun position update") {
    Sun sun(100, 150, 32, 32);
    sun.set_collectable_position(200, 300);

    // Check if new position is set correctly
    REQUIRE(sun.get_position().x == Catch::Approx(200));
    REQUIRE(sun.get_position().y == Catch::Approx(300));
}

TEST_CASE("Sun collision increases score"){
    Sun sun(50, 50, 32, 32);
    Mock_Player player;

    player.set_sun_count(0);
    sun.enscapsulated_collision_action(player);
    
    // Check if count increased
    REQUIRE(player.get_sun_count() == 1);

    // Check if sun moved out of bounds
    REQUIRE(sun.get_position().x == Catch::Approx(2000));
    REQUIRE(sun.get_position().y == Catch::Approx(2000));
   
}