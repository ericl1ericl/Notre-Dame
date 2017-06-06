// Eric Layne
// CSE20311
// simple driver to test the Rational class

#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  cout << endl;
  
  Rational a(9,9), b(3,7), c, s;

  cout << "*** display a and b ***\n";
  cout << a << endl;
  cout << b << endl;

  cout << "*** set a to 5/6 ***\n";
  a.setRational(5,6);
  cout << a << endl;
  
  cout << "*** display c ***\n";
  cout << c << endl;

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a + b;
  cout << s << endl;
  
  // subtract a and b
  cout << "*** compute s as the math difference of a and b, and display s ***\n";
  s = a - b;
  cout << s << endl;

  // multiply a and b
  cout << "*** compute s as the math product of a and b, and display s ***\n";
  s = a * b;
  cout << s << endl;

  // divide a and b
  cout << "*** compute s as the math quotient of a and b, and display s ***\n";
  s = a / b;
  cout << s << endl;

  // get user inputs
  Rational u;
  cout << "*** get inputs from the user ***\n";
  cin >> u;
  cout << "*** display said inputs ***\n";
  cout << u << endl;
  cout << "*** compute s as the math sum of user input and a ***\n";
  s = a + u;
  cout << s << endl;

  cout << endl;

  return 0;
}

