#include <iostream>
#include <iomanip>
using namespace std;

// Eric Layne
// CSE20311
// Multiplication Table

int main () {
	int imax;	// i will be the variable for rows
	int jmax;	// j will be the variable for columns
	cout << "How many rows: ";
	cin >> imax;
	cout << "How many columns: ";
	cin >> jmax;

	int i;
	int j;
	// creates the initial top row
	cout << "*   ";
	for (j = 1; j <= jmax; j++) {
		cout << setw(4) << fixed << left << j;
		}
	cout << endl;
	
	i = 1;
	for (i = i; i <= imax; i++) {
		// creates the leftmost column
		cout << setw(4) << fixed << left << i;
		// creates the interior of the multiplication table
		for (j = 1; j <= jmax; j++) {
			cout << setw(4) << fixed << left << j*i;
		}
		cout << endl;
	}
	return 0;
}
