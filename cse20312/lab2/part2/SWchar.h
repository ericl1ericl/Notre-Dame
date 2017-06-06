// Eric Layne
// CSE20312
// SWchar.h

#ifndef SWCHAR_H
#define SWCHAR_H

#include <string>
using namespace std;

class SWchar {

   public:
      SWchar(string = "empty", string = "empty"); // constructor
      virtual void print() = 0;
      void setName(const string); // set character name
      void setPhrase(const string); // set character phrase
      string getName(); // get character name
      string getPhrase(); // get character phrase

   protected:
      string name;
      string phrase;
};

#endif
