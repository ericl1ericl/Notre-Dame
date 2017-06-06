#include <iostream>
using namespace std;
#include <vector>

const int size = 5;

int main() {
   vector<int> arr = { 2, 16, 77, 34, 50 };

   cout << "arr contains: ";
   for (auto it = arr.begin(); it < arr.end(); it++)
      cout << *it << " ";
   cout << endl << arr.size() << endl;

   return 0;
}
