.PRECIOUS: %.o
.SUFFIXES:
.PHONY: compile test checkstyle clean

CXX = g++
CC_FLAGS = -Wall
HEADERS = $(wildcard *.h)
SOURCES = $(filter-out %Playground.cpp, $(wildcard *.cpp))
EXEC = $(filter %Main, $(basename $(wildcard *.cpp)))
TESTEXEC = $(filter %Test, $(basename $(wildcard *.cpp)))

all: compile checkstyle

compile: $(filter-out %Test.cpp,$(SOURCES))
	$(CXX) $(CC_FLAGS) -o $(EXEC) $^ -lncurses

test:$(filter-out %Ground.cpp, $(filter-out %Main.cpp,$(SOURCES)))
	$(CXX) $(CC_FLAGS) -o $(TESTEXEC) $^ -lgtest -lgtest_main -lncurses

xxx:
	@echo $(SOURCES)
	@echo $(EXEC)
	@echo $(TESTEXEC)

%.o:	%.cpp $(HEADERS)
	$(CXX) -c $<

checkstyle:
	touch .svn
	cpplint $(SOURCES) $(HEADERS)
	rm .svn

clean:
	rm -rf *.o
	rm -rf *Main
	rm -rf *Test
	rm -rf *Playground
