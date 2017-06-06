// Eric Layne
// CSE 20311
// My sayings manager

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

void displaytext(list<string>); // displays contents of file
void newtext(list<string>&, string); // allows user to add new phrase
void findword(list<string>, string); // finds a search term
void newfile(list<string>, string); // allows user to save new file
void deleteline(list<string>&, int); // allows user to delete a line

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

   list<string> sayings; // creates a list of strings
   string line; // a string file to hold individual lines of file

   cin.ignore();
   getline(myfile, line);
   while (!myfile.eof()) {
      auto it = sayings.begin();
      while (line > *it && it != sayings.end()) {
         ++it;
      }
      if (it == sayings.end()) {
         sayings.push_back(line);
      }
      else {
         sayings.insert(it, line);
      }
      getline(myfile, line);
   }

   string newquote; // string for new phrase entered by user
   string findterm; // string for search term specified by user
   string newfilename; // string for new file name entered by user

   int x = 1; // keeps propmpts running while true
   int z; // variable that holds task number
   int linenum;

   while (x){
      cout << "\n";
      cout << "Tasks you can perform:\n";
      cout << " 1: display sayings\n";
      cout << " 2: enter a new saying\n";
      cout << " 3: list sayings that contain a given word\n";
      cout << " 4: save all sayings in new text file\n";
      cout << " 5: delete a saying\n";
      cout << " 6: quit\n";
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
         case 5: displaytext(sayings);
                 cout << "Enter a line number to delete:\n";
                 cin >> linenum;
                 deleteline(sayings, linenum); // function deleteline
                 break;
         case 6: x = 0;
                 cout << "Thank you!\n";
                 break;
         default: cout << "ERROR: enter a valid input\n";
                 break;
      }
   }
}

// function that displays the contents of the string list
void displaytext(list<string> sayings) {
   int linenum = 1;
   for (auto it = sayings.begin(); it != sayings.end(); it++, linenum++) {
      cout << " > " << linenum << ". " << *it << endl;
   }
}

// function that adds a new quote to the string list
void newtext(list<string>& sayings, string newquote) {
   auto it = sayings.begin();
   while (newquote > *it && it != sayings.end()) {
      ++it;
   }
   if (it == sayings.end()) {
      sayings.push_back(newquote);
   }
   else {
      sayings.insert(it, newquote);
   }
}

// function that finds a search term and displays the line it is found in
void findword(list<string> sayings, string findterm) {
   for (auto it = sayings.begin(); it != sayings.end(); it++) {
      auto found = (*it).find(findterm); // searches for term in pointer it
      if (found != string::npos) {
         cout << " > " << *it << endl;
      }
   }
}

// function that writes string list to new file
void newfile(list<string> sayings, string newfilename) {
   ofstream newfile (newfilename);
   for (auto it = sayings.begin(); it != sayings.end(); it++) {
      newfile << *it << endl;
   }
   newfile.close();
   cout << "SAVED: " << newfilename << endl; // lets user know it saved
}

// function that deletes a line
void deleteline(list<string>& sayings, int linenum) {
   auto it = sayings.begin();
   advance(it, (linenum-1));
   sayings.erase(it);
}
