#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

int main() {
   ifstream ifs;
   string filename;
   int num;

   list<int> areacodes;

   cout << "Enter file name: ";
   cin >> filename;

   ifs.open(filename);
   if (!ifs) {
      cout << "ERROR" << endl;
      return 1;
   }

   ifs >> num;
   while(!ifs.eof()) {
      areacodes.push_back(num);
      ifs >> num;
   }

   int i = 1;
   for (auto it = areacodes.begin(); it != areacodes.end(); ++it, ++i) {
      cout << *it << " ";
      if (i%15 == 0) {
         cout << endl;
      }
   }

   cout << endl;
   return 0;
}
