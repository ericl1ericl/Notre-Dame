#include <iostream>
using namespace std;

int main() {
   char str[] = "hello";

   char c = 8;
   cout << "I say " << str << c << " to everyone" << endl;
// prints our hell instead of hello because ASCII 8 is backspace

   str[5] = 'z';
   cout << ">" << str << "<" << endl;
// does not have odd string output because there must be a null char
// even though z replaced the old null character

   for (int i = 1; i <= 10; i++) {
      str[5+i] = 'a';
      cout << ">" << str << " " << i << "<" << endl;
   }
// stops because it destroys the variable i
// 97 is printed because it is ASCII value of i

   return 0;
}
