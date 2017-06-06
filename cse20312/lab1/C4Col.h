// Eric Layne
// CSE20312
// C4Col.h

#ifndef C4Col_h
#define C4Col_h

class C4Col {
   public:
      C4Col();			// constructor
      ~C4Col();			// deconstructor
      int isFull();		// checks if column is full of discs
      char getDisc(int);	// extracts disc char in certain position
      int getMaxDiscs();	// returns size of column
      void addDisc(char);	// adds disc of char to lowest open spot

   private:
      int numdiscs;		// number of discs in column
      int maxdiscs;		// max number of discs per column
      char* discs;		// array of spots in column
};

#endif
