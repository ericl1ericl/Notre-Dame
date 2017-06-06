// Eric Layne
// CSE 20311
// Finds all prime numbers from 1 to 1000

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int sieve[1000];

   // Sets every value in the array to 1
   for (int i = 0; i <= 999; i++) {
      sieve[i] = 1;
   }

   // Sorts through all the prime numbers and leaves them as 1
   for (int j = 2; j <= 999; j++) {
      // will declare multiples of prime numbers as non-prime
      if (sieve[j] == 1) {
         // checks every number higher than itself
         for (int k = j + 1; k <= 999; k++ ) {
            // if a number has no remainder, it is a multiple and not prime
            if (k%j == 0) {
               sieve[k] = 0;
            } 
         }
      }
   }

   int z;
   int count = 0; // variable that records the number of values per line

   // prints out all the prime numbers
   for (z = 2; z <= 999; z++) {
      if (sieve[z] == 1) { // finds that number z is prime
         cout << setw(6) << fixed << right << z;
         count++;
         if (count == 10) {
            cout << endl; // after ten numbers, a new line
            count = 0; // number that counts primes per line is reset
         }
      }
   }
   cout << endl;

   return 0;
}
