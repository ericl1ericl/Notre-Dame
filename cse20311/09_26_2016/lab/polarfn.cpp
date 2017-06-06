#include <iostream>
#include <math.h>
using namespace std;

// Function calculating hypotenuse (radius)
double radius(double x, double y) {
   double r;

   r = sqrt(x * x + y * y);

   return r;
}

// Function calculating theta
double theta(double x, double y) {
   double t;

   t = atan2(y, x);

   return t;
}

// Function determining the location of the point
char location(int x, int y) {
   if (x < 0 && y == 0) {
      cout << "Negative x-axis";
   }
   else if (x < 0 && y > 0) {
      cout << "Quadrant II";
   }
   else if (x == 0 && y > 0) {
      cout << "Positive y-axis";
   }
   else if (x > 0 && y > 0) {
      cout << "Quadrant I";
   }
   else if (x > 0 && y == 0) {
      cout << "Positive x-axis";
   }
   else if (x == 0 && y == 0) {
      cout << "Origin";
   }
   else if (x > 0 && y < 0) {
      cout << "Quadrant IV";
   }
   else if (x == 0 && y < 0) {
      cout << "Negative y-axis";
   }
   else {
      cout << "Quadrant III";
   }

   return 0;
}
