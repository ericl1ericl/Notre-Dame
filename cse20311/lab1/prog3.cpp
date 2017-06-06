#include <iostream>
using namespace std;

int main()
{
	cout << "Coulomb's Law: the force interacting between two charges." <<endl;
	
	float pi;			// declare pi
	float epsilon0;		// declare epsilon naught
	pi = 3.14159265;	// define pi
	epsilon0 = 8.854*0.000000000001;	// define epsilon naught
	
	float k;		// declare constant k
	k = 1/(4*pi*epsilon0);	// define constant k

	float q1;			// declare charge q1
	float q2;			// declare charge q2
	float r;			// declare distance r
	cout << "Enter a value for charge 1 (q1, in coulombs): ";
	cin >> q1;
	cout << "Enter a value for charge 2 (q2, in coulombs): ";
	cin >> q2;
	cout << "What is the distance between the charges (in meters): ";
	cin >> r;
		if (r <= 0) {
			cout << "ERROR: distance must be positive" <<endl;
			return 0;
			}

	float x;
	x = k*(q1*q2/(r*r));
	
	cout << "The force between the two charges is " << x << " N." << endl;
	
	if (x > 0) {
		cout << "Since the force is positive, the charges repel each other." << endl;
	}
	if (x < 0) {
		cout << "Since the force is negative, the charges attract each other." << endl;
	}

	return 0;
}

// Eric Layne
