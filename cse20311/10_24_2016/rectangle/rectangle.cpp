// class implementation for Rectangle

#include "rectangle.h"   // need to include the class interface (prototype)

Rectangle::Rectangle() 
{ length = 1; width = 1; }

Rectangle::Rectangle(float wd, float ln) 
{ length = ln; width = wd; }

Rectangle::~Rectangle() { }  // nothing to be done (yet)

float Rectangle::getLength() 
{ return length; }

float Rectangle::getWidth() 
{ return width; }

void Rectangle::setLength(float ln) 
{ length = ln; }

void Rectangle::setWidth(float wd) 
{ width = wd; }

float Rectangle::perimeter() 
{ return 2*(length+width); }

float Rectangle::area() 
{ return (length*width); }

