#include <iostream>
using namespace std;

void func(void);
void funcstatic(void);

int main() {
   for (int i = 1; i <= 5; i++)
      func();
   cout << endl;
   for (int i = 1; i <= 5; i++)
      funcstatic();
}

void func(void) {
   int n = 11;
   cout << "n: " << n << endl;
   n++;
}

void funcstatic(void) {
   static int n = 11;
   cout << "n: " << n << endl;
   n++;
}
