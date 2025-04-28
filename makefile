CXX = g++
CXXFLAGS = -Wall -std=c++17

# קבצי המקור
SRCS = SquareMat.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)

# שם האובייקט הסופי
TARGET = SquareMatrix

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# הפעלת הטסטים
test: $(TARGET)
	./$(TARGET)

# הרצת ולגרינד
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# ניקוי
clean:
	rm -f $(OBJS) $(TARGET)
