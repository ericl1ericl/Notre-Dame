#include <iostream>
#include <string>
using namespace std;

int main() {
   string s1, s2;
   cout << "s1: ";
   cin >> s1;
   cout << "s2: ";
   cin >> s2;
   cout << s1.compare(s2) << endl;
}
