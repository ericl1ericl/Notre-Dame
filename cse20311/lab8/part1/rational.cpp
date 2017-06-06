// Eric Layne
// CSE20311
// class implementation for Rational

#include <iostream>
using namespace std;
#include <cmath>
#include "rational.h"

Rational::Rational()
{ numer = 1; denom = 1; }

Rational::Rational(int nm, int dn)
{ numer = nm; denom = dn; }

Rational::~Rational() { }

int Rational::getNumer()
{ return numer; }

int Rational::getDenom()
{ return denom; }

void Rational::setNumer(int nm)
{ numer = nm; }

void Rational::setDenom(int dn)
{ denom = dn; }

void Rational::setRational(int nm, int dn)
{ numer = nm; denom = dn; }

void Rational::print()
{ std::cout << numer << " / " << denom << std::endl; }

Rational Rational::operator+(Rational b)
{ Rational z;
  z.setNumer(numer*b.getDenom() + denom*b.getNumer());
  z.setDenom(denom*b.getDenom());
  return z;
}

Rational Rational::operator-(Rational b)
{ Rational z;
  z.setNumer(numer*b.getDenom() - denom*b.getNumer());
  z.setDenom(denom*b.getDenom());
  return z;
}

Rational Rational::operator*(Rational b)
{ Rational z;
  z.setNumer(numer*b.getNumer());
  z.setDenom(denom*b.getDenom());
  return z;
}

Rational Rational::operator/(Rational b)
{ Rational z;
  z.setNumer(numer*b.getDenom());
  z.setDenom(denom*b.getNumer());
  return z;
}

ostream& operator<< (ostream &s, Rational &c)
{ s << c.numer << " / " << fabs(c.denom);
  return s;
}

istream& operator>> (istream &s, Rational &c)
{ int x, y;

  cout << "Enter the numerator and the denominator: ";
  s >> x >> y;
  c.setRational(x, y);

  return s;
}
