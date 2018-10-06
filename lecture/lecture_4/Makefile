.PRECIOUS: %.o
.SUFFIXES:
.PHONY: compile test checkstyle clean

CXX = g++
CC_FLAGS = -Wall
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.c=.o)
EXEC = $(filter %Main, $(basename $(wildcard *.cpp)))

all: compile checkstyle

compile: $(OBJECTS)
	$(CXX) $(CC_FLAGS) -o $(EXEC) $^ -lncurses

GameOfLifeMain: GameOfLifeMain.o
	$(CXX) -o GameOfLifeMain GameOfLifeMain.o -lncurses

ArrayAndPointerMain: ArrayAndPointerMain.o
	$(CXX) -o ArrayAndPointerMain ArrayAndPointerMain.o -lncurses

%.o:	%.cpp $(HEADERS)
	$(CXX) -c $<

checkstyle:
	touch .svn
	cpplint *.cpp *.h
	rm .svn

clean:
	rm -rf *.o
	rm -rf *Main
	rm -rf *Test
