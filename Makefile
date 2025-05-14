#Source files and output file for project
SRC = main.cpp Game.cpp Player.cpp Object.cpp Platform.cpp Level.cpp
OUT = test1.out

# For windows systems
windows:
	@echo "Compiling for Windows"
	@g++ $(SRC) -o $(OUT) -lsfml-graphics -lsfml-window -lsfml-system
	@./$(OUT)

# For macOS systems
mac:
	@echo "Compiling for macOS"
	@g++ -std=c++20 -I/opt/homebrew/opt/sfml@2/include $(SRC) -o $(OUT) -L/opt/homebrew/opt/sfml@2/lib -lsfml-graphics -lsfml-window -lsfml-system
	@./$(OUT)
