// driver to test the School class
// it reads the data into a vector, and then displays it all

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "school.h"

void displayall(vector<School> &);

int main()
{
  ifstream ifs;
  string infilename;
  string name, nick, yr_s;
  int yr;
  vector<School> schools;
  School sch;

  cout << "enter data file name: ";
  cin >> infilename;
  ifs.open(infilename);
  if (!ifs) {
    cout << "bad file name: " << infilename << endl;
    return 1;
  }

  char c = ifs.peek();
  while(c != EOF) {
    getline(ifs, name , ',');
    getline(ifs, nick , ',');
    getline(ifs, yr_s , '\n');
    yr = stoi(yr_s);
    sch = School(name, nick, yr);
    schools.push_back(sch);
    c = ifs.peek();
  }

  displayall(schools);

  return 0;
}

// display all schools as:
//  school (nickname): year
void displayall(vector<School> &s)
{
  for (auto it = s.begin(); it != s.end(); ++it) {
    cout << it->getSchoolname() << " (";
    cout << it->getNickname() << "): ";
    cout << it->getYear() << endl;
  }
}

