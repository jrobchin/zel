CXX = g++
CXXFLAGS = -g -std=c++11 -I../src
LDFLAGS = -lSDL2 -lSDL2_image -lGLEW -lGLU -lGL

PROJ_OBJECTS = $(shell find ../src -type f -name '*.o' -and ! -name 'main.o')

TEST_SOURCES = $(shell find -type f -name '*Tests.cpp' -exec basename {} \;)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

EXE = tests

all: $(EXE)

run: $(EXE)
	./tests $(TEST_ARGS)

$(EXE): $(PROJ_OBJECTS) $(TEST_OBJECTS)
	@echo Linking tests...
	$(CXX) $(CXXFLAGS) $(PROJ_OBJECTS) $(TEST_OBJECTS) -o $(EXE) $(LDFLAGS)

%.o:%.cpp
	@echo Compiling tests...
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o tests