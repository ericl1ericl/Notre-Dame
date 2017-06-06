# Makefile for testing the Circle class

runrectangle: testrectangle.o rectangle.o
	g++ testrectangle.o rectangle.o -o runrectangle

testrectangle.o: testrectangle.cpp rectangle.h
	g++ -c testrectangle.cpp -o testrectangle.o

rectangle.o: rectangle.cpp rectangle.h
	g++ -c rectangle.cpp -o rectangle.o

clean:
	rm *.o runrectangle

