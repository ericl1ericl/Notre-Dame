// Eric Layne
// CSE 20311
// ND Football win/loss array program

#include <iostream>
#include <iomanip>
#include "nd_data.h"
using namespace std;

void fcase1(int);
void fcase2();
void fcase3();
void fcase4(int);
void fcase5(int);
void fcase6(int);
void fcase7(int);

int main() {
   int x; // variable defining choices

   while (1) {
      cout << "\n";
      cout << "ND Football win/loss record data." << endl;
      cout << "What would you like to do?" << endl;
      cout << "1: Display record for a given year." << endl;
      cout << "2: Display years with a winning record." << endl;
      cout << "3: Display years with a losing record." << endl;
      cout << "4: Display years with a given number of wins." << endl;
      cout << "5: Display years with a given minimum number of wins." << endl;
      cout << "6: Display years with a given number of losses." << endl;
      cout << "7: Display years with a given maximum number of losses." << endl;
      cout << "0: Exit." << endl;
      cout << "Enter your choice: ";
      cin >> x;

      int val;

      if (x == 0) {
         cout << "Thank you! Go Irish!" << endl;
         cout << "" << endl;
         return 0;
      }
      else if (x == 1) {
         cout << "Enter a year: ";
         cin >> val;
         fcase1(val);
      }
      else if (x == 2) {
         cout << "Years with a winning record:" << endl;
         fcase2();
     }
      else if (x == 3) {
         cout << "Years with a losing record" << endl;   
         fcase3();
     }
      else if (x == 4) {
         cout << "Enter a number of wins: ";
         cin >> val;
         fcase4(val);
     }
      else if (x == 5) {
         cout << "Enter a minimum number of wins: ";
         cin >> val;
         fcase5(val);
      }
      else if (x == 6) {
         cout << "Enter a number of losses: ";
         cin >> val;
         fcase6(val);
      }
      else if (x == 7) {
         cout << "Enter a maximum number of losses: ";
         cin >> val;
         fcase7(val);
      }
      else {
         cout << "ERROR: Invalid response. Please try again." << endl;
      } 
   }
}

// Displays record for a given year
void fcase1(int val) {
      val = val - 1900;
      if (val >= 0) {
         cout << setw(5) << "Wins: " << wins[val];
         cout << setw(10) << "Losses: " << losses[val] << endl;
      }
      else {
      cout << "ERROR: Invalid year" << endl;
      }
}

// Displays years with a winning record
void fcase2() {
   int printcount = 0; // variable for printing years neatly
   int count = sizeof(wins) / sizeof(int); // size of array

   for (int i = 0; i <= count; i++) {
      int avg = (wins[i] + losses[i]) / 2; // calculates games needed for winning                                               season
      if (wins[i] > avg) {
         int year = i + 1900;
         cout << setw(5) << fixed << left << year;
         printcount ++;
         if (printcount==10) { // prints years out neatly, ten per line
            cout << endl;
            printcount = 0;
         }
      }
   }
   cout << endl;
}

// Displays years with a losing record
void fcase3() {
   int printcount = 0; // see explanation in fcase2
   int count = sizeof(losses) / sizeof(int);

   for (int i = 0; i <= count; i++) {
      int avg = (losses[i] + wins[i]) / 2;
      if (losses[i] > avg) {
         int year = i + 1900;
         cout << setw(5) << fixed << left << year;
         printcount ++;
         if (printcount==10) {
            cout << endl;
            printcount = 0;
         }
      }
   }
   cout << endl; 
}

// determines years with x number of wins
void fcase4(int val) {
   if (val < 0) {
      cout << "ERROR: Please enter a nonnegative value" << endl;
   }
   else {
      int printcount = 0;
      int x = 0;
      int count = sizeof(wins) / sizeof(int);

      for (int i = 1; i <= count; i++) {
         if (wins[i] == val) {
            int year = i + 1900;
            cout << setw(5) << fixed << left << year;
            x++;
            printcount ++;
            if (printcount==10) {
               cout << endl;
               printcount = 0;
            }
         }
      }
      cout << endl;
      if (x == 0) {
         cout << "ERROR: No year with given number of wins" << endl;   
      }
   }
}

// determines years with at least x wins
void fcase5(int val) {
   if (val < 0) {
      cout << "ERROR: Please enter a nonnegative value" << endl;
   }
   else {
      int printcount = 0;
      int x = 0;
      int count = sizeof(wins) / sizeof(int);
      for (int i = 1; i <= count; i++) {
         if (wins[i] >= val) {
            int year = i + 1900;
            cout << setw(5) << fixed << left << year;
            x++;
            printcount ++;
            if (printcount==10) {
               cout << endl;
               printcount = 0;
            }
         }
      }
      if (x == 0) {
         cout << "ERROR: No years with at least the given number of wins";
         cout << endl;  
      }
      cout << endl;
   }
}   

// determines years with x losses
void fcase6(int val) {
   if (val < 0) {
      cout << "ERROR: Please enter a nonnegative value" << endl;
   }
   else {
      int printcount = 0;
      int x = 0;
      int count = sizeof(losses) / sizeof(int);
      for (int i = 1; i <= count; i++) {
         if (losses[i] == val) {
            int year = i + 1900;
            cout << setw(5) << fixed << left << year;
            x++;
            printcount ++;
            if (printcount==10) {
               cout << endl;
               printcount = 0;
            }
         }
      }
      cout << endl;
      if (x == 0) {
         cout << "ERROR: No year with given number of losses" << endl;   
      } 
   }
}

// determines years with at most x losses
void fcase7(int val) {
   if (val < 0) {
      cout << "ERROR: Please enter a nonnegative value" << endl;
   }
   else {
      int printcount;
      int x = 0;
      int count = sizeof(losses) / sizeof(int);
      for (int i = 1; i <= count; i++) {
         if (losses[i] <= val) {
            int year = i + 1900;
            cout << setw(5) << fixed << left << year;
            x++;
            printcount ++;
            if (printcount==10) {
               cout << endl;
               printcount = 0;
            }
         }
      }
      if (x == 0) {
         cout << "ERROR: No year with less than the given number of losses";
         cout << endl;   
      }
      cout << endl;
   }
}   

