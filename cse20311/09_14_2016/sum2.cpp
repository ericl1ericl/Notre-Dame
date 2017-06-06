#include <iostream>
using namespace std;

int main() {

   int a, sum;

   cout << "Enter positive integers, followed by a -1: ";

   sum = 0;
   cin >> a;
   while (a >= 0) {
      sum += a;
      cin >> a;
   }

   cout << "The sum is: " << sum << endl;

   return 0;
}
