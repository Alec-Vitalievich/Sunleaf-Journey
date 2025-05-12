
Game: Game.cpp Player.cpp Object.cpp Platform.cpp Level.cpp
	@g++ main.cpp Game.cpp Player.cpp Object.cpp Platform.cpp Level.cpp -o test1.out -lsfml-graphics -lsfml-window -lsfml-system
	@./test1.out