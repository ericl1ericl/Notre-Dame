#include <iostream>
using namespace std;

int main() {
   char board [64];
   int x = 1;
   while(x == 1) {      
      int a = 0;
      int countdot = 0;
      for (int i = 0; i <= 63; i++) {
         cin >> a;
         if (a == '.') {
            countdot++;
         }
         board[i] = a;
      }

      if (countdot == 64) { 
         x = 0;
      }
      else {
         countdot = 0;
      }

//   int count = 0;
//   for (int i = 0; i <= 63; i++) {
//      cout << board[i];
//      count++;
//      if (count == 8) {
//         cout << endl;
//         count = 0;
//      }      
// }

   int blackking;
   int whiteking;

   int whitekillboard [64];
   int whitecount = 0;
   for (int i = 0; i <= 63; i++) {
      whitekillboard[i] = 0;
      cout << whitekillboard[i];
      whitecount++;
      if (whitecount == 8) {
         cout << endl;
         whitecount = 0;
      } 
   }

   int blackkillboard [64];
   int blackcount = 0;
   for (int i = 0; i <= 63; i++) {
      blackkillboard[i] = 0;
      cout << blackkillboard[i];
      blackcount++;
      if (blackcount == 8) {
         cout << endl;
         blackcount = 0;
      } 
   }

   for (int i = 0; i <= 63; i++) {
      int x;
      int z = 0;
      switch (board[i]) {
         case 'p':
            blackkillboard[i+7] = 1;
            blackkillboard[i+9] = 1; 
            break;
         case 'P':
            whitekillboard[i-9] = 1;
            whitekillboard[i-7] = 1;
            break;
         case 'n':
            cout << "knight" << endl;
            break;
         case 'N':
            break;
         case 'b':
            break;
         case 'B':
            break;
         case 'r':
            x = (i+1)%8;
            while (x <= 64) {
               x = x + 8;
               blackkillboard[x-1] = 1;
            }
            while (x >= 1) {
               x = x - 8;
               blackkillboard[x-1] = 1;
            }
            x = (i+1)%8;
            x = i - x;
            while (z <= 8) {
               blackkillboard[x+z-1] = 1;
               z++;
            }
            break;
         case 'R':
            break;
         case 'q':
            break;
         case 'Q':
            break;
         case 'k':
            break;
         case 'K':
            break;
         default:
            ;       
         }
   }
   return 0;
}
}
