// Eric Layne
// CSE20312
// blackjack.cpp

#include "CardDeck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

// runs if dealer wins
void dealwin(int&, int&, char, int&, int&, int, int);
// runs if player wins
void playwin(int&, int&, char, int&, int&, int, int);

int main() {
   cout << endl << "Welcome to BLACKJACK!" << endl;
   int dval = 0; // dealer's hand value
   int pval = 0; // player's hand value
   int dwins = 0; // number of dealer wins
   int pwins = 0; // number of player wins
   int playgame = 1; // keeps while loop going
   srand (time(NULL)); // to randomize shuffle
   CardDeck deck = CardDeck(); // create deck of cards
   deck.shuffle(); // shuffle deck
   int x; // variable to hold dealt card value
   int turn = 1; // tracks turns in game (1 is important)
   char choice; // holds user input for decisions

   while(playgame) { // loop runs until user quits
      if (turn == 1) { // automatically do first deal
         cout << endl;
         x = deck.deal(); // first card dealt to dealer
         cout << "Dealer draws: " << x << endl;
         dval = dval + x; // dealer hand value updates
         x = deck.deal(); // card dealt to player
         cout << "Player draws: " << x << endl;
         pval = pval + x; // player hand value updates
      }
      cout << "     Dealer score: " << dval << endl;
      cout << "     Player score: " << pval << endl;
      if (dval > 21 && pval > 21) { // dealer auto win condition
         dwins++; // iterate number of dealer wins
         dealwin(dval, pval, choice, playgame, turn, dwins, pwins);
      }
      else if (pval > 21 || dval == 21) { // dealer auto win condition
         dwins++; // iterate dealer wins
         dealwin(dval, pval, choice, playgame, turn, dwins, pwins);
      }
      else if (((pval > dval) && (dval >= 17) && (pval <= 21)) || pval == 21 || dval > 21) { // player auto win conditions
         pwins++; // iterate player wins
         playwin(dval, pval, choice, playgame, turn, dwins, pwins);
      }
      else { // if no automatic win condition is met
         cout << "HIT (H) or STAND (S)? ";
         cin >> choice; // holds user input
         cout << endl;
         if (tolower(choice) == 'h') { // hit
            if (dval < 17) { // dealer draws if not >= 17
               x = deck.deal();
               cout << "Dealer draws: " << x << endl;
               dval = dval + x;
            }
            else { // if dealer is >= 17
               cout << "Dealer draws: NULL" << endl;
            } 
            x = deck.deal(); // player always draws on hit
            cout << "Player draws: " << x << endl;
            pval = pval + x;
         }
         else if (tolower(choice) == 's') { // stand
            if (dval < 17 && dval < pval) {
               x = deck.deal();
               cout << "Dealer draws: " << x << endl;
               dval = dval + x;
            }
            else {
               cout << "Dealer draws: NULL" << endl;
            } 
            cout << "Player draws: NULL" << endl; // player never
						  // draws on stand
         }
         else { // error message
            cout << "ERROR: INVALID INPUT" << endl;
         }
      }

      // win conditions that occur after decisions
      if (choice == 's' && dval > 21) { // dealer exceeds 21
         pwins++; // player wins
         cout << "     Dealer score: " << dval << endl;
         cout << "     Player score: " << pval << endl;
         playwin(dval, pval, choice, playgame, turn, dwins, pwins);
      }
      else if (choice == 's' && dval >= pval) { // player effectively
						// forfeits hand
         dwins++; // dealer wins
         cout << "     Dealer score: " << dval << endl;
         cout << "     Player score: " << pval << endl;
         dealwin(dval, pval, choice, playgame, turn, dwins, pwins);
      }

      // gets new deck and reshuffles if less than 15 cards
      if (deck.getSize() < 15) {
         cout << endl << "NEW DECK!" << endl << endl;
         deck = CardDeck(52);
         deck.shuffle();
      }
      turn++; // advance to next turn to prevent extra dealing
   }
}

void dealwin(int &dval, int &pval, char choice, int &playgame, int &turn, int dwins, int pwins) {
   cout << "DEALER WINS!" << endl;
   cout << "     Dealer: " << dwins << " | Player: " << pwins << endl;
   cout << "Play again? Yes (Y) or No (N): ";
   cin >> choice; // get user input
   while (1) { // always running
      if (tolower(choice) == 'n') {
         playgame = 0; // user wants to quit, exits main while loop
         break;
      }
      else if (tolower(choice) == 'y') {
         dval = 0; // resets hand values
         pval = 0;
         turn = 0; // so that initial deal occurs
         break;
      }
      else { // error
         cout << "ERROR: INVALID INPUT" << endl;
         cout << "Play again? Yes (Y) or No (N): ";
         cin >> choice; // re prompt user
      }
   }
}

void playwin(int &dval, int &pval, char choice, int &playgame, int &turn, int dwins, int pwins) {
   cout << "PLAYER WINS!" << endl;
   cout << "     Dealer: " << dwins << " | Player: " << pwins << endl;
   cout << "Play again? Yes (Y) or No (N): ";
   cin >> choice;
   while (1) {
      if (tolower(choice) == 'n') {
         playgame = 0;
         break;
      }
      else if (tolower(choice) == 'y') {
         dval = 0;
         pval = 0;
         turn = 0;
         break;
      }
      else {
         cout << "ERROR: INVALID INPUT" << endl;
         cout << "Play again? Yes (Y) or No (N): ";
         cin >> choice;
      }
   }
}
