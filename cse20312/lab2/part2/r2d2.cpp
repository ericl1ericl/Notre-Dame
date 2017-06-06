// Eric Layne
// CSE20312
// r2d2.cpp

#include "SWchar.h"
#include "r2d2.h"
#include <string>
#include <iostream>

using namespace std;

r2d2::r2d2() : SWchar("R2-D2", "[beep]") {}

void r2d2::print() {
   cout << name << ": " << phrase << endl;
}
