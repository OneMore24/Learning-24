CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include
TARGET = array.exe
SRCS = src/array.cpp src/main.cpp
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
	@if exist src\*.o del src\*.o 2>nul
	@if exist obj\*.o del obj\*.o 2>nul

.PHONY: all run clean