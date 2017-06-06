// Eric Layne
// CSE 20311
// Letter frequency

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cctype>
#include <iomanip>
using namespace std;

void alphacount(int[], char); // function that counts the occurence of a letter 

int main() {
   string filename; // string to hold .txt file name
   cout << "\nLetter Frequency Counter\n";
   cout << "Enter name of text file: ";
   cin >> filename;
   fstream myfile (filename); // reads .txt file into myfile

   if (!myfile) { // displays an error if no file exists
      cout << "ERROR: error opening file\n";
      return 0;
   }
   
   char c; // variable to hold each character
   int countchar = 0; // variable that counts total number of characters
   int countlet = 0; // variable that counts total letters
   int countws = 0; // variable that counts total white spaces
   int eachlet [26]; // array that holds occurrence of each letter

   for (int i = 1; i <= 26; i++) { // populates array with zeroes
      eachlet[i] = 0;
   }
  
   myfile.get(c); 
   while(!myfile.eof()) { // pulls one character at a time and analyzes it
      ++countchar;
      c = tolower(c); // lowercases the character
      if (isalpha(c) != 0) { // if character is in alphabet
         ++countlet;
         alphacount(eachlet, c);
      }
      else if (isspace(c) != 0) { // if character is white space
         ++countws;
      }
      myfile.get(c);
   }

   int newline = 0; // variable that holds elements per displayed line
   for(int i = 1; i <= 26; i++ ) { // displays how often letter occurs
      if (newline == 6) { // if there are six elements, then new line
         cout << endl;
         newline = 0;
      }
      cout << setw(2) << fixed << right << (char)(i+96) << ": ";
      cout << setw(7) << fixed << left << eachlet[i];
      newline++;
   }
   cout << endl;

   cout << "Total characters: " << countchar << endl;
   cout << "Number of letters: " << countlet << endl;
   cout << "Number of white spaces: " << countws << endl;

   // white space percentage
   double wspct = (double)countws / (double)countchar * 100;
   cout << "Percentage of white space: ";
   cout << setprecision(1) << fixed << wspct << "%\n"; 
   cout << endl;
}

// function that counts the occurrence of each letter
void alphacount(int eachlet[26], char c) {
   int x;
   x = (int)c; // converts letter (char) to integer
   int z = x - 96; // converts ascii to position in alphabet
   eachlet[z] = eachlet[z] + 1; // adds one to corresponding position
}
