// Eric Layne
// CSE20312
// c3po.cpp

#include "SWchar.h"
#include "c3po.h"
#include <string>
#include <iostream>

using namespace std;

c3po::c3po() : SWchar("C-3PO", "You know better than to trust a strange computer!") {}

void c3po::print() {
   cout << name << ": " << phrase << endl;
}
