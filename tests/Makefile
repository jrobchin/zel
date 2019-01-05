CXX = g++
CXXFLAGS = -g -std=c++11 -I../src
LDFLAGS = -lSDL2 -lGLEW -lGLU -lGL

PROJ_OBJECTS = $(shell find ../src -type f -name '*.o' -and ! -name 'main.o')

ifdef test

TEST_SOURCE = $(test).cpp

EXE = $(test).out

run: $(EXE)
	./$(EXE)

$(EXE): $(TEST_SOURCE)
	$(CXX) $(TEST_SOURCE) $(CXXFLAGS) -o $(EXE) $(LDFLAGS)

else

TEST_SOURCES = $(shell find -type f -name '*.cpp' -exec basename {} \;)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

EXES = $(TEST_SOURCES:.cpp=.out)

all: $(EXES)

run: all
	@echo Running tests...
	for exe in $(EXES); do ./$$exe; done

%.out: %.o $(PROJ_OBJECTS)
	@echo Linking tests...
	$(CXX) $(PROJ_OBJECTS) $< -o $@ $(LDFLAGS)

%.o: %.cpp
	@echo Compiling tests...
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o
	rm -f *.out

endif