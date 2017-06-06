// Eric Layne
// CSE20312
// CardMain.cpp

#include "CardDeck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main() {
   srand (time(NULL)); // initialize rand
   CardDeck deck = CardDeck(10); // set deck to ten cards
   cout << deck; // display unshuffled deck
   deck.shuffle(); // shuffle deck
   cout << deck; // display shuffled deck
}
