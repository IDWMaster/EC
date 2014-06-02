CFLAGS=-c -Wall
LDFLAGS=-L. -ldl
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=OpenNet
G++=g++
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	g++ --std=c++0x -g $(OBJECTS) $(LDFLAGS) -Wl,-rpath . -o $@
.cpp.o:
	g++ --std=c++0x -g -I../ $(CFLAGS) $< -o $@

