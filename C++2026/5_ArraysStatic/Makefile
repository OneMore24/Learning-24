CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./5_Arrays
TARGET = Arr.exe
SRCS = Array.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	@if exist $(TARGET) del $(TARGET) 2>nul
	@if exist *.o del *.o 2>nul

.PHONY: all run clean