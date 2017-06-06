#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string myline;
   int count = 0;

   cout << "enter a line: ";
   getline(cin, myline);

   for (auto it = myline.begin(); it < myline.end(); ++it) {
      cout << *it << endl;
      if (ispunct(*it)) count++;
   }

   cout << "the line's size is: " << myline.size() << endl;
   cout << "there are " << count << " punctations\n";
   cout << myline << endl;

   return 0;
}
