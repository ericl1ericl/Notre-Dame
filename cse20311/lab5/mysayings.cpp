// Eric Layne
// CSE 20311
// My sayings manager

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void displaytext(vector<string>); // displays contents of file
void newtext(vector<string>&, string); // allows user to add new phrase
void findword(vector<string>, string); // finds a search term
void newfile(vector<string>, string); // allows user to save new file

int main() {
   string filename; // will save startup .txt file name as string
   cout << "\nWelcome to the sayings manager!\n";
   cout << "Enter name of startup file: ";
   cin >> filename; // saves .txt file name as string
   fstream myfile (filename); // pulls in data from file to myfile

   if (!myfile) { // displays error if specified file does not exist
      cout << "ERROR: error opening file\n";
      return 0;
   }

   vector<string> sayings; // creates a vector of strings
   string line; // a string file to hold individual lines of file
   while(getline(myfile, line)) { // transfers myfile to sayings line by line
      sayings.push_back(line);
   }

   string newquote; // string for new phrase entered by user
   string findterm; // string for search term specified by user
   string newfilename; // string for new file name entered by user

   int x = 1; // keeps propmpts running while true
   int z; // variable that holds task number

   while (x){
      cout << "\n";
      cout << "Tasks you can perform:\n";
      cout << " 1: display sayings\n";
      cout << " 2: enter a new saying\n";
      cout << " 3: list sayings that contain a given word\n";
      cout << " 4: save all sayings in new text file\n";
      cout << " 5: quit\n";
      cout << "Please enter a choice: ";
      cin >> z;

      switch(z) {
         case 1: displaytext(sayings);
                 break;
         case 2: cout << "Enter a new quote:\n";
                 cin.ignore();
                 getline(cin, newquote);
                 newtext(sayings, newquote); // function newtext
                 break;
         case 3: cout << "Enter a search term:\n";
                 cin.ignore();
                 getline(cin, findterm);
                 findword(sayings, findterm); // function findword
                 break;
         case 4: cout << "Enter a new text file name:\n";
                 cin >> newfilename;
                 newfile(sayings, newfilename); // function newfile
                 break; 
         case 5: x = 0;
                 cout << "Thank you!\n";
                 break;
         default: cout << "ERROR: enter a valid input\n\n";
                 break;
      }
   }
}

// function that displays the contents of the string vector
void displaytext(vector<string> sayings) {
   for (auto it = sayings.begin(); it < sayings.end(); it++) {
      cout << " > " << *it << endl;
   }
}

// function that adds a new quote to the string vector
void newtext(vector<string>& sayings, string newquote) {
   sayings.push_back (newquote);  
}

// function that finds a search term and displays the line it is found in
void findword(vector<string> sayings, string findterm) {
   for (auto it = sayings.begin(); it < sayings.end(); it++) {
      auto found = (*it).find(findterm); // searches for term in pointer it
      if (found != string::npos) {
         cout << " > " << *it << endl;
      }
   }
}

// function that writes string vector to new file
void newfile(vector<string> sayings, string newfilename) {
   ofstream newfile (newfilename);
   for (auto it = sayings.begin(); it < sayings.end(); it++) {
      newfile << *it << endl;
   }
   newfile.close();
   cout << "SAVED: " << newfilename << endl; // lets user know it saved
}
