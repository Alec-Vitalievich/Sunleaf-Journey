#include "catch_amalgamated.hpp"
#include "Levels/Level.h"
#include "Main/Player.h"

class Mock_Level : public Level {
    private:

    public:
        Mock_Level(int* level_number, bool* new_level)
            : Level(level_number, new_level) {}

        const std::vector<Object *>& get_level_data() const {
            return level_data;
        }
};

TEST_CASE("Level 1 initialisation")
{
    int level_number = 1;
    bool new_level = false;

    Mock_Level level(&level_number, &new_level);
    const auto& objects = level.get_level_data();

    SECTION("Level number constant")
    {
        REQUIRE(level.get_current_level() == 1);
    }

    SECTION("Level has correct number of objects")
    {
        REQUIRE(objects.size() == 23);
    }
}

TEST_CASE("Level 2 initialisation")
{
    int level_number = 2;
    bool new_level = false;

    Mock_Level level(&level_number, &new_level);
    const auto& objects = level.get_level_data();

    SECTION("Level number constant")
    {
        REQUIRE(level.get_current_level() == 2);
    }

    SECTION("Level has correct number of objects")
    {
        REQUIRE(objects.size() == 23);
    }
}

TEST_CASE("Level 3 initialisation")
{
    int level_number = 3;
    bool new_level = false;

    Mock_Level level(&level_number, &new_level);
    const auto& objects = level.get_level_data();

    SECTION("Level number constant")
    {
        REQUIRE(level.get_current_level() == 3);
    }

    SECTION("Level has correct number of objects")
    {
        REQUIRE(objects.size() == 23);
    }
}