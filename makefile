#israelmor555@gmail.com
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCS = SquareMat.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = SquareMatrix

MAIN_SRC = Main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
MAIN_TARGET = Main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

Main: $(MAIN_TARGET)

$(MAIN_TARGET): SquareMat.o $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

clean:
	rm -f *.o $(TARGET) $(MAIN_TARGET)
