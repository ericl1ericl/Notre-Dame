#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cout << "Enter a string: ";
	string str;
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), toupper());
	cout << str << endl;
	return 0;	
}
