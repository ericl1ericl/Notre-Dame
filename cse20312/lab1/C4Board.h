// Eric Layne
// CSE20312
// C4Board.h

#ifndef C4Board_h
#define C4Board_h

#include "C4Col.h"

class C4Board {
   public:
      C4Board();	// constructor
      ~C4Board();	// deconstructor
      void display();	// displays the board
      void play();	// plays the game
      void wincheck();	// checks for a win (connect-four)

   private:
      int numcol;	// number of columns
      C4Col* board;	// array of columns (C4Col class)
};

#endif
