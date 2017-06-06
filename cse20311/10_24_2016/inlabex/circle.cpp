// class implementation for Circle

#include "circle.h" // prototype

Circle::Circle()
{ radius = 1; }

Circle::Circle(float r)
{ radius = r; }

Circle::~Circle() { }

float Circle::getRadius()
{ return radius; }

void Circle::setRadius(float r)
{ radius = r; }

float Circle::circumference()
{ return 2*3.14159265*radius; }

float Circle::area()
{ return 3.14159265*radius*radius; }
