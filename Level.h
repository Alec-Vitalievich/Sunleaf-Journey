#ifndef LEVEL_H
#define LEVEL_H
#include "Object.h"
#include "Platform.h"
class Level{
    protected:
        std::vector<Object*> level_data;
    public:
    Level(int level_number);
    std::vector<Object*>& get_level_vector();
    ~Level();
};

#endif