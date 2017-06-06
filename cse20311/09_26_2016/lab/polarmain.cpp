// Eric Layne
// CSE20311
// Cartesian to Polar Converter

#include <iostream>
#include "polarfn.h"
using namespace std;

int main() {
   double x, y;

   cout << "x coordinate: ";
   cin >> x;
   cout << "y coordinate: ";
   cin >> y;

   double r, t;
   r = radius(x, y);
   t = theta(x, y);

   cout << "Polar coordinates (in radians): ( " << r;
   cout << " , " << t;
   cout << " )" << endl;

   cout << "Located in: ";
   cout << location(x, y) << endl;

   return 0;

}
 
