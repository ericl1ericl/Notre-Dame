BLACKJACK: blackjack.o CardDeck.o
	g++ blackjack.o CardDeck.o -o BLACKJACK

blackjack.o: blackjack.cpp CardDeck.h
	g++ -c blackjack.cpp -o blackjack.o

CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -c CardDeck.cpp -o CardDeck.o

clean:
	rm *.o
	rm BLACKJACK

