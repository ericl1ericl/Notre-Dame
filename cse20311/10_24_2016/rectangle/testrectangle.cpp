// main driver to test the Rectangle class
#include <iostream>
using namespace std;
#include "rectangle.h"

int main()
{
  Rectangle r(3, 2);  // the 2nd constructor will be called

  cout << "length: " << r.getLength() << endl;
  cout << "width: " << r.getWidth() << endl;
  cout << "perimeter is: " << r.perimeter() << endl;
  cout << "area is: " << r.area() << endl;

  return 0;
}

