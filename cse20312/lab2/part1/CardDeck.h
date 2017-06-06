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
      int getSize();		// gets deck size
      void shuffle();      	// shuffles deck

   private:
      int size;			// deck size
      int* values;		// holds card value

};

#endif
