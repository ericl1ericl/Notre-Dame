// Eric Layne
// CSE20312
// vader.cpp

#include "SWchar.h"
#include "vader.h"
#include <string>
#include <iostream>

using namespace std;

vader::vader() : SWchar("Darth Vader", "I find your lack of faith disturbing") {}

void vader::print() {
   cout << name << ": " << phrase << endl;
}
