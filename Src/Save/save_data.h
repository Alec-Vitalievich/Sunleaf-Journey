#ifndef SAVE_DATA_H
#define SAVE_DATA_H

class save_data {
    private:
        int level_number;
        float player_position_x;
        float player_position_y;
        int player_health;
        int sun_count;

    public:
        save_data(int level = 0, float x = 0, float y = 0, int health = 100, int sun = 0);

        //Getters and setters
        int get_level_number() const;
        float get_player_position_x() const;
        float get_player_position_y() const;
        int get_player_health() const;
        int get_sun_count() const;

        void set_level_number(int level);
        void set_player_position(float x, float y);
        void set_player_health(int health);
        void set_sun_count(int sun);
};

#endif