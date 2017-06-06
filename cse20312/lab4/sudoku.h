// Eric Layne
// CSE20312
// sudoku.h

#ifndef sudoku_h
#define sudoku_h
#include <iostream>
#include <vector>
using namespace std;

class sudoku {
   public:
      sudoku(); // constructor
      ~sudoku();
      void setval(int, int, int); // set display value
      int getval(int, int); // get position display value
      void display(); // display board
      void finalval(int, int); // sets value if one option left
      void scanrow(int); // elimination on row
      void scancol(int); // elimination on column
      void scanblock(int, int); // elimination on 3x3 grid
      int sumboard(); // adds up board to see if solved
      void singlerow(int); // singleton method on row
      void singlecol(int); // singleton method on column
   private:
      vector<vector<vector<int>>> board; // 3D vector for board
					 // first two dimensions for board
					 // third dimension for values
};

#endif
