#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include "Save/save_data.h"

#include <fstream>
#include <string>

// Class for retrieving and saving data to txt file.
class save_manager
{
private:
public:
    static bool save_game(save_data &data, const std::string &file_name = "save.txt");
    static bool load_game(save_data &data, const std::string &filename = "save.txt");
};

#endif