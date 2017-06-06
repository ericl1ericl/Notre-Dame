CardDeck: CardMain.o CardDeck.o
	g++ CardMain.o CardDeck.o -o CardDeck

CardMain.o: CardMain.cpp CardDeck.h
	g++ -c CardMain.cpp -o CardMain.o

CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -c CardDeck.cpp -o CardDeck.o

clean:
	rm *.o
	rm CardDeck

