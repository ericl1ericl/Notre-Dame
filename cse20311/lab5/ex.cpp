#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   fstream ifs("startup.txt");
   string strObject;
   getline(ifs, strObject);
   while(!ifs.eof()) {
      cout << strObject << endl;
      getline(ifs, strObject);
   }
}
