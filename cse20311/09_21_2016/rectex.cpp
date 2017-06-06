#include <iostream>
#include <cmath>
using namespace std;

void compute (int, int, int &, int &);

int main () {
   int a, b, circ, area;

   cout << "Enter dimensions of rectangle: ";
   cin >> a >> b;
   compute(a, b, circ, area);

   cout << "Perimeter is: " << circ << endl;
   cout << "Area is: " << area << endl;

   return 0;
}

void compute(int a, int b, int &circ, int &area) {
   circ = 2*(a+b);
   area = a*b;
}
