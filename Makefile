CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./source -I/usr/include/gtest -g
LINKFLAGS = -lgtest -lgtest_main -pthread

SRCDIR = source
TESTDIR = tests

MAIN_OBJ = build/main.o
SOURCES = $(filter-out $(SRCDIR)/main.cpp, $(wildcard $(SRCDIR)/*.cpp))
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=build/%.o)

TESTSOURCES = $(wildcard $(TESTDIR)/*.cpp)
TESTOBJECTS = $(TESTSOURCES:$(TESTDIR)/%.cpp=build/tests_%.o)

TARGET = game
TESTTARGET = unit_tests

all: $(TARGET) $(TESTTARGET)
build:
	mkdir -p build

$(TARGET): build $(MAIN_OBJ) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJ) $(OBJECTS)

build/%.o: $(SRCDIR)/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/main.o: $(SRCDIR)/main.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TESTTARGET): build $(TESTOBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(TESTOBJECTS) $(OBJECTS) $(LINKFLAGS)

build/tests_%.o: $(TESTDIR)/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET) $(TESTTARGET)

.PHONY: all clean build
