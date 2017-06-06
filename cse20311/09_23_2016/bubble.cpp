#include <iostream>
using namespace std;

void bubble(int[], int);

main() {
   int a[MAX], i , n;

   cout << "Enter positive integers followed by a -1: ";
   cin >> a[n=0];
   while (a[n] != -1) {
      ++n;
      cin >> a[n];
   }

   bubble(a, n);

   for(i = 0; i < n; i++) {
      cout << a[i] << endl;
   }

   return 0;
}

void bubble(int list[], int n) {
   int i, temp;

   for (int k = 1; k <= n; ++k) {
      for (i = 0; i < n-1; ++i) {
         if (list[i] > list[i+1]) {
            temp = list[i];
            list[i] = list[i+1];
            list[i+1] = temp;
         }
      }
   }
}
