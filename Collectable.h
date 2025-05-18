#ifndef COLLECT_H
#define COLLECT_H
#include "Object.h"
class Collectable: public Object{
    protected:
    public:
        Collectable(float collectable_pos_x, float collectable_pos_y, float collectable_size_x, float collectable_size_y);
        virtual void set_collectable_position(int x, int y) = 0;
};


#endif