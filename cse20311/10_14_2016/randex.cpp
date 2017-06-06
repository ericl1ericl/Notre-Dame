#include <iostream>
using namespace std;
#include <cstdlib>
#include<ctime>

int main() {
   int i, n = 10;
   time_t t;

   srand(time(&t));

   for (i = 1; i <= n; i++) {
      cout << rand()%50 + 1 << endl;
   }

   return 0;
}
