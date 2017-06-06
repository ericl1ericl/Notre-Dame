ConnectFour: C4Main.o C4Board.o C4Col.o
	g++ C4Main.o C4Board.o C4Col.o -o ConnectFour

C4Main.o: C4Main.cpp C4Board.h C4Col.h
	g++ -c C4Main.cpp -o C4Main.o

C4Board.o: C4Board.cpp C4Board.h C4Col.h
	g++ -c C4Board.cpp -o C4Board.o

C4Col.o: C4Col.cpp C4Col.h
	g++ -c C4Col.cpp -o C4Col.o

clean:
	rm *.o
	rm ConnectFour

