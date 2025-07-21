CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = text_editor
SOURCES = text_editor.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

# default:
#	clang++ hello_world.cpp -o hello_world.o
# clang++ hello_world.cpp -o hello_world