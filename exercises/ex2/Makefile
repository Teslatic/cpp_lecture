all:	compile test checkstyle

ApproximateEulersNumberMain:	ApproximateEulersNumberMain.o ApproximateEulersNumber.o
		g++ -L. -o ApproximateEulersNumberMain ApproximateEulersNumberMain.o ApproximateEulersNumber.o -leuler

ApproximateEulersNumberMain.o : ApproximateEulersNumberMain.cpp
		g++ -c ApproximateEulersNumberMain.cpp

ApproximateEulersNumberTest: ApproximateEulersNumberTest.o
		g++  -L. -o ApproximateEulersNumberTest ApproximateEulersNumberTest.o -lgtest -leuler

ApproximateEulersNumberTest.o: ApproximateEulersNumberTest.cpp
		g++ -c ApproximateEulersNumberTest.cpp

compile: ApproximateEulersNumberMain ApproximateEulersNumberTest

test:
				./ApproximateEulersNumberTest

checkstyle:
				touch .svn
				cpplint *.cpp *.h
				rm .svn
clean:
			rm -rf a.out
			rm -rf ApproximateEulersNumberMain
			rm -rf ApproximateEulersNumberTest
			rm -rf *.o
