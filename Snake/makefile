CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS := -pthread

SRC_FILES := src/config.cpp src/console_view.cpp src/controller.cpp \
             src/game_objects.cpp src/main.cpp src/model.cpp

OBJ_FILES := $(patsubst src/%.cpp,obj/%.o,$(SRC_FILES))

TARGET := snake_game

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<

obj:
	mkdir -p obj

clean:
	rm -rf obj $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run