// Eric Layne
// CSE20311
// statemain.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

#include "state.h"

void displaystates(vector<State> &);
void stateabbrv(vector<State> &, string);
void statecap(vector<State> &, string);
void statepop(vector<State> &, string);
void stateyear(vector<State> &, string);
void statereps(vector<State> &, string);
void displaydata(vector<State> &);

int main() {
   ifstream myfile;
   string filename; // string for data file name
   string abbr, name, cap, pop_s, year_s, reps_s; // variables for data
   int pop; // variable for population
   int year; // variable for year state was admitted into Union
   int reps; // variable for number of state representatives
   vector<State> states; // creates vector of State called states
   State ste; // variable to hold state class data

   cout << endl;
   cout << "Enter data file name: ";
   cin >> filename;
   myfile.open(filename);
   if (!myfile) { // returns error if no file exists
      cout << "ERROR: bad file " << filename << endl;
      return 1;
   }

   char c = myfile.peek();
   while (c != EOF) { // loop to extract data from file into vector
      getline(myfile, abbr, ',');
      getline(myfile, name, ',');
      getline(myfile, cap, ',');
      getline(myfile, pop_s, ',');
      getline(myfile, year_s, ',');
      getline(myfile, reps_s, '\n');
      pop = stoi(pop_s); // converts string to integer
      year = stoi(year_s);
      reps = stoi(reps_s);
      ste = State(abbr, name, cap, pop, year, reps);
      states.push_back(ste); // inserts data from ste into states vector
      c = myfile.peek();
   }

   int x = 1; // variable to keep while loop running
   int z; // variable for switch loop cases
   string statename; // string for the state user wishes to learn about

   while(x) {
      cout << "\n";
      cout << "Please choose an option:\n";
      cout << " 1: list all states alphabetically\n";
      cout << " 2: get state abbreviation\n";
      cout << " 3: get state capital\n";
      cout << " 4: get state population\n";
      cout << " 5: get year state was admitted into Union\n";
      cout << " 6: get number of state representatives\n";
      cout << " 7: display all data in file\n";
      cout << " 0: quit\n";
      cout << "Please enter a choice: ";
      cin >> z;

      switch(z) {
         case 1: displaystates(states); // calls function
                 break;
         case 2: cout << "Enter a state name: ";
                 cin.ignore();
                 getline(cin, statename);
                 stateabbrv(states, statename); // calls function
                 break;
         case 3: cout << "Enter a state name: ";
                 cin.ignore();
                 getline(cin, statename);
                 statecap(states, statename); // calls function
                 break;     
         case 4: cout << "Enter a state name: ";
                 cin.ignore();
                 getline(cin, statename);
                 statepop(states, statename); // calls function
                 break;     
         case 5: cout << "Enter a state name: ";
                 cin.ignore();
                 getline(cin, statename);
                 stateyear(states, statename); // calls function
                 break;     
         case 6: cout << "Enter a state name: ";
                 cin.ignore();
                 getline(cin, statename);
                 statereps(states, statename); // calls function
                 break;     
         case 7: displaydata(states); // calls function
                 break;
         case 0: x = 0;
                 cout << "Thank you!\n";
                 break;     
         default: cout << "ERROR: enter a valid input\n";
                 break;
      }
   }
   return 0;
}

// function to display all the state names
void displaystates(vector<State> &s) {
   for (auto it = s.begin(); it != s.end(); ++it) {
      cout << " > " << it->getName() << endl;
   }
}

// function to display the abbreviation for user entered state
void stateabbrv(vector<State> &s, string statename) {
   int x = 0; // variable to trigger error message
   for (auto it = s.begin(); it != s.end(); ++it) {
      if (it->getName() == statename) {
         cout << " > " << it->getAbbr() << endl;
         x = 1;
      }
   }
   if (x != 1) { // displays error if user mistypes state name
      cout << "ERROR: ensure state is spelled and capitalized properly" << endl;
   } 
}

// function to display the capital of user entered state
void statecap(vector<State> &s, string statename) {
   int x = 0;
   for (auto it = s.begin(); it != s.end(); ++it) {
      if (it->getName() == statename) {
         cout << " > " << it->getCap() << endl;
         x = 1;
      }
   }
   if (x != 1) {
      cout << "ERROR: ensure state is spelled and capitalized properly" << endl;
   } 
}

// function to display population of user entered state
void statepop(vector<State> &s, string statename) {
   int x = 0;
   for (auto it = s.begin(); it != s.end(); ++it) {
      if (it->getName() == statename) {
         cout << " > " << it->getPop() << endl;
         x = 1;
      }
   }
   if (x != 1) {
      cout << "ERROR: ensure state is spelled and capitalized properly" << endl;
   } 
}

// function to display year unionized of user entered state
void stateyear(vector<State> &s, string statename) {
   int x = 0;
   for (auto it = s.begin(); it != s.end(); ++it) {
      if (it->getName() == statename) {
         cout << " > " << it->getYear() << endl;
         x = 1;
      }
   }
   if (x != 1) {
      cout << "ERROR: ensure state is spelled and capitalized properly" << endl;
   } 
}

// function to display number of representatives in user entered state
void statereps(vector<State> &s, string statename) {
   int x = 0;
   for (auto it = s.begin(); it != s.end(); ++it) {
      if (it->getName() == statename) {
         cout << " > " << it->getReps() << endl;
         x = 1;
      }
   }
   if (x != 1) {
      cout << "ERROR: ensure state is spelled and capitalized properly" << endl;
   } 
}

// function that displays all the data within the file
void displaydata(vector<State> &s) {
   for (auto it = s.begin(); it != s.end(); ++it) {
      cout << " > ";
      cout << setw(3) << it->getAbbr();
      cout << setw(16) << it->getName();
      cout << setw(16) << it->getCap();
      cout << setw(10) << it->getPop();
      cout << setw(6) << it->getYear();
      cout << setw(4) << it->getReps() << endl;
   }
}
