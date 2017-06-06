// Eric Layne
// CSE20311
// lifeboard.cpp

#include <iostream>
using namespace std;
#include "othboard.h"

int board_size = 8;

Othboard::Othboard() // creates board and border
{ 
   for (int row = 0; row < board_size; row++) { // 42 rows so that two can be border
      for (int col = 0; col < 42; col++) { // 42 columns 
         if (row == 0 || row == 41) { // border of "#"
            board[row][col] = '#';
         }
         else if (col == 0 || col == 41) { // border of "#"
            board[row][col] = '#';
         }
         else { // inside border
            board[row][col] = ' ';
         }
       
      }
   }
}

Othboard::~Othboard()
{ }

void Othboard::display() // displays everything, including border
{
   for (int row = 0; row < 42; row++) {
      for (int col = 0; col < 42; col++) {
         cout << board[row][col];       
      }
   cout << endl;
   }
}

int Othboard::addC(int x, int y) // replaces cell with live space
{
   x++; // changes x so valid user inputs of 0-39 affect positions 1-40 on board
   y++; // changes y so valid user inputs of 0-39 affect positions 1-40 on board
   if ((x < 41) && (x >= 1) && (y < 41) && (y >= 1)) { // checks if in boundary
      board[y][x] = 'X'; // replaces cell with live space
   }
   else {
      return 0; // prompts main to display error
   }
}

int Othboard::changeC(int x, int y)

int Othboard::isState(int x, int y) // returns if (x,y) should be dead or alive
{
   x++; // changes x so valid user input of 0-39 affect positions 1-40 on board
   y++; // changes y so valid user input of 0-39 affect positions 1-40 on board
   int nAlive = 0; // number of living cells around (x,y) is 0 before count
   for (int i = -1; i <= 1; i++) { // in 3x3 grid around (x,y), loop rows
      for (int j = -1; j <= 1; j++) { // loop columns
         if (((x+i) < 41) && ((x+i) >= 1) && ((y+j) < 41) && ((y+j) >= 1)) {
            if (board[y+j][x+i] == 'X') { // if cell being checked is alive
               nAlive = nAlive + 1; // add one to count of living cells by (x,y)
            }
         }
      }
   }
   if (board[y][x] == 'X') { // since loop above checks (x,y) as a point...
      nAlive = nAlive - 1; // ...remove (x,y) from living count if alive
   }

   if (nAlive == 3) { // parameter: if exactly 3 living cells, (x,y) is live
      return 1; // returns 1 as live
   }
   else if ((board[y][x] == 'X') && (nAlive == 2)) { // if (x,y) is alive and has two neighbors living
      return 1; // returns live
   }
   else { // if above two parameters are not met
      return 0; // returns (x,y) should be dead
   }
}  
