#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Eric Layne
// CSE20311
// Mortgage Calculator (amortization table)

int main() {
	float bal;		//initialize principal
	float ir;		//initialize interest rate
	float mp;		//initialize mortgage payment
	bal = 0;
	ir = 0;
	mp = 0;
	while (bal <= 0) {
		cout << "Principal: ";
		cin >> bal;
		if (bal <= 0) {
			cout << "ERROR: Principal must be positive.";
			cout << endl;
		}
	}
	while (ir <= 0) {
		cout << "Interest Rate (in __%): ";
		cin >> ir;
		if (ir <= 0) {
			cout << "ERROR: Interest Rate must be positive.";
			cout << endl;
		}
	}
	while (mp <= 0) {
		cout << "Monthly Mortgage Payment: ";
		cin >> mp;
		if (mp <= 0) {
			cout << "ERROR: Payment must be positive:";
			cout << endl;
		}
	}

	float interest;		//initialize interest
	int mnth;		//initialize month
	float total;		//initialize total amount paid
	mnth = 1;		//start at month 1
	total = 0;

	interest = (ir/100)*bal/12;	//monthly interest will be annual/12
	if (mp < interest) {
		cout << "ERROR: Monthly payment too small. Balance will";
		cout << " never be paid off." << endl;
		return 0;
	}

	cout << "Month      Payment      Interest      Balance";
	cout << endl;
	while (bal > 0) {
		interest = (ir/100)*bal/12;
		//for normal calculation when payment is less than balance
		if (bal+interest >= mp) {
			bal = interest + bal - mp;
			total = total + mp;
		}
		//for final payment when balance is less than normal payment
		else {
			mp = bal + interest;
			total = total + mp;
			bal = bal + interest - mp;
		}
		cout << setw(4) << fixed << left << mnth;
		cout << setw(8) << fixed << right << "$";
		cout << setprecision(2) << fixed << setw(7) << fixed << right;
		cout << mp;
		cout << setw(6) << fixed << right << "$";
		cout << setprecision(2) << fixed << setw(7) << fixed << right;
		cout << interest;
		cout << setw(7) << fixed << right << "$";
		cout << setprecision(2) << fixed << setw(9) << fixed << right;
		cout << bal;
		cout << endl;
		mnth++;
	}
	mnth = mnth - 1;
	float yrs;
	yrs = mnth/12;	
	yrs = floor(yrs);
	int rmdrMnth;
	rmdrMnth = mnth - (12*yrs);
	cout << "" << endl;
	cout << setprecision(2) << fixed << "You paid a total of $" << total;
	cout << setprecision(0) << fixed << " over " << yrs << " years and ";
	cout << rmdrMnth << " months." << endl;
	cout << "" << endl;

	return 0;
}
