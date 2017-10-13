#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	int len = 0;
	cout << "length of array: ";
	cin >> len;
	int a[len];
	for (int i = 0; i < len; i++) {
		cout << "value " << i << ": ";
		cin >> a[i];
	}

	cout << "version 1" << endl;
	int sumright = 0;
	int sumleft = 0;
	int s[10];
	int countS = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			sumright = sumright + a[j];
		}
		for (int j = i-1; j >= 0; j--) {
			sumleft = sumleft + a[j];
		}
		cout << i << ": " << sumleft << ", " << sumright << "\n";
		if (sumright == sumleft) {
			s[countS] = i;
			countS++;
		}
		sumright = 0;
		sumleft = 0;
	}
	for (int i = 0; i < countS; i++) {
		cout << s[i] << " ";
	}
	cout << "\n";

	cout << "version 2" << endl;
	sumright = 0;
	sumleft = 0;
	countS = 0;
	int pos = 0;
	for (int i = pos+1; i < len; i++) {
		sumright = sumright + a[i];
	}
	for (int i = 0; i < len; i++) {
		cout << i << ": " << sumleft << ", " << sumright << "\n"; 
		if (sumright == sumleft) {
			s[countS] = i;
			countS++;
		}
		sumright = sumright - a[i+1];
		sumleft = sumleft + a[i];
	}
	for (int i = 0; i < countS; i++) {
		cout << s[i] << " ";
	}
	cout << "\n";
	return 0;	
}
