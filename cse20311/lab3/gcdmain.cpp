// Eric Layne
// CSE20311
// Simple Function (GCD)

#include <iostream>
using namespace std;

int getgcd(int, int);
int gcd(int, int);

int main() {
   int x, y, z;

   cout << "Enter two integers: ";
   cin >> x >> y; 

   z = getgcd(x, y);

   cout << "The greatest common divisor is: " << z << endl;

   return 0;
}

// Function calling a GCD function
int getgcd(int a, int b) {
   int c;

   c = gcd(a, b);

   return c;
}

// Function that determines GCD
int gcd(int a, int b) {
   if (a < b) {
      return gcd(b, a);
   } 

   int f = a % b;
   if (f == 0) {
      return b;
   }
   else {
      return gcd(b, f);
   }
}

