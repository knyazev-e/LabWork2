TARGET_PROJECT = main
TARGET_TEST = test1
CXX = g++
CXXFLAGS = -std=c++17 -I$(GTEST_DIR)/include
LDFLAGS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread


PROJECT_SOURCE = $(wildcard source/*.cpp)
TEST_SOURCE = $(wildcard tests/*.cpp)


PROJECT_OBJECT = $(PROJECT_SOURCE:.cpp=.o)
TEST_OBJECT = $(TEST_SOURCE:.cpp=.o)


all: $(TARGET_PROJECT) $(TARGET_TEST)


$(TARGET_PROJECT): $(PROJECT_OBJECT)
	$(CXX) -o $@ $^


$(TARGET_TEST): $(TEST_OBJECT)
	$(CXX) -o $@ $^ $(LDFLAGS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(PROJECT_OBJECT) $(TEST_OBJECT) $(TARGET_PROJECT) $(TARGET_TEST)


test: $(TARGET_TEST)
	./$(TARGET_TEST)


.PHONY: all clean test
