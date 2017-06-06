// Eric Layne
// CSE20311
// state.cpp implementation

#include "state.h"

State::State() {
}

State::State(string ab, string nm, string cp, int pp, int yr, int rp) {
   abbr = ab;
   name = nm;
   cap = cp;
   pop = pp;
   year = yr;
   reps = rp;
}

State::~State() {
}

void State::setAbbr(string ab) {
   abbr = ab;
}

void State::setName(string nm) {
   name = nm;
}

void State::setCap(string cp) {
   cap = cp;
}

void State::setPop(int pp) {
   pop = pp;
}

void State::setYear(int yr) {
   year = yr;
}

void State::setReps(int rp) {
   reps = rp;
}

string State::getAbbr() {
   return abbr;
}

string State::getName() {
   return name;
}

string State::getCap() {
   return cap;
}

int State::getPop() {
   return pop;
}

int State::getYear() {
   return year;
}

int State::getReps() {
   return reps;
}
