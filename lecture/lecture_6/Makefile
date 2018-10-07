# Generic MAkefile
# Tailored to work with 3 different types of files: Main, Test, Playground
.PRECIOUS: %.o
.SUFFIXES:
.PHONY: compile test checkstyle clean

CXX = g++
CC_FLAGS = -g -std=c++11 -Wall -pedantic
VALGRIND = valgrind --leak-check=full
HEADERS = $(wildcard *.h)
MAIN_BIN = $(basename $(wildcard *Main.cpp))
TEST_BIN = $(basename $(wildcard *Test.cpp))
PLAY_BIN = $(basename $(wildcard *Playground.cpp))
OBJECTS = $(addsuffix .o , $(basename $(filter-out %Playground.cpp %Main.cpp %Test.cpp, $(wildcard *.cpp))))
LIBRARIES = -lncurses

all: compile test checkstyle

compile: $(MAIN_BIN) $(TEST_BIN) $(PLAY_BIN)

test: $(TEST_BIN)
	@echo ========================================================================
	@echo TESTING
	for T in $(TEST_BIN); do $(VALGRIND) ./$$T; done

xxx:
	@echo $(MAIN_BIN)
	@echo $(OBJECTS)
	@echo $(filter-out %Main.o %Test.o, $(OBJECTS))
	@echo $(PLAY_BIN)
	@echo $(HEADERS)

%Main: %Main.o	$(filter-out %Playground.o %Test.o, $(OBJECTS))
	@echo ========================================================================
	@echo Praising the Machine God...
	$(CXX) $(CC_FLAGS) -o $@ $^ $(LIBRARIES)

%Test: %Test.o $(filter-out %Playground.o %Main.o, $(OBJECTS))
	@echo ========================================================================
	@echo MAKING TEST
	$(CXX) $(CC_FLAGS) -o $@ $^ $(LIBRARIES) -lgtest -lgtest_main -lpthread

%Playground: %Playground.o $(filter-out %Main.o %Test.o, $(OBJECTS))
	@echo ========================================================================
	@echo MAKING  PLAGROUND
	$(CXX) $(CC_FLAGS) -o $@ $^ $(LIBRARIES)

%.o:	%.cpp $(HEADERS)
	@echo ========================================================================
	$(CXX) $(CC_FLAGS) -c $<

checkstyle:
	@echo ========================================================================
	@echo CHECKSTYLE
	touch .svn
	cpplint *.cpp *.h
	rm .svn

clean:
	@echo ========================================================================
	@echo TAKING OUT THE TRASH
	rm -rf *.o
	rm -rf *Main
	rm -rf *Test
	rm -rf *Playground
