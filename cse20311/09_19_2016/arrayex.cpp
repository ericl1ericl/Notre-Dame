#include <iostream>
using namespace std;

int main() {
   int nums[21];
   int sum = 0;
   int a, count = 0;

   cout << "Enter a few positive numbers (20 or less), followed by a -1: ";
   cin >> a;
   
   while(a != -1) {
      nums[count] = a;
      count++;
      cin >> a;
   }
   
   for (int j = 0; j < count; j++) {
      cout << nums[j] << endl;
   }

   for (int k = 0; k < count; k++) {
      sum += nums[k];
   }

   cout << "There are " << count << " numbers." << endl;
   cout << "Their sum is: " << sum << endl;

   return 0;
}
