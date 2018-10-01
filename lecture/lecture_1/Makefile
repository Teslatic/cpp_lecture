all: compile test checkstyle

compile:
				g++ -o approx_pi_main approx_pi_main.cpp
				g++ -o approx_pi_main_test approx_pi_main_test.cpp -lgtest
test:
				./approx_pi_main_test
checkstyle:
				cpplint *.cpp
clean:
				rm -rf a.out
				rm -rf approx_pi_main
				rm -rf approx_pi_main_test
