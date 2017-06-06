#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Eric Layne
// CSE20311
// ASCII Graph (graphing a curve)

int main () {

	float xmax;
	float xmin;
	xmin = 0;		// starting x value
	xmax = 25;		// final x value
	cout << "A plot of y = 2*(sin(2*x)+cos(3*x))+4 from x = ";
	cout << setprecision(1) << fixed << xmin << " to " << xmax << endl; 

	cout << setw(5) << fixed << right << "X";
	cout << setw(6) << fixed << right << "Y";
	cout << endl;
	
	float x;		// x value at one instant
	float y;		// y value at one instant
	float ymax;		// stores maximum y value
	float ymin;		// stores minimum y value
	float xofymax;		// stores x position of maximum y
	float xofymin;		// stores x position of minimum y
	float interval;		// incrementation
	float xstop;		// x value that tells loop when to stop
	interval = 0.2;
	xstop = xmax + interval;
	for (x = xmin; x <= xstop ;) {
		cout << setprecision(2) << fixed << setw(5) << fixed << right;
		cout << x;
		y = 2*(sin(2*x)+cos(3*x))+4;
		cout << setprecision(2) << fixed << setw(6) << fixed << right;
		cout << y;
		if (x == 0) {		// creates an initial value for ymin/ymax
			ymax = y;
			ymin = y;
		}
		if (y >= ymax) {	// determines y maximum
			ymax = y;
			xofymax = x;
		}
		if (y <= ymin) {	// determines y minimum
			ymin = y;
			xofymin = x;
		}	
		
		// Graphs the function with # signs
		float numpd;		
		numpd = round(y/0.2);	// rounds the number of fifths in y
		cout << " ";
		for (int k = 1; k <= numpd; k++) {
			cout << "#";
		}

		cout << endl;
		x = x + interval;
	}

	cout << "" << endl;
	cout << "Maximum: y = " << ymax << " at x = " << xofymax << endl;
	cout << "Minimum: y = " << ymin << " at x = " << xofymin << endl;

	return 0;
}

