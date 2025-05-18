# -------------------------
# Makefile configuration
# -------------------------

#Declare compiler
CXX = g++

#Flags (C++20 modern version, -W... for warnings)
CXXFLAGS = -std=c++20 -Wall -Wextra

#Linker flags (SFML since using SFML libraries)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# -------------------------
# Files
# -------------------------

#Source files and output file for project
SRC = main.cpp Game.cpp Player.cpp Object.cpp Platform.cpp Level_Loader.cpp Level.cpp Menu.cpp Obstacle.cpp Spike.cpp Water.cpp Lava.cpp One_Way_Platform.cpp Jump_Pad.cpp save_data.cpp save_manager.cpp Collectable.cpp Sun.cpp Heart.cpp Story_Screen.cpp
OUT = test1.out

# -------------------------
# Targets
# -------------------------

windows:
	@echo "Compiling for Windows"
	@g++ $(SRC) -o $(OUT) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	@./$(OUT)

mac:
	@echo "Compiling for macOS"
	@g++ -std=c++20 -I/opt/homebrew/opt/sfml@2/include $(SRC) -o $(OUT) -L/opt/homebrew/opt/sfml@2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	@./$(OUT)


# -------------------------
# Debugging
# -------------------------

debug: CXXFLAGS += -g - DDEBUG