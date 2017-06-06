// grd3.cpp
// further improvement on grd2.cpp
// data file now has no sentinel
// uses an ifstream object to read the data
//  and to identify the end-of-file
// uses the string class for the data file name
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  vector<int> grades;
  int grd, grd_sum = 0;
  float avg; 
  ifstream ifs;
  string filename;

  cout << "enter data file name: ";
  cin >> filename;
  ifs.open(filename);

  if(!ifs) {
    cout << "error opening file " << filename << endl;
    return 1;
  }
 
  ifs >> grd;
  while (!ifs.eof()) {
    grades.push_back(grd);
    ifs >> grd;
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

