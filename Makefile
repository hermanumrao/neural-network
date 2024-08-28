# Define compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -g -Og

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
DATA_DIR := data

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(INCLUDE_DIR)/*.cpp)
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Executable
TARGET := neural_network

# Include directories
INCLUDES := -I$(INCLUDE_DIR)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets
.PHONY: all clean

