CXX = g++
CXXFLAGS = -std=c++17 -Wsign-compare -Wall -O3 -Wsign-compare

# Directories
SRC_DIR = src
MMH3_DIR = mmh3
BIN_DIR = bin

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Target executable
TARGET = $(BIN_DIR)/yacht_train

# Default target
all: $(TARGET)

# Create the bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# build the object files
$(OBJ_FILES): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -lz

# build the target executable
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(TARGET)

# clean up
clean:
	rm -f $(OBJ_FILES) $(TARGET)