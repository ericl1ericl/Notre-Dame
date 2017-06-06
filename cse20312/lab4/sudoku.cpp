// Eric Layne
// CSE20312
// sudoku.cpp

#include <iostream>
#include <vector>
#include "sudoku.h"

using namespace std;

// constructor
sudoku::sudoku() {
   board = vector<vector<vector<int>>> (9, vector<vector<int>>(9, vector<int>(10, 0))); // initialize board, all options to 0
          // 0 means option still available, 1 means option unavailable
}

// destructor
sudoku::~sudoku() {
}

// sets the display value of board
void sudoku::setval(int row, int col, int val) {
   board[row][col][0] = val; // display value for board
   if (val != 0) { // if val is a final number
      for (int i = 1; i <= 9; i++) { // iterate through all options
         if (i != val) { // deactivate all other options
            board[row][col][i] = 1; // 0 is active, 1 is deactive
         }
      }
   }
}

// returns the display value of a location
int sudoku::getval(int row, int col) {
   return board[row][col][0]; // 0 position in options is displayed
}

// display board
void sudoku::display() {
   for(int row = 0; row < 9; row++) { // iterate through all positions
      for(int col = 0; col < 9; col++) {
         cout << ' ' << getval(row, col); // displays
         if (((col+1) == 3) || ((col+1) == 6)) { // nice formatting
            cout << " |";
         }
      }
      if (((row+1) == 3) || ((row+1) == 6)) {
         cout << endl;
         for (int i = 0; i < 23; i++) {
            if ((i == 7) || (i == 15)) {
               cout << '+';
            }
            else {
               cout << '-';
            }
         }
      }
      cout << endl;
   }
}

// sets display value if only one option left
void sudoku::finalval(int row, int col) {
   int countzero = 0; // counts available options
   int zerospot; // stores value of option
   if (getval(row, col) == 0) { // if location is not finalized
      for(int i = 1; i <= 9; i++) { // iterate through all options
         if (board[row][col][i] == 0) { // if an option is viable
            countzero++;
            zerospot = i; // store the number
         }
      }
      if (countzero == 1) { // if there is only one viable option
         setval(row, col, zerospot); // set display value to that option
      }
   }
}

// elimination process on row
void sudoku::scanrow(int row) {
   int value;
   for (int i = 0; i < 9; i++) { // iterate through each element in row
      value = getval(row, i); // get display value
      if (value != 0) { // if number is not zero (to eliminate in others)
         // eliminate in elements to the left
         for (int col = i-1; col >= 0; col--) {
            board[row][col][value] = 1; // deactivate option in cell
         }
         // eliminate in elements to the right
         for (int col = i+1; col < 9; col++) {
            board[row][col][value] = 1; // deactivate option
         }
      }
   }
}

// elimination process on column
void sudoku::scancol(int col) {
   int value;
   for (int i = 0; i < 9; i++) { // iterate through column element
      value = getval(i, col); // get display value
      if (value != 0) { // if number is not zero (to eliminate in others)
         // eliminate in elements above
         for (int row = i-1; row >= 0; row--) {
            board[row][col][value] = 1; // deactivate option
         }
         // eliminate in elements below
         for (int row = i+1; row < 9; row++) {
            board[row][col][value] = 1; // deactivate option
         }
      }
   }  
}

// elimination process on 3x3 grid
void sudoku::scanblock(int row, int col) {
   int value = getval(row, col); // get display value
   if (value != 0) { // if it is a number
      // moves to top left of 3x3 grid
      if ((col == 8)||(col == 5)||(col == 2)) { // 3rd column to 1st
         col = col - 2;
      }
      else if ((col == 7)||(col == 4)||(col == 1)) { // 2nd column to 1st
         col = col - 1;
      }
      if ((row == 8)||(row == 5)||(row == 2)) { // 3rd row to 1st
         row = row - 2;
      }
      else if ((row == 7)||(row == 4)||(row == 1)) { // 2nd row to 1st
         row = row - 1;
      }
      for (int i = row; i <= row+2; i++) { // iterate through 3x3
         for (int j = col; j <= col+2; j++) {
            if (getval(i, j) == 0) { // if not finalized
               board[i][j][value] = 1; // turn off existing value
            }
         }
      }
   }
}

// sums board (to see if the output is 405, or solved)
int sudoku::sumboard() {
   int sum = 0;
   for (int row = 0; row < 9; row++) { // iterate through elements
      for (int col = 0; col < 9; col++) {
         sum = sum + board[row][col][0]; // add them up
      }
   }
   return sum;
}

// singleton method on row
void sudoku::singlerow(int row) {
   int countvalue = 0; // tracks number of times a number is an option
   int colspot; // tracks location of where the number is the only option
   for (int i = 1; i <= 9; i++) { // for each number option
      for (int col = 0; col < 9; col++) { // for each element of row
         scanblock(row, col);
         finalval(row, col);
         scanrow(row);
         finalval(row, col);
         if (getval(row, col) == 0) { // if not finalized
            if (board[row][col][i] == 0) { // if number is an option
               countvalue++; // increase number of times is option
               colspot = col; // stores location
            }
         }
      }
      if (countvalue == 1) { // if number is only an option in one spot
         for (int q = 1; q <= 9; q++) { // iterate through options
            if (q != i) { // for options not the singleton
               board[row][colspot][q] = 1; // deactivate
            }
         }
         setval(row, colspot, i); // display the singleton
      }
      countvalue = 0; // reset for next number option
   }
}

// singleton method on column, same logic as singlerow
void sudoku::singlecol(int col) {
   int countvalue = 0;
   int rowspot;
   for (int i = 1; i <= 9; i++) {
      for (int row = 0; row < 9; row++) {
         scanblock(row, col);
         finalval(row, col);
         scancol(col);
         finalval(row, col);
         if (getval(row, col) == 0) {
            if (board[row][col][i] == 0) {
               countvalue++;
               rowspot = row;
            }
         }
      }
      if (countvalue == 1) {
         for (int q = 1; q <= 9; q++) {
            if (q != i) {
               board[rowspot][col][q] = 1;
            }
         }
         setval(rowspot, col, i);
      }
      countvalue = 0; 
   }
}

