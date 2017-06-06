// Eric Layne
// CSE 20311
// Text Menu Calculator

#include <iostream>
#include <iomanip>
using namespace std;

char inputs(double, double);
char operations(double, double, int);

int main() {
   int x;
   double a, b;

   while (1) {
      cout << "What would you like to do?" << endl;
      cout << setw(20) << "1 for addition" << endl;
      cout << setw(23) << "2 for subtraction" << endl;
      cout << setw(26) << "3 for multiplication" << endl;
      cout << setw(20) << "4 for division" << endl;
      cout << setw(15) << "5 to exit" << endl;

      cout << "Enter your choice: ";
      cin >> x;

      if (x == 5) {
         cout << "Thank you!" << endl;
         return 0;
      }

      cout << "Enter two numbers: ";
      cin >> a >> b;

      inputs(a, b);

      operations(a, b, x); 
   }
   return 0;
}

// represents inputted numbers as fixed decimals
char inputs(double a, double b) {
   cout << "Inputs: ";
   cout << setprecision(6) << fixed << a;
   cout << ", ";
   cout << setprecision(6) << fixed << b;
   cout << endl;

   return 0;
}

// outputs the equation desired by the user
char operations(double a, double b, int x) {
   double c;
   char symbol;

   if (x == 1) {
      c = a + b;
      symbol = '+';
   }
   if (x == 2) {
      c = a - b;
      symbol = '-';
   }
   if (x == 3) {
      c = a * b;
      symbol = '*';
   }
   if (x == 4) {
      c = a / b;
      symbol = '/';
   }

   cout << setprecision(6) << "(" << a;
   cout << ") " << symbol << " (";
   cout << setprecision(6) << b <<  ") = " << c;
   cout << endl;

   return 0;
}
