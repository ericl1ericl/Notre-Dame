// Eric Layne
// CSE 20311
// Finds all prime numbers from 1 to 1000

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int sieve[1000000];

   // Sets every value in the array to 1
   for (int i = 0; i <= 999999; i++) {
      sieve[i] = 1;
   }

   // Sorts through all the prime numbers and leaves them as 1
   for (int j = 2; j <= 999999; j++) {
      // will declare multiples of prime numbers as non-prime
      if (sieve[j] == 1) {
         // checks every number higher than itself
         for (int k = j + 1; k <= 999999; k++ ) {
            // if a number has no remainder, it is a multiple and not prime
            if (k%j == 0) {
               sieve[k] = 0;
            } 
         }
      }
   }

   int z;
   int zx;

   for (int k = 999999; k >= 1; k--) {
      if (sieve[k] == 1) {
         int val = k;
            if (val%100000 == k) {
               if (val%10000 == k) {
                  if (val%1000 == k) {
                     if (val%100 == k) {
                        if (val%10 == k) {
                           sieve[k] = 1;
                        }
                     }
                     else {
                        zx = 1;
                        while (zx == 1) {
                           z = val%100;
                           val = val - z;
                           val = (val/100)+(z*100);
                           if (sieve[val] == 0) {
                              sieve[k] = 0;
                           }
                           if (val == k) {
                              zx = 0;
                           }
                        }
                     }
                  }
                  else {
                     zx = 1;
                     while (zx == 1) {
                        z = val%1000;
                        val = val - z;
                        val = (val/1000)+(z*1000);
                        if (sieve[val] == 0) {
                           sieve[k] = 0;
                        }
                        if (val == k) {
                           zx = 0;
                        }
                     }
                  }
               }
               else {
                  zx = 1;
                  while (zx == 1) {
                     z = val%10000;
                     val = val - z;
                     val = (val/10000)+(z*10000);
                     if (sieve[val] == 0) {
                        sieve[k] = 0;
                     }
                     if (val == k) {
                        zx = 0;
                     }
                  }
               }
            }
            else {
               zx = 1;
               while (zx == 1) {
                  z = val%100000;
                  val = val - z;
                  val = (val/100000)+(z*100000);
                  if (sieve[val] == 0) {
                     sieve[k] = 0;
                  }
                  if (val == k) {
                     zx = 0;
                  }
               }
            }
       }
   }
   
   int count = 0;

   for (int i = 1; i <= 999999; i++) {
      if (sieve[i] == 1) {
         count++;
      }
   }
   cout << count << endl;

   return 0;
}
