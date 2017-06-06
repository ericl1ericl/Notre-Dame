sudoku: main.o sudoku.o
	g++ -std=c++11 main.o sudoku.o -o sudoku

main.o: main.cpp sudoku.h
	g++ -std=c++11 -c main.cpp -o main.o

sudoku.o: sudoku.cpp sudoku.h
	g++ -std=c++11 -c sudoku.cpp -o sudoku.o

clean:
	rm *.o
	rm sudoku
