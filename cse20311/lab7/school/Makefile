
runschools: schoolmain.o school.o
	g++ schoolmain.o school.o -o runschools

schoolmain.o: schoolmain.cpp school.h
	g++ -c -std=c++11 schoolmain.cpp -o schoolmain.o

school.o: school.cpp school.h
	g++ -c school.cpp -o school.o

clean:
	rm *.o runschools

