#include <iostream>
using namespace std;
#include "point.h"

int main()
{
  Point a(4,3.2), b(7.8,-1.2), c;

  cout << "points a, b, c are at: " << endl;
  cout << " a: " << a << endl;
  cout << " b: " << b << endl;
  cout << " c: " << c << endl;

  cout << "the distance between a and b is: " << a.distance(b) << endl;
  cout << "point a's polar radius is: " << a.radius() << endl;
  cout << "point a's polar angle is: " << a.angle() << endl;

  c.setpoint(-1.6,5.5);
  cout << "point c is now at: " << c <<  endl;

  Point d;
  cin >> d;
  cout << " d: " << d <<  endl;
  
  return 0;
}

