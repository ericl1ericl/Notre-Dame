#include <iostream>
using namespace std;
#include <array>

const int size = 5;
typedef array<int, size> myArray;

int main() {
   myArray arr = { 2, 16, 77, 34, 50 };
   myArray::iterator it;

   cout << "arr contains: ";
   for (it = arr.begin(); it < arr.end(); it++)
      cout << *it << " ";
   cout << endl;

   return 0;
}
