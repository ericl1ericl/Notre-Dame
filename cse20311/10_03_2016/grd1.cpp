// grd1.cpp
// reads grades from a file (with a sentinel value)
// using input redirection, and puts them in a built-in array,
// and finds their average
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int grades[100];  // assume no more than 100 grades             
  int grd_sum = 0;
  int i, count;          
  float avg;  

  i = 0;
  cin >> grades[i];
  while (grades[i] >= 0) {
    ++i;
    cin >> grades[i];
  }
  count = i;

  cout << "there are " << count << " grades\n";

  for (i = 0; i < count; i++) {
    grd_sum = grd_sum + grades[i];
  }

  avg = (float)grd_sum / count;

  cout << fixed << setprecision(2);
  cout << "average: " << avg << endl;

  return 0;
}

