


CXX=clang++
# or use CXX=g++

all: rugfit1 rugfit2

rugfit1: rugfit1.o
	${CXX} rugfit1.o -o rugfit1

rugfit1.o: rugfit1.cpp
	${CXX} rugfit1.cpp -c 

rugfit2.o: rugfit2.cpp Rectangle.h
	${CXX} rugfit2.cpp -c

Rectangle.o: Rectangle.cpp Rectangle.h
	${CXX} Rectangle.cpp -c


rugfit2: rugfit2.o Rectangle.o
	${CXX} rugfit2.o Rectangle.o -o rugfit2

clean:
	/bin/rm -f *.o rugfit1 rugfit2

