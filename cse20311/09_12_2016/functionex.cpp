#include <iostream>
using namespace std;

int addition(int, int);
int remainder(int, int);

int main()
{
   int a, b, c, r;

   cout << "Enter two numbers: ";
   cin >> a >> b;

   c = addition(a, b);	// The value of addition(a, b) is assigned to c
   r = remainder(a, b);

   cout << "" << endl;
   cout << "Their sum is: " << c << endl;
   cout << "The remainder of " << a << "/" << b << " is: ";
   cout << r << endl;
   cout << "" << endl;
   cout << "The variable a is: " << a << endl;
   cout << "" << endl;

   return 0;
}

int addition(int a, int b)
{
   int c;

   c = a + b;

   a = 99999;	// This will not be output because it is a local variable
   return c;	// This gets returned to addition(a, b)
}

int remainder(int a, int b)
{
   int r;
   r = a%b;
   return r;
}
