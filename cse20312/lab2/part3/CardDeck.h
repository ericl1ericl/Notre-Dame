// Eric Layne
// CSE20312
// CardDeck.h

#ifndef CardDeck_h
#define CardDeck_h
#include <iostream>
using namespace std;

class CardDeck {

   friend ostream& operator<<(ostream&, CardDeck&);

   public:
      CardDeck(int = 52);	// constructor
      CardDeck(const CardDeck&);// copy constructor
      ~CardDeck();		// deconstructor
      int getSize();		// returns deck size
      void shuffle();		// shuffles deck
      int deal();     		// deals out one card (removes from
				// deck too)

   private:
      int size;			// size of deck
      int* values;		// holds card values

};

#endif
