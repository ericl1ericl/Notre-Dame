#include <iostream>
using namespace std;

int main() {

   int a, sum;

   cout << "Enter 10 integers: ";

   sum = 0;
   for (int i = 1; i <= 10; i++) {
      cin >> a;
      sum += a;
   }

   cout << "The sum is: " << sum << endl;

   return 0;
}
