#include "catch_amalgamated.hpp"
#include "Collectables/Heart.h"
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

TEST_CASE("Heart initialisation") {
    Heart heart(100, 150, 32, 32);

    // Check position set correctly
    REQUIRE(heart.get_position().x == Catch::Approx(100));
    REQUIRE(heart.get_position().y == Catch::Approx(150));

    // Check size set correctly
    REQUIRE(heart.get_size().x == Catch::Approx(32));
    REQUIRE(heart.get_size().y == Catch::Approx(32));
}

TEST_CASE("Heart position update") {
    Heart heart(0, 0, 32, 32);
    heart.set_collectable_position(200, 300);

    // Check if new position is set correctly
    REQUIRE(heart.get_position().x == Catch::Approx(200));
    REQUIRE(heart.get_position().y == Catch::Approx(300));
}

TEST_CASE("Heart collision increases health"){
    Heart heart(50, 50, 32, 32);
    Mock_Player player;

    int health = player.get_player_health();

    heart.enscapsulated_collision_action(player);

    // Check if health increased
    REQUIRE(player.get_player_health() == health + 1); 

    // Check if heart moved out of bounds
    REQUIRE(heart.get_position().x == Catch::Approx(2000));
    REQUIRE(heart.get_position().y == Catch::Approx(2000));
}