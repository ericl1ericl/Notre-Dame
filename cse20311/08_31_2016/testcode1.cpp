#include <iostream>
using namespace std;

int main()
{
	float x;
	cout << "Enter x: ";
	cin >> x;
	
	if (x > 0)
		cout << "You entered a positive number" << endl;
	else
		cout << "You entered a negative number" << endl;
		
	return 0;
}

