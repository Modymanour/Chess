CXX = g++
CXXFLAGS = -g -I src/Headers
SRCS = $(wildcard src/*.cpp src/Pieces/*.cpp src/board/*.cpp)
TARGET = build/main.exe

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

.PHONY: clean
clean:
	if exist build\main.exe del /Q build\main.exe