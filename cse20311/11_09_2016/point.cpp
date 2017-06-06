// point.cpp
#include <iostream>
using namespace std;
#include <cmath>
#include "point.h"

Point::Point() 
{ setpoint(0., 0.); } 

Point::Point(double x, double y) 
{ setpoint(x, y); }

Point::~Point() 
{ }

double Point::getx() 
{ return x; }

double Point::gety() 
{ return y; }

void Point::setx(double x) 
{ this->x = x; }

void Point::sety(double y) 
{ this->y = y; }

void Point::setpoint(double x, double y) 
{ 
  setx(x);
  sety(y); 
}

double Point::radius() 
{ return distance(Point(0.,0.)); }

double Point::angle() 
{ return atan2(y,x); }

double Point::distance(Point p)
{ return sqrt(pow((x-p.x),2) + pow((y-p.y),2)); }

ostream& operator<< (ostream &s, Point &m)
{
  s << "(" << m.x << "," << m.y << ")"; 
  return s;
}

istream& operator>> (istream &s, Point &m)
{
  cout << "Enter x and y coordinates: ";
  s >> m.x >> m.y;
  return s;
}

