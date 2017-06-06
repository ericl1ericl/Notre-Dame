// Eric Layne
// CSE20312
// han.cpp

#include "SWchar.h"
#include "han.h"
#include <string>
#include <iostream>

using namespace std;

han::han() : SWchar("Han Solo", "Never tell me the odds!") {}

void han::print() {
   cout << name << ": " << phrase << endl;
}
