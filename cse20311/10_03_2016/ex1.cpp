#include <iostream>
using namespace std;

const int size = 5;

int main() {
   int arr[size] = { 2, 16, 77, 34, 50 };

   cout << "arr contains: ";
   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
   cout << endl;

   return 0;
}
