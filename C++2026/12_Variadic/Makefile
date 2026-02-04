CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./12_Variadic -I./algorithms -I./containers -I./general
TARGET = list.exe
SRCS = main.cpp DemoArray.cpp DemoLists.cpp
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
	@if exist *.txt del *.txt 2>nul
	@if exist algorithms\*.o del algorithms\*.o 2>nul
	@if exist containers\*.o del containers\*.o 2>nul
	@if exist general\*.o del general\*.o 2>nul

.PHONY: all run clean