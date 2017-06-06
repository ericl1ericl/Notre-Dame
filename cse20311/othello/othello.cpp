// Eric Layne
// CSE20311
// life.cpp

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;
#include "othboard.h"

void fadvance(Lifeboard &, Lifeboard &); // function: advance board 1 generation

int main(int argc, char *argv[]) {
   Othboard board; // creates Lifeboard class for current board
   Othboard nextboard; // creates Lifeboard class for next board
   int x, y, z; // variables x,y hold position, z holds error messages
   char key; // used to switch options/cases in interactve mode
   board.display(); // displays board immediately

   if (argc == 1) { // interactive mode
      while (1) { // continuously running
         cout << "enter a command: ";
         cin >> key; // receives user input for choice
         switch(key) { // switches between different input options
            case 'a' : // add living cell
               cout << "enter coordinates to add a live cell: ";
               cin >> x >> y;
               z = board.addC(x, y); // calls on addC method
               system("clear");
               board.display(); // calls display method
               if (z == 0) { // if addC returns 0, user entered invalid point
                  cout << "ERROR: (" << x << "," << y;
                  cout << ") not within boundary" << endl;
               }
               break;
            case 'r' : // remove cell
               cout << "enter coordinates to remove a cell: ";
               cin >> x >> y;
 //              z = board.remC(x, y); // calls on remC method
               system("clear");
               board.display(); // calls display method
               if (z == 0) { // if remC returns 0, user entered invalid point
                  cout << "ERROR: (" << x << "," << y;
                  cout << ") not within boundary" << endl;
               }
               break;
            case 'n' : // advances board 1 generation
               fadvance(board, nextboard); // calls function to advance board
               system("clear");
               board.display();
               break;
            case 'q' : // quits interactive mode
               return 0;
               break;
            case 'p' : // plays game continuously
               while (1) { // infinite while loop
                  fadvance(board, nextboard); // calls function to advance board
                  system("clear");
                  board.display(); // calls display method
                  cout << "press ctrl-C to quit" << endl;
                  usleep(100000); // pauses for 0.1 seconds
               }
               break;
            default : // if user enters invalid command
               cout << "enter a valid command" << endl;
               break;
         }
      }
   }
   else if (argc == 2) { // sees additional file after executable, runs batch mode
      fstream myfile;

      myfile.open(argv[1]); // opens up file

      if (!myfile) { // checks file for existence
         cout << "ERROR: error opening file\n";
         return 0;
      }

      string commands; // string to hold each char in .txt file
      char c; // used to look at next char
      string xin; // string to hold x values
      string yin; // string to hold y values

      c = myfile.peek();

      while (c != EOF) { // while not at end of file
         getline(myfile, commands, ' '); // extracts until ' ' is reached
         if (!(commands.compare("a"))) { // if currently holding 'a'
            getline(myfile, xin, ' '); // next char must be x
            getline(myfile, yin, '\n'); // last char must be y
            int x = stoi(xin); // convert xin to integer
            int y = stoi(yin); // convert yin to integer
            board.addC(x, y); // use addC method to add (xin,yin) to board
         }

         c = myfile.peek(); // checks next character after current line
 
         if (c == 'p') { // if next character is a p
            while (1) { // infinite loop
               fadvance(board, nextboard); // calls function to advance board
               system("clear");
               board.display(); // calls display method
               cout << "press ctrl-C to quit" << endl;
               usleep(100000); // pauses .1 seconds
            }
         }
      }
   }
   else { // if user enters too many files after executable
      cout << "ERROR: too many inputs" << endl;
   }
}

void fadvance(Othboard &board, Othboard &nextboard) { // advances board
   for (int x = 0; x <= 39; x++) { // checks all x within border
      for (int y = 0; y <= 39; y++) { // checks all y within border
         int pos = board.isState(x, y); // recieves (x,y)'s next state
         if (pos == 0) { // if (x,y) should die
//            nextboard.remC(x, y); // remove (x,y) to nextboard
         }
         else if (pos == 1) { // if (x,y) should live
            nextboard.addC(x, y); // add (x,y) to nextboard
         }
      }
   }
   board = nextboard; // because nextboard is board's next state, return the next state as board
}
