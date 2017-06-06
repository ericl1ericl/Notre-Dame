// Eric Layne
// CSE20312
// C4Board.cpp

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "C4Board.h"

using namespace std;

C4Board::C4Board() {
   numcol = 7; // number of columns
   board = new C4Col[numcol]; // array of C4Col arrays (columns and data)
}

C4Board::~C4Board() {
   delete [] board; // deconstructor
}

void C4Board::display() {
   for (int i = 1; i <= numcol; i++) { // top line enumerating columns
      cout << ' ' << i; // displays space then column number
   }
   cout << endl;
   // displays the main portion of the board
   for (int i = board[0].getMaxDiscs() - 1; i >= 0; i--) { // rows
      cout << "|"; // leftmost bar
      for (int j = 0; j < numcol; j++) { // columns
         cout << board[j].getDisc(i); // displays disc (or space)
         cout << "|"; // righthand bar
      }
      cout << endl;
   }
   for (int i = 1; i <= 2*numcol+1; i++) { // bottom line
      cout << "=";
   }
   cout << endl;
 }

void C4Board::play() {
   int playgame = 1; // variable to keep while loop active
   int turn = 1; // records which turn number
   while(playgame) {
      cout << endl;
      display(); // displays the board

      int askvalue; // holds user input
      if (turn%2 == 1) { // player 1's prompt
         cout << "Player 1! (Token 'X')" << endl;
         cout << "Enter 1-7 to add 'X' to a column. Enter -1 to quit.";
      }
      else if (turn%2 == 0) { // player 2's prompt
         cout << "Player 2! (Token 'O')" << endl;
         cout << "Enter 1-7 to add 'O' to a column. Enter -1 to quit.";
      }
      cout << endl << "Please enter your decision: ";

      if (turn%2 == 1) { // player 1, human player
         cin >> askvalue; // user input goes to askvalue
      }
      else if (turn%2 == 0) { // cpu player, plays randomly
         srand (time(NULL));
         askvalue = rand() % numcol + 1;
         cout << askvalue << endl;
      }
      cout << endl;

      if (askvalue == -1) { // quits game
         cout << "Thanks for playing!" << endl << endl;
         break;
      }
      // if input is a valid column
      else if (askvalue == 1 | askvalue == 2 | askvalue == 3 | askvalue == 4 | askvalue == 5 | askvalue == 6 | askvalue == 7) {
         askvalue--; // sets input to array enumeration (0-6)
         if (board[askvalue].isFull() == 1) { // error if column is full
            cout << "ERROR: Column full" << endl;
         }
         else if (board[askvalue].isFull() == 0) { // if column empty
            if (turn%2 == 1) { // disc for player 1
               board[askvalue].addDisc('X');
            }
            else if (turn%2 == 0) { // disc for player 2
               board[askvalue].addDisc('O');
            }
            turn++; // advance a turn
         } 
      }
      else { // if input is an invalid integer
         cout << "ERROR: Invalid input" << endl;
      }
      wincheck(); // function wincheck looks for four-in-a-rows
   }
}

void C4Board::wincheck() {
   int rows = board[0].getMaxDiscs(); // number of rows
   int cols = numcol; // number of columns
   int p1win = 0; // variable if player 1 wins
   int p2win = 0; // variable if player 2 wins
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) { // scans through board
         if (board[j].getDisc(i) == 'X') { // if disc is 'X'
            if (j < cols-3) { // checks rows
               if (board[j+1].getDisc(i) == 'X' & board[j+2].getDisc(i) == 'X' & board[j+3].getDisc(i) == 'X') {
                  p1win = 1; // if true, player 1 wins
               }
            }
            if (i < rows-3) { // checks columns
               if (board[j].getDisc(i+1) == 'X' & board[j].getDisc(i+2) == 'X' & board[j].getDisc(i+3) == 'X') {
                  p1win = 1;
               }
            }
            if (j < cols-3 & i < rows - 3) { // checks up-right diagonal
               if (board[j+1].getDisc(i+1) == 'X' & board[j+2].getDisc(i+2) == 'X' & board[j+3].getDisc(i+3) == 'X') {
                  p1win = 1;
               }
            }
            if (j > 2 & i < rows - 3) { // checks up-left diagonal
               if (board[j-1].getDisc(i+1) == 'X' & board[j-2].getDisc(i+2) == 'X' & board[j-3].getDisc(i+3) == 'X') {
                  p1win = 1;
               }
            }
         }   
         else if (board[j].getDisc(i) == 'O') { // if disc is 'O'
            if (j < cols-3) {
               if (board[j+1].getDisc(i) == 'O' & board[j+2].getDisc(i) == 'O' & board[j+3].getDisc(i) == 'O') {
                  p2win = 1; //if true, player 2 wins
               }
            }
            if (i < rows-3) {
               if (board[j].getDisc(i+1) == 'O' & board[j].getDisc(i+2) == 'O' & board[j].getDisc(i+3) == 'O') {
                  p2win = 1;
               }
            }
            if (j < cols-3 & i < rows - 3) {
               if (board[j+1].getDisc(i+1) == 'O' & board[j+2].getDisc(i+2) == 'O' & board[j+3].getDisc(i+3) == 'O') {
                  p2win = 1;
               }
            }
            if (j > 2 & i < rows - 3) { 
               if (board[j-1].getDisc(i+1) == 'O' & board[j-2].getDisc(i+2) == 'O' & board[j-3].getDisc(i+3) == 'O') {
                  p2win = 1;
               }
            }
         }   
      }
   }
   if (p1win == 1) {
      cout << "Player 1 wins!" << endl;
   }
   if (p2win == 1) {
      cout << "Player 2 wins!" << endl;
   }    
}
