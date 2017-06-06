// Eric Layne
// CSE 20311
// Takes a series of grades from an inputted file and
// computes their average and std. deviation

#include <iostream>
#include <math.h>
using namespace std;

int main() {
   int grades[51]; // One extra on fifty to fit the sentinel value
   int sum = 0;
   int count = 0;
   int a = 0;

   cin >> a;

   // reads every input into "grades" array until sentinel value reached
   while (a >= 0) {
      grades[count] = a; // reads input into array
      count++;
      cin >> a;
   }

   // calculates the sum of all the inputted grades
   for (int j = 0; j < count; j++) {
      sum += grades[j];
   }

   double avg; // variable declared for average
   avg = (double) sum / (double) count;

   double stddevsum; // variable declared for the summation portion of the
                     // standard deviation equation

   // calcuates the summation portion of the std. dev. equation
   for (int k = 0; k < count; k++) {
      stddevsum += ((grades[k] - avg)*(grades[k] - avg));
   } 

   double stddev; // variable declared for the standard deviation
   stddev = sqrt(stddevsum / (count-1)); // calculates std. dev.

   cout << "The average grade is: " << avg << endl;
   cout << "The standard deviation is: " << stddev << endl;

   return 0;
}
