
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./source -fsanitize=address -g

# Source files and object files
SRCDIR = source
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=build/%.o)

# Output executable
TARGET = game

# Default rule to build executable
all: $(TARGET)

# Create build directory if missing
build:
	mkdir -p build

# Link object files to create executable
$(TARGET): build $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Compile source files into object files
build/%.o: $(SRCDIR)/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf build $(TARGET)

.PHONY: all clean build
