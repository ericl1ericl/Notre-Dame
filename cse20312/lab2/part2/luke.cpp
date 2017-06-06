// Eric Layne
// CSE20312
// luke.cpp

#include "SWchar.h"
#include "luke.h"
#include <string>
#include <iostream>

using namespace std;

luke::luke() : SWchar("Luke Skywalker", "I have a very bad feeling about this") {}

void luke::print() {
   cout << name << ": " << phrase << endl;
}
