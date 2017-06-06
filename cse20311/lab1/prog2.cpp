#include <iostream>
using namespace std;

int main()
{
	int td;
	cout << "Enter the number of touchdowns scored by the Irish: ";
	cin >> td;
	int xpt;
	cout << "Enter the number of extra points made by the Irish: ";
	cin >> xpt;
	int fg;
	cout << "Enter the number of field goals made by the Irish: ";
	cin >> fg;
	int s;
	cout << "Enter the number of safeties scored by the Irish: ";
	cin >> s;
	
	int sum;
	sum = td*6 + xpt*1 + fg*3 + s*2;
	cout << "The Fighting Irish scored " << sum << " points.  Go Irish!" 
	<< endl;
	
	return 0;
}

// Eric Layne

