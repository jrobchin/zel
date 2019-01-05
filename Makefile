EXE = parkcurse

CXX = g++
CXXFLAGS = -g -std=c++11
LDFLAGS = -lSDL2 -lGLEW -lGLU -lGL

# All source files
SOURCES = $(shell find src -type f -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJECTS)
	@echo Linking...
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)

src/%.o: src/%.cpp
	@echo Compiling...
	$(CXX) $(CXXFLAGS) $< -c -o $@

run: all
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJECTS)
