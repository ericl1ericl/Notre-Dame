// Eric Layne
// CSE20311
// fractals.cpp

#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
using namespace std;
#include "gfxnew.h"

void triangles(int, int, int, int, int, int);
void drawtriangle(int, int, int, int, int, int);
void squares(int, int, int);
void spiralsquares(float, float, float, float);
void circles(float, float, float);
void snowflake(float, float, float, int);
void tree(int, int, float, float, float);
void fern(int, int, float, float, float);

int main() {
   int xmax = 600;
   int ymax = 600;
   gfx_open(xmax, ymax, "Eric Layne ~ Fractals");
   gfx_clear();

   bool loop = true;
   
   while(loop) {
      char c = gfx_wait();
      switch(c) {
         case('1'): {
            gfx_clear();
            triangles(xmax/2, ymax/2-250, xmax/2 + 250*sqrt(3)/2, ymax/2 + 250/2, xmax/2 - 250*sqrt(3)/2, ymax/2 + 250/2);
            break;
         }
         case('2'): {
            gfx_clear();
            squares(xmax/3, ymax/3, xmax/3); 
            break;
         }
         case('3'): {
            gfx_clear();
            spiralsquares(xmax/2-1, ymax/2-1, 1, 0);
            break;
         }
         case('4'): {
            gfx_clear();
            circles(xmax/2, ymax/2, xmax/4);
            break;
         }
         case('5'): {
            gfx_clear();
            snowflake(xmax/2, ymax/2, xmax/3, 5);
            break;
         }
         case('6'): {
            gfx_clear();
            gfx_line(xmax/2, ymax, xmax/2, ymax-ymax/3);
            tree(2, ymax/3, xmax/2, ymax - ymax/3, 0);
            break;
         }
         case('7'): {
            gfx_clear();
            gfx_line(xmax/2, ymax, xmax/2, ymax - 2*ymax/3);
            fern(2, 2*ymax/3, xmax/2, ymax - 2*ymax/3, 0);
            break;
         }
         case('q'): {
            loop = false;
            break;
         }
     
      }
   }

}

void triangles(int x1, int y1, int x2, int y2, int x3, int y3) {
   if (abs(x2-x1) < 5) return;
   drawtriangle(x1, y1, x2, y2, x3, y3);
   triangles(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
   triangles((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2);
   triangles((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);
}
void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
   gfx_line(x1, y1, x2, y2);
   gfx_line(x2, y2, x3, y3);
   gfx_line(x3, y3, x1, y1);
}
void squares(int x1, int y1, int s) {
   if (abs(s) < 4) return;
   gfx_rectangle(x1, y1, s, s);
   float newS = s/4;
   squares(x1-newS, y1-newS, newS*2);
   squares(x1+3*newS, y1-newS, newS*2);
   squares(x1-newS, y1+3*newS, newS*2);
   squares(x1+3*newS, y1+3*newS, newS*2);
}
void spiralsquares(float x, float y, float s, float i) {
   if (abs(s) > 100) return;
   gfx_rectangle(x, y, s, s);
   float theta = M_PI/8;
   float r = (s+2)*exp(0.05*i);
   spiralsquares(x + r*cos(i), y + r*sin(i), s+1, i+theta);
}
void circles(float x, float y, float r) {
   if (r < 1) return;
   gfx_circle(x, y, r);
   float theta = M_PI/3;
   for (int i = 0; i <= 5; i++) {
      gfx_circle(x + r*cos(i*theta), y + r*sin(i*theta), r/3); 
      circles(x + r*cos(i*theta), y + r*sin(i*theta), r/3);
   } 
}
void snowflake(float x, float y, float l, int r) {
   if (abs(l) < 2) return;
   float theta = M_PI*2/r;
   for (int i = 0; i < r; i++) {
      float x2 = x + l*cos(i*theta);
      float y2 = y + l*sin(i*theta);
      gfx_line(x, y, x2, y2);
      snowflake(x2, y2, l/3, 5);
   }
}
void tree(int slope, int l, float x, float y, float theta) {
   if (abs(l) < 2) return;
   float angleR = theta + (M_PI/2 - (M_PI/(slope+1)));
   float angleL = theta - (M_PI/2 - (M_PI/(slope+1)));
   l = l*2/3;
   float xR = x + l*sin(angleR);
   float yR = y - l*cos(angleR);
   float xL = x + l*sin(angleL);
   float yL = y - l*cos(angleL);
   gfx_line(x, y, xR, yR);
   gfx_line(x, y, xL, yL);
   tree(slope, l, xR, yR, angleR);
   tree(slope, l, xL, yL, angleL);
}
void fern(int slope, int l, float x, float y, float theta) {
   if (abs(l) < 6) return;
   float angleR = theta + (M_PI/2 - (M_PI/(slope+1)));
   float angleL = theta - (M_PI/2 - (M_PI/(slope+1)));
   int newl = l/4;
   l = l/3;
   for(int i = 0; i <= 3; i++) {
   float newx = x - i*sin(theta)*newl;
   float newy = y + i*cos(theta)*newl;
   float xR = newx + l*sin(angleR);
   float yR = newy - l*cos(angleR);
   float xL = newx + l*sin(angleL);
   float yL = newy - l*cos(angleL);
   gfx_line(newx, newy, xR, yR);
   gfx_line(newx, newy, xL, yL);
   fern(slope, l, xR, yR, angleR);
   fern(slope, l, xL, yL, angleL);
   }
}
