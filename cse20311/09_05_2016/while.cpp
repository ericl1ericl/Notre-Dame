# include <iostream>
using namespace std;

int main() {
	int i = 0;
	/*
	while (i < 10) {
		cout << ++i << endl;
	}
	*/
	do {
		cout << i++ << endl;
	}	while (i < 10);
}
