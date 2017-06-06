// Eric Layne
// CSE20311
// symbol.cpp

#include "gfx.h"
#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159265

int main() {
   const int xsize = 700, ysize = 600;
   char c;

   gfx_open(xsize, ysize, "Eric Layne ~ symbol.cpp");
   gfx_clear();
   
   while(1) {
      double z = 25; // radius
      c = gfx_wait();
      int xcenter = gfx_xpos();
      int ycenter = gfx_ypos();
      if (c == 1) { // on left mouse click, blue square
         gfx_color(0, 0, 255);
         gfx_line(xcenter + z, ycenter + z, xcenter - z, ycenter + z);
         gfx_line(xcenter + z, ycenter - z, xcenter - z, ycenter - z);
         gfx_line(xcenter + z, ycenter + z, xcenter + z, ycenter - z);
         gfx_line(xcenter - z, ycenter + z, xcenter - z, ycenter - z);
      }
      else if (c == 't') { // on entering t, green triangle
         gfx_color(0, 255, 0);
         gfx_line(xcenter, ycenter - z, xcenter + z*sqrt(3)/2, ycenter + z/2);
         gfx_line(xcenter, ycenter - z, xcenter - z*sqrt(3)/2, ycenter + z/2);
         gfx_line(xcenter + z*sqrt(3)/2, ycenter + z/2, xcenter - z*sqrt(3)/2, ycenter + z/2);
      } 
      else if (c == 'c') { // on entering c, white circle
         gfx_color(255, 255, 255);
         gfx_circle(xcenter, ycenter, z);
      }
      else if (c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') { // purple n-gon of c sides
         gfx_color(200, 0, 220);
         double sides = (int)c - 48; // turns ascii into sides
         double ix = xcenter + z; // initial vertice
         double iy = ycenter; // initial vertice
         double theta = 2*PI/sides; // angle between vertices (in radians)
         for (double i = 1; i <= sides; i++) { // draws a line between every vertice
             gfx_line(ix, iy, z*cos(theta*i) + xcenter, z*sin(theta*i) + ycenter);
             ix = z*cos(theta*i) + xcenter; // next vertice
             iy = z*sin(theta*i) + ycenter; // next vertice
         }
      }
      else if (c =='q') { // quits
         return 0;
      }
   }

   return 0;

}
