// Eric Layne
// CSE20312
// CardDeck.cpp

#include <iostream>
#include "CardDeck.h"
#include <stdlib.h>

using namespace std;

CardDeck::CardDeck(int n) { // runs when a new deck called
   size = n; // deck is called size
   values = new int[size]; // creates size many cards
   int x; // for holding card value
   for (int i = 0; i < 13; i++) { // ranks of cards
      if (i + 1 == 1) { // make aces equal eleven
         x = 11;
      }
      if (i + 1 >= 10) { // make 10s and face cards equal ten
         x = 10;
      }
      else {
         x = i + 1; // make other cards their value
      }
      values[i] = x; // four different suits
      values[i+13] = x; // suit 2
      values[i+26] = x; // suit 3
      values[i+39] = x; // suit 4
   }
}

CardDeck::~CardDeck() {
   delete [] values;
}

int CardDeck::getSize() { // returns deck size
   return size;
}

void CardDeck::shuffle() { // shuffles deck
   for (int i = size-1; i >= 1; i--) {
      int j = rand() % i;
      int x = values[i];
      values[i] = values[j];
      values[j] = x;
   }
}

int CardDeck::deal() {
   int x = size - 1; // array values shifted one down
   int cardval = values[x]; // gets value of top card
   values[x] = 0; // sets top card to zero
   size = size - 1; // reduces deck size by one ("remove" top card)
   return cardval; // return value of top card
}

ostream& operator<< (ostream &s, CardDeck &r) {
   int size = r.getSize();
   s << r.values[0];
   for (int i = 1; i < 52 ; i++) {
      s << ',' << (r.values[i]);
   }
   s << '\n';
   return s;
}
