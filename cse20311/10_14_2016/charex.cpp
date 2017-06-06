#include <iostream>
using namespace std;

int main() {
   char x;
   x = 'q';

   cout << "letter: " << x << endl;
   cout << "code: " << (int)x << endl;

   int n = 121;
   cout << "number: " << n << endl;
   cout << "corresponding letter: " << (char)n << endl;

   cout << 't' - 'a' << endl;

   return 0;
}
