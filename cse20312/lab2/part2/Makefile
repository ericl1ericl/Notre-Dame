SWchar: main.o SWchar.o c3po.o r2d2.o luke.o han.o leia.o vader.o
	g++ main.o SWchar.o c3po.o r2d2.o luke.o han.o leia.o vader.o -o SWchar

main.o: main.cpp SWchar.h 
	g++ -c main.cpp -o main.o

SWchar.o: SWchar.cpp SWchar.h
	g++ -c SWchar.cpp -o SWchar.o

c3po.o: c3po.cpp c3po.h
	g++ -c c3po.cpp -o c3po.o

r2d2.o: r2d2.cpp r2d2.h
	g++ -c r2d2.cpp -o r2d2.o

luke.o: luke.cpp luke.h
	g++ -c luke.cpp -o luke.o

han.o: han.cpp han.h
	g++ -c han.cpp -o han.o

leia.o: leia.cpp leia.h
	g++ -c leia.cpp -o leia.o

vader.o: vader.cpp vader.h
	g++ -c vader.cpp -o vader.o

clean:
	rm *.o
	rm SWchar

