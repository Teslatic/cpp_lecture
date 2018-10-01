all: compile test checkstyle clean

approx_pi_main: approx_pi_main.o approx_pi.o
		g++ -o approx_pi_main approx_pi_main.o approx_pi.o

approx_pi_main.o: approx_pi_main.cpp approx_pi.h
		g++ -c approx_pi_main.cpp

approx_pi.o: approx_pi.cpp
		g++ -c approx_pi.cpp

approx_pi_main_test.o:
		g++ -c approx_pi_main_test.cpp

approx_pi_main_test: approx_pi_main_test.o
		g++ -L. -o approx_pi_main_test approx_pi_main_test.o -lgtest -lpi

compile: approx_pi_main approx_pi_main_test

execute:
		./approx_pi_main

test:
		./approx_pi_main_test

checkstyle:
		touch .svn
		cpplint *.cpp *.h
		rm -f .svn

clean:
		rm -rf a.out
		rm -rf approx_pi_main
		rm -rf approx_pi_main_test
		rm -rf *.o
