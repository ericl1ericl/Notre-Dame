// grd2.cpp
// improvement on grd1.cpp, by using a vector and iterator,
// but still needs the data file to have an sentinel,
// and still uses input redirection
//
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
  vector<int> grades;
  int grd, grd_sum = 0;
  float avg; 

  cin >> grd;
  while (grd >= 0) {
    grades.push_back(grd);
    cin >> grd;
  }

  cout << "there are " << grades.size() << " grades\n";

  for (auto it = grades.begin(); it != grades.end(); ++it) {
    grd_sum = grd_sum + *it;
  }

  avg = (float)grd_sum / grades.size();

  cout << fixed << setprecision(2);
  cout << "average: " << avg << endl ;

  return 0;
}

