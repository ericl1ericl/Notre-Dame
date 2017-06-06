// Eric Layne
// CSE20312
// main.cpp

#include "SWchar.h"
#include "c3po.h"
#include "r2d2.h"
#include "luke.h"
#include "han.h"
#include "leia.h"
#include "vader.h"

#include <iostream>
using namespace std;

int main() {
   SWchar swc; // Star Wars characters
   c3po c3;
   r2d2 r2;
   luke lk;
   han hn;
   leia la;
   vader vr;

   c3po * c3_ptr = &c3;
   r2d2 * r2_ptr = &r2;
   luke * lk_ptr = &lk;
   han * hn_ptr = &hn;
   leia * la_ptr = &la;
   vader * vr_ptr = &vr;

   c3_ptr->print();
   r2_ptr->print();
   lk_ptr->print();
   hn_ptr->print();
   la_ptr->print();
   vr_ptr->print();

}
