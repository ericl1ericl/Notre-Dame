#include <iostream>

class Rectangle {
   public:
//      Rectangle(); {} // fallback values make this uncecessary
      Rectangle (int=10, int=20); // fallback values
      ~Rectangle(); {} // deconstructor
      Rectangle (Rectangle &);
      void setLength(int newL); // set funciton/mutators
   private:
      int length; //
      int width;
      int array[100]; // static memory, 100 items
      int *arr2; // pointer pointing to arbitrary numers
};
Rectangle::Rectangle() {
   length = 10;
   width = 20;
   arr2 = malloc(  // malloc: memory allocation
}
Rectangle::Rectangle(int newL, int newW) {
   length = newL;
   width = newW;
//   arr2 = malloc(newNum*sizeof(int)); // C way
   arr2 = new int[newNum]; // C++ way
//   arr3 = new FooBsr[newNum];
}
Rectangle::~Rectangles() {
   delete [] arr2; // needs brackets to remove array
}
void doSomethingCool(Rectangle newR); // passing by value, makes a copy
void doSOmethingCool(Rectangle & thenewR) { // passing by reference
   thenewR.hihdsadf;
}
int main() {
   Rectangle myR;
   myR.length = -10;
}
