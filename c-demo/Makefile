TARGET = connect_db

SRCS = src/simple.cpp

CXX = g++
CXXFLAGS = -std=c++20 -Ifull_deploy/host/nlohmann_json/3.11.3/include

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(CONAN_LIBS)

clean:
	rm -f $(TARGET)

install:
	conan install . --output-folder=build --build=missing

build:
	g++ -o $1 $1.cpp