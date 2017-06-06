// implementation for the School class

#include "school.h"

School::School() { }

School::School(string sn, string nn, int yr) 
{ schoolname = sn; nickname = nn; year = yr; }

School::~School() { }

void School::setSchoolname(string sn) 
{ schoolname = sn; }

void School::setNickname(string nn) 
{ nickname = nn; }

void School::setYear(int yr) 
{ year = yr; }

string School::getSchoolname() 
{ return schoolname; }

string School::getNickname() 
{ return nickname; }

int School::getYear() 
{ return year; }

