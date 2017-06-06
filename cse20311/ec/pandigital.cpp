// Eric Layne
// pandigital EC

#include <iostream>
using namespace std;

int main () {
   int x;
   int outx;
   int outxpast;
   int k;
   int z;
   int counter;
   outx = 1;
   outxpast = 1;
   counter = 0;

   int num1;
   int num2;
   int num3;
   int num4;
   int num5;
   int num6;
   int num7;
   int num8;
   int num9;

   for (num9 = 0; num9 <= 9; num9++) {
      for (num8 = 0; num8 <= 9; num8++) {
         for (num7 = 0; num7 <= 9; num7++) {
            for (num6 = 0; num6 <= 9; num6++) {
               for (num5 = 0; num5 <= 9; num5++) {
                  for (num4 = 0; num4 <= 9; num4++) {
                     for (num3 = 0; num3 <= 9; num3++) {
                        for (num2 = 0; num2 <= 9; num2++) {
                           for (num1 = 1; num1 <= 9; num1++) {
                              if (num9 == 0 && num8 == 0 && num7 == 0 && num6 == 0 && num5 == 0 && num4 == 0 && num3 == 0 && num2 == 0 && num1 == 1) {
                                 x = num1;
                              }
                              if (num9 == 0 && num8 == 0 && num7 == 0 && num6 == 0 && num5 == 0 && num4 == 0 && num3 == 0 && num2 > 0 && (num2 + num1) == 3 && num2 != num1) {
                                 x = (num2 * 10) + num1;
                              }
                              if (num9 == 0 && num8 == 0 && num7 == 0 && num6 == 0 && num5 == 0 && num4 == 0 && num3 > 0 && num2 > 0 && (num3 + num2 + num1) == 6 &&num3 != num2 != num1) {
                                 x = (num3 * 100) + (num2 * 10) + num1;
                              }
                              if (num9 == 0 && num8 == 0 && num7 == 0 && num6 == 0 && num5 == 0 && num4 > 0 && num3 > 0 && num2 > 0 && (num4 + num3 + num2 + num1) == 10 && num4 != num3 != num2 != num1) {
                                 x = (num4 * 1000) + (num3 * 100) + (num2 * 10) + num1;
                              }
                              if (num9 == 0 && num8 == 0 && num7 == 0 && num6 == 0 && num5 > 0 && num4 > 0 && num3 > 0 && num2 > 0 && (num5 + num4 + num3 + num2 + num1) == 15 && num5 != num4 != num3 != num2 != num1) {
                                 x = (num5 * 10000) + (num4 * 1000) + (num3 * 100) + (num2 * 10) + num1;
                              }
                              if (num9 == 0 && num8 == 0 && num7 == 0 && num6 > 0 && num5 > 0 && num4 > 0 && num3 > 0 && num2 > 0 && (num6 + num5 + num4 + num3 + num2 + num1) == 21 && num6 != num5 != num4 != num3 != num2 != num1) {
                                 x = (num6 * 100000) + (num5 * 10000) + (num4 * 1000) + (num3 * 100) + (num2 * 10) + num1;
                              } 
                              if (num9 == 0 && num8 == 0 && num7 > 0 && num6 > 0 && num5 > 0 && num4 > 0 && num3 > 0 && num2 > 0 && (num7 + num6 + num5 + num4 + num3 + num2 + num1) == 28 && num7 != num6 != num5 != num4 != num3 != num2 != num1) {
                                 x = (num7 * 1000000) + (num6 * 100000) + (num5 * 10000) + (num4 * 1000) + (num3 * 100) + (num2 * 10) + num1;
                              }
                              if (num9 == 0 && num8 > 0 && num7 > 0 && num6 > 0 && num5 > 0 && num4 > 0 && num3 > 0 && num2 > 0 && (num8 + num7 + num6 + num5 + num4 + num3 + num2 + num1) == 36 && num8 != num7 != num6 != num5 != num4 != num3 != num2 != num1) {
                                 x = (num8 * 10000000) + (num7 * 1000000) + (num6 * 100000) + (num5 * 10000) + (num4 * 1000) + (num3 * 100) + (num2 * 10) + num1;
                              }
                              if (num9 > 0 && num8 > 0 && num7 > 0 && num6 > 0 && num5 > 0 && num4 > 0 && num3 > 0 && num2 > 0 && (num9 + num8 + num7 + num6 + num5 + num4 + num3 + num2 + num1) == 45 && num9 != num8 != num7 != num6 != num5 != num4 != num3 != num2 != num1) {
                                 x = (num9 * 100000000) + (num8 * 10000000) + (num7 * 1000000) + (num6 * 100000) + (num5 * 10000) + (num4 * 1000) + (num3 * 100) + (num2 * 10) + num1;
                              }

                              cout << x << endl;
                              for(k = 1; k <= x; k++) {
                                 z = x % k;
                                 if (z == 0) {
                                    counter = counter + 1;
                                 }
                              }
                              if (counter == 2) {
                                 outxpast = outx;
                                 outx = x;

                                 if (outxpast < outx) {
                                    cout << outx << endl;
                                 }
                              }
                              counter = 0;
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }

   return 0;

}
