#include <iostream>
#include <cstdlib>

using namespace std;

#include "array.h"

// rule of 3: have new/delete, then:
// 1. write constructor
// 2. write deconstructor
// 3. write copy constructor

Array::Array (int arraySize) {
   size = arraySize;
   ptr = new int[size]; // immortal
   for (int i=0; i < size; i+) {
      ptr[i] = 0;
   }
}

Array::~Array() {
   delete [] ptr; // kills immortal
}

// member initialization list syntax
Array::Array(const Array &arrayCopy) : size(arrayCopy.size) {
   ptr = new int[size];
   for (int i = 0; i < size; i++) {
      ptr[i] = arrayCopy.ptr[i];
}
