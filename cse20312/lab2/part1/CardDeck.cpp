// Eric Layne
// CSE20312
// CardDeck.cpp

#include <iostream>
#include "CardDeck.h"
#include <stdlib.h>

using namespace std;

CardDeck::CardDeck(int n) {
   size = n; // sets deck size to specified value
   values = new int[size]; // creates size many cards
   for (int i = 0; i < size; i++) { // initialize cards
      values[i] = i;
   }
}

CardDeck::~CardDeck() {
   delete [] values;
}

int CardDeck::getSize() { // number of cards in deck
   return size;
}

void CardDeck::shuffle() {
   for (int i = size-1; i >= 1; i--) { // Knuth's algorithm
      int j = rand() % i;
      int x = values[i];
      values[i] = values[j];
      values[j] = x;
   }
}

ostream& operator<< (ostream &s, CardDeck &r) { // overloaded output
   int size = r.getSize(); // get size of deck
   s << r.values[0]; // display first card
   for (int i = 1; i < size ; i++) { // display rest of cards
      s << ',' << (r.values[i]);
   }
   s << '\n';
   return s;
}
