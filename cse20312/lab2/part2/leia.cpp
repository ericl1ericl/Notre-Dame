// Eric Layne
// CSE20312
// leia.cpp

#include "SWchar.h"
#include "leia.h"
#include <string>
#include <iostream>

using namespace std;

leia::leia() : SWchar("Leia Organa", "Somebody has to save our skins!") {}

void leia::print() {
   cout << name << ": " << phrase << endl;
}
