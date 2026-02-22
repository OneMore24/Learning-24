CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./20_BinaryTree -I./containers -I./general
TARGET = binarytree.exe
SRCS = main.cpp Demos.cpp
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
	@if exist containers\*.o del containers\*.o 2>nul
	@if exist general\*.o del general\*.o 2>nul

.PHONY: all run clean