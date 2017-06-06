// Eric Layne
// CSE20312
// SWchar.cpp

#include "SWchar.h"
#include <iostream>

using namespace std;

SWchar::SWchar (string n, string p) {
   name = n;
   phrase = p;
}

void SWchar::setName(const string x) {
   name = x;
}

void SWchar::setPhrase(const string x) {
   phrase = x;
}

string SWchar::getName() {
   return (name);
}

string SWchar::getPhrase() {
   return (phrase);
}
