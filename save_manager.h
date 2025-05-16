#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include "save_data.h"

#include <fstream>
#include <string>

class save_manager {
    private:

    public:
        static bool save_game(const save_data& data, const std::string& file_name = "save.txt"); 
        static bool load_game(save_data& data, const std::string& filename = "save.txt");

};

#endif