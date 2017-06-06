// Eric Layne
// CSE 20311
// Crossword Anagram

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct spotinfo { //holds info on specific spots
   char letter; //holds letter
   int row; //holds row
   int col; //holds column
   int ort; //holds orientation
   int free; //holds number of free spaces
   int pos; //holds the position of the letter within the word
};

spotinfo make_spotinfo(char&, int&, int&, int&, int&, int&);

struct wordinfo { //holds info on certain words
   string word;
   int row;
   int col;
   int ort;
};

wordinfo make_wordinfo(string&, int&, int&, int&);

int main() {
   cout << "ANAGRAM CROSSWORD PUZZLE GENERATOR" << endl;
   cout << "----------------------------------" << endl;

   cout << endl << "enter a list of words:" << endl;

   list<string> words;
   string x;
   int countwords = 1;

   while ((countwords < 21) && (x != ".")){ //gets words
      cout << setw(3) << right << fixed << countwords;
      cout << ". ";
      cin >> x;
      if ((x.size() <= 15) && (x != ".")) { //valid word added to list
         words.push_back (x);
         countwords++;
      }
      else if (x != ".") { //displays if not under 15 chars and is not .
         cout << "ERROR: 15 characters or less" << endl;
      }
   }

   list<string> sortwords; // list to hold sorted words by length
   for (auto it = words.begin(); it != words.end(); it++) {
      auto sw = sortwords.begin();
      while ((*it).size() < (*sw).size() && sw != sortwords.end()) {
         ++sw;
      }
      if (sw == sortwords.end()) {
         sortwords.push_back(*it);
      }
      else {
         sortwords.insert(sw, *it);
      }
   }

   char board[15][15]; //initialize board
   for (int row = 0; row < 15; row++) {
      for (int col = 0; col < 15; col++) {
         board[row][col] = '.';
      }
   }
   
   cout << endl << "SOLUTION:" << endl << endl;

   auto it = sortwords.begin();
   int strlength = (*it).size();
   int y = (15 - strlength)/2; //used to center first word
   for (int i = 0; i < strlength; i++) {//puts word on board
      char c = (char) (*it)[i];
      c = toupper(c);
      board[7][i+y] = c;     
   }
   int initialrow = 7;
   int initialort = 0; //first word always horizontal
   list<wordinfo> wordinfo; //stuct holding info on word
   wordinfo.push_back(make_wordinfo((*it), initialrow, y, initialort));

   it++; // next word

   for (it = it; it != sortwords.end(); it++) { //for the rest of the words
      strlength = (*it).size();
      list<spotinfo> matches;//list to hold info on spots that have matching chars
      for (int i = 0; i < strlength; i++) { //breaks up string into chars
         char c = (char) (*it)[i];
         c = toupper(c);
         for (int row = 0; row < 15; row++) { //searches through board
            for (int col = 0; col < 15; col++) {
               if (c == board[row][col]) { //if board has matching char
                  int freevert = 0; //will hold free vertical spaces
                  int freehorz = 0; //will hold free horizontal spaces
                  int check = 1;
                  int rowcheck = row; //will move up/down rows
                  int colcheck = col; //will move up/down columns
                  while (check) { //checks for empty spaces
                     rowcheck++;
                     if (board[rowcheck][col] == '.') {
                        freevert++;
                     }
                     else {
                        check = 0;
                     }
                  }
                  check = 1;
                  rowcheck = row;
                  while (check) {
                     rowcheck--;
                     if (board[rowcheck][col] == '.') {
                       freevert++;
                     }
                     else {
                        check = 0;
                     }
                  }
                  check = 1;
                  colcheck = col + 1;
                  while (check) {
                     if (board[row][colcheck] == '.') {
                        freehorz++;
                     }
                     else {
                        check = 0;
                     }
                     colcheck++;
                     if (colcheck == 15) {
                        check = 0;
                     }
                  }
                  check = 1;
                  colcheck = col - 1;
                  while (check) {
                     if (board[row][colcheck] == '.') {
                        freehorz++;
                     }
                     else {
                        check = 0;
                     }
                     colcheck--;
                     if (colcheck == -1) {
                        check = 0;
                     }
                  }
                  
                  if (freevert >= freehorz) { //more empty vertical
                     int ort = 1; //sets orientation vertical
                     int free = freevert;
                     matches.push_back(make_spotinfo(c, row, col, ort, free, i));                    
                  }
                  else if (freevert < freehorz) { //more empty horizontal
                     int ort = 0; //sets orientation horizontal
                     int free = freehorz;
                     matches.push_back(make_spotinfo(c, row, col, ort, free, i));
                  }
  
               }      
            }
         }
      }  

    
         int ifree = 0; //initializing some variables
         int irow = 0;
         int icol = 0;
         int iort;
         char iletter;
         int ipos;
         // loop runs through all the matching positions for a given word
         for (auto ma = matches.begin(); ma != matches.end(); ma++) {

// BELOW IS AN ATTEMPT TO SEPARATE WORDS BY A BLANK SPACE
//            int countdots = 0;
//            for (int i = -1; i = 1; i++) {
//               for (int j = -1; j = 1; j++) {
//                  if (board[(*ma).row+i][(*ma).col+j] == '.') {
//                     countdots++;
//                  }
//               }
//            }

            // finds matching position with most free space and gets
            // its attributes
            if ((*ma).free > ifree && (*ma).free < 15) {
               ifree = (*ma).free; 
               irow = (*ma).row;
               icol = (*ma).col;
               iort = (*ma).ort;
               iletter = (*ma).letter;
               ipos = (*ma).pos;
            }
         }
         // puts attributes into list of wordinfo struct
         wordinfo.push_back(make_wordinfo((*it), irow, icol, iort));
         int isplaced = 1;
         while (isplaced) { //runs until word is placed
            if (iort == 1) { //if word should be vertical
               if (board[irow][icol] == toupper(iletter)) { 
                  if ((irow + strlength) <= 15) { //makes sure word will fit
                     for (int i = 0; i < strlength; i++) {
                        char c = (char) (*it)[i];
                        c = toupper(c);
                        board[irow+i-ipos][icol] = c; //puts word in right spot
                        isplaced = 0; //word placed
                     }
                  }
               }
            }
            else if (iort == 0) { // if word should be horizontal
               if (board[irow][icol] == toupper(iletter)) { 
                  if ((icol + strlength) <= 15) {
                     for (int i = 0; i < strlength; i++) {
                        char c = (char) (*it)[i];
                        c = toupper(c);
                        board[irow][icol+i-ipos] = c;
                        isplaced = 0;
                     }
                  }
               }
            }
            else {
               cout << "ERROR: " << (*it) << " cannot be placed" << endl;
               isplaced = 0;
            }
         }  
      }
                        
   for (int row = 0; row < 15; row++) { //displays board
      for (int col = 0; col < 15; col++) {
         cout << board[row][col];
      }
      cout << endl;
   }

   cout << endl << "CROSSWORD:" << endl << endl;

   for (int row = 0; row < 15; row++) { //displays blank board
      for (int col = 0; col < 15; col++) {
         if(isalpha(board[row][col])) {
            cout << " ";
         }
         else {
            cout << "#";
         }
      }
      cout << endl;
   }

   cout << endl << "CLUES:" << endl << endl;

   //displays clues
   for (auto it = wordinfo.begin(); it != wordinfo.end(); it++) {
      cout << (*it).row << ", " << (*it).col << " ";//row, column
      if ((*it).ort == 1) {//displays orientation
         cout << "DOWN ";
      }
      else {
         cout << "ACROSS ";
      }
      
      //shuffles and capitalizes words
      string stringx = (*it).word;      
      random_shuffle(stringx.begin(), stringx.end());
      int strlength = stringx.size();
      for (int i = 0; i <= strlength; i++ ) { //capitalization
         char c = stringx[i];
         c = toupper(c);
         cout << c;
      }
      cout << endl;
   }
    
   return 0;   
}

spotinfo make_spotinfo(char& letter, int& row, int& col, int& ort, int& free, int& pos) {
   spotinfo x;
   x.letter = letter;
   x.row = row;
   x.col = col;
   x.ort = ort;
   x.free = free;
   x.pos = pos;
   return x;
}

wordinfo make_wordinfo(string& word, int& row, int& col, int& ort) {
   wordinfo x;
   x.word = word;
   x.row = row;
   x.col = col;
   x.ort = ort;
   return x;
}
