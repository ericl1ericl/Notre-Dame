// Eric Layne
// CSE20311
// class implementation for Rational

#include "rational.h"
#include <iostream>

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

void Rational::print()
{ std::cout << numer << " / " << denom << std::endl; }

Rational Rational::add(Rational b)
{ Rational z;
  z.setNumer(numer*b.getDenom() + denom*b.getNumer());
  z.setDenom(denom*b.getDenom());
  return z;
}

Rational Rational::subtract(Rational b)
{ Rational z;
  z.setNumer(numer*b.getDenom() - denom*b.getNumer());
  z.setDenom(denom*b.getDenom());
  return z;
}

Rational Rational::multiply(Rational b)
{ Rational z;
  z.setNumer(numer*b.getNumer());
  z.setDenom(denom*b.getDenom());
  return z;
}

Rational Rational::divide(Rational b)
{ Rational z;
  z.setNumer(numer*b.getDenom());
  z.setDenom(denom*b.getNumer());
  return z;
}
