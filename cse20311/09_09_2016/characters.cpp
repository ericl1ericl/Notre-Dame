#include <iostream>
using namespace std;

int main() {

	char x;

	for (x = 'a'; x <= 'z'; x++) {
		cout << x;
	}
	cout << endl;
	
	for (x = 99; x <= 115; x++) {
		cout << x;
	}
	cout << endl;

	for (int i = 99; i <= 115; i++) {
		cout << i;
	}
	cout << endl;

	cout << (char) 70 << endl;
	cout << static_cast<char>(87) << endl;

	return 0;
}
