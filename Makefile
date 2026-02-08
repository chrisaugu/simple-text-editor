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


# CC = cl
# CFLAGS = /EHsc
# TARGET = myProgram.exe
# SOURCES = main.cpp helper.cpp

# $(TARGET): $(SOURCES)
#     $(CC) $(CFLAGS) $(SOURCES) /Fe:$(TARGET)


# Compiler and flags
CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

# Target executable name
TARGET   := myprogram

# Source and object files
SRCS := main.cpp utils.cpp
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Remove everything and rebuild
rebuild: clean all

# Mark targets that are not files
.PHONY: all clean rebuild


# Example Makefile
CC = gcc
CFLAGS = -Wall -g
all: main
main: main.o utils.o
   $(CC) $(CFLAGS) -o main main.o utils.o
%.o: %.c
   $(CC) $(CFLAGS) -c $< -o $@
clean:
   rm -f *.o main