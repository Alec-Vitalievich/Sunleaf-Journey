#ifndef SAVE_DATA_H
#define SAVE_DATA_H

class save_data
{
private:
    int level_number;
    int player_health;
    int sun_count;

public:
    save_data(int level = 1, int health = 3, int sun = 0);

    // Getters and setters
    int get_level_number() const;
    int get_player_health() const;
    int get_sun_count() const;

    void set_level_number(int level);
    void set_player_health(int health);
    void set_sun_count(int sun);
};

#endif