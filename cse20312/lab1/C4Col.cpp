// Eric Layne
// CSE20312
// C4Col.cpp

#include<iostream>
#include "C4Col.h"

using namespace std;

C4Col::C4Col() {
   numdiscs = 0; // initialize number of disks in column to 0
   maxdiscs = 6; // maximum disks per column
   discs = new char[maxdiscs]; // array of chars, of size maxdiscs
   for (int i = maxdiscs - 1; i >= 0; i--) {
      discs[i] = ' '; // initialize array to spaces
   }
}

C4Col::~C4Col() {
   delete [] discs; // deconstructor
}

int C4Col::isFull() {
   if (numdiscs == maxdiscs) { // number of discs in column = maxdiscs
      return 1; // true
   }
   else { // any other scenario
      return 0; // false
   }
}

char C4Col::getDisc(int x) { // to get the disc in a certain position
   return discs[x]; // returns a char
}

int C4Col::getMaxDiscs() { // gets maxdiscs
   return maxdiscs;
}

void C4Col::addDisc(char c) { // adds character to column
   discs[numdiscs++] = c; // stacks up on bottom of column
}
