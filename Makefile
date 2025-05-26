# -------------------------
# Makefile configuration
# -------------------------

#Includes 
INCLUDES = -ISrc

#SFML path for macOS
SFML_INCLUDE = -I/opt/homebrew/opt/sfml@2/include
SFML_LIB = -L/opt/homebrew/opt/sfml@2/lib

#Declare compiler
CXX = g++

#Flags (C++20 modern version, -W... for warnings)
CXXFLAGS = -std=c++20 #-Wall -Wextra

#Linker flags (SFML since using SFML libraries)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#Check OS
ifeq ($(OS),Windows_NT)
	CLEAR = cls
else
	CLEAR = clear
endif

# -------------------------
# Files
# -------------------------

#Tells compiler where to find source files and output file for project
SRC = $(wildcard Src/**/*.cpp)
OBJ = $(SRC:.cpp=.o)
OUT = game.out

# -------------------------
# Unit testing
# -------------------------

#Unit test
TEST_SRC = $(wildcard Unit_Tests/*.cpp)
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_OUT = tests.out

$(TEST_OUT): $(TEST_OBJ) $(filter-out Src/main.o, $(OBJ))
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) $(filter-out Src/Main/main.o, $(OBJ)) -o $@ $(LDFLAGS)


#Saves time by only specific .o files related to .cpp changes are recompiled instead of every .cpp
$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDFLAGS)

#Don't have to write separate compile commands for every .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SFML_INCLUDE) -c $< -o $@

# -------------------------
# Targets
# -------------------------

#If you want to see the compile commands during build, remove the "@" infront of the commands

#Incase any files are named the same as the targets below the compiler can differentiate
.PHONY: all clean debug windows mac run

all: $(OUT)

windows: all
	@$(CLEAR)
	@echo "Compiling for Windows"
	@./$(OUT)

mac: CXXFLAGS += $(SFML_INCLUDE)
mac: LDFLAGS += $(SFML_LIB)
mac: all
	@$(CLEAR)
	@echo "Compiling for macOS"
	@./$(OUT)

test: CXXFLAGS += $(SFML_INCLUDE)
test: LDFLAGS += $(SFML_LIB)
test: $(TEST_OUT)
	@$(CLEAR)
	@echo "Unit testing"
	./$(TEST_OUT)


# -------------------------
# Debugging
# -------------------------

debug: CXXFLAGS += -g -DDEBUG
debug: all

## -------------------------
# Clean
# -------------------------

clean:
	@$(CLEAR)
	rm -f $(OUT) $(OBJ) $(TEST_OUT) $(TEST_OBJ)

run: all
	./$(OUT)