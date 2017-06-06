// Eric Layne
// CSE20312
// main.cpp (sudoku)

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "sudoku.h"

int main() {
   sudoku newboard; // create a board
   string filename; // string to store file name

   cout << "\nEnter name of sudoku file: ";
   cin >> filename;
   cout << endl;
   
   ifstream myfile (filename); // stream in file
   if (!myfile) { // error if no file exists
      cout << "ERROR: error opening file\n";
      return 0;
   }

   int val; // stores number from sudoku board file
   int row, col = 0; // initialize dimension variables
   
   while(myfile >> val) { // stream in all input
      newboard.setval(row, col, val); // set board value to input
      col++; // advance one to the right
      if (col == 9) { // if at end of row...
         col = 0; // ...go back to left side...
         row++; // ...advance down a row
      }
   }
   
   myfile.close(); // close file
   
   newboard.display(); // display original board
   cout << endl;

   int iteration = 0;
   // run until board is solved or 50 iterations
   while ((newboard.sumboard() != 405)&&(iteration != 50)) {
      // for every element
      for (int row = 0; row < 9; row++) {
         for (int col = 0; col < 9; col++) {
            newboard.scanrow(row); // elimination in row
            newboard.scancol(col); // elimination in column
            newboard.scanblock(row,col); // elimination in block
            newboard.singlerow(row); // singleton method on row
            newboard.singlecol(col); // singleton method on column
            newboard.finalval(row,col); // update values
         }
      }
      iteration++;
   }
   newboard.display();
}
