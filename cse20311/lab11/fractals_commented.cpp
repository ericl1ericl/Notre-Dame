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

   bool loop = true; // keeps while loop running
   
   while(loop) {
      char c = gfx_wait(); // controls switch statement
      switch(c) {
         case('1'): { // triangle fractal
            gfx_clear();
            triangles(xmax/2, ymax/2-250, xmax/2 + 250*sqrt(3)/2, ymax/2 + 250/2, xmax/2 - 250*sqrt(3)/2, ymax/2 + 250/2);
            break;
         }
         case('2'): { // square fractal
            gfx_clear();
            squares(xmax/3, ymax/3, xmax/3); 
            break;
         }
         case('3'): { // spiral of squares
            gfx_clear();
            spiralsquares(xmax/2-1, ymax/2-1, 1, 0);
            break;
         }
         case('4'): { // circle fractal
            gfx_clear();
            circles(xmax/2, ymax/2, xmax/4);
            break;
         }
         case('5'): { // snowflake fractal
            gfx_clear();
            snowflake(xmax/2, ymax/2, xmax/3, 5);
            break;
         }
         case('6'): { // tree fractal
            gfx_clear();
            gfx_line(xmax/2, ymax, xmax/2, ymax-ymax/3); // initial line
            tree(2, ymax/3, xmax/2, ymax - ymax/3, 0);
            break;
         }
         case('7'): { // fern fractal
            gfx_clear();
            gfx_line(xmax/2, ymax, xmax/2, ymax - 2*ymax/3); // initial line
            fern(2, 2*ymax/3, xmax/2, ymax - 2*ymax/3, 0);
            break;
         }
         case('q'): { // quits function
            loop = false;
            break;
         }
     
      }
   }

}

// sierpinski triangle function
// (x1, y1), (x2, y2), (x3, y3) describe a vertex
void triangles(int x1, int y1, int x2, int y2, int x3, int y3) {
   if (abs(x2-x1) < 5) return; // stops if a side is <5
   drawtriangle(x1, y1, x2, y2, x3, y3);
   triangles(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
   triangles((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2);
   triangles((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);
}
// draws a triangle given three vertices
void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
   gfx_line(x1, y1, x2, y2);
   gfx_line(x2, y2, x3, y3);
   gfx_line(x3, y3, x1, y1);
}
// square fractal function
// (x1, y1) denote upper-left corner of a square
// s denotes side length
void squares(int x1, int y1, int s) {
   if (abs(s) < 4) return; // stops if a side is <4
   gfx_rectangle(x1, y1, s, s); // note usage of gfx_rect vs 4 gfx_line
   float newS = s/4; // new square offset by s/4 of old square
   squares(x1-newS, y1-newS, newS*2); // new square top left
   squares(x1+3*newS, y1-newS, newS*2); // new square top right
   squares(x1-newS, y1+3*newS, newS*2); // new square bottom left
   squares(x1+3*newS, y1+3*newS, newS*2); // new square bottom right
}
// spiral of squares fractal function
// (x, y) denote upper left corner of a square
// s denotes side length
// i carries theta
void spiralsquares(float x, float y, float s, float i) {
   if (abs(s) > 100) return; // stop if side is >100
   gfx_rectangle(x, y, s, s); // draws square
   float theta = M_PI/8;
   float r = (s+2)*exp(0.05*i); // r is radius for parametric formula
   // NOTE: x, y utilize parametric formula, squares grow by one each
   // iteration, i grows by pi/8 every iteration
   spiralsquares(x + r*cos(i), y + r*sin(i), s+1, i+theta);
}
// circle fractal function
// (x, y) denotes center of circle
// r denotes radius
void circles(float x, float y, float r) {
   if (r < 1) return; // stop if radius is <1
   gfx_circle(x, y, r); // draws circle
   float theta = M_PI/3; // to put a new circle every pi/3 radians
   for (int i = 0; i <= 5; i++) { // draws six circles on old circle
      gfx_circle(x + r*cos(i*theta), y + r*sin(i*theta), r/3); 
      circles(x + r*cos(i*theta), y + r*sin(i*theta), r/3);
   } 
}
// snowflake fractal function
// (x, y) denotes hub location
// l denotes length of arm
// r denotes number of spokes
void snowflake(float x, float y, float l, int r) {
   if (abs(l) < 2) return; // stop if arm is <2
   float theta = M_PI*2/r; // draws an arm out from hub at this angle
   for (int i = 0; i < r; i++) { // draws r arms at even angles
      float x2 = x + l*cos(i*theta); // arm endpt x component
      float y2 = y + l*sin(i*theta); // arm endpt y component
      gfx_line(x, y, x2, y2); // draws line
      snowflake(x2, y2, l/3, r); // new spokes at endpoint with 1/3 length
      // NOTE: new alteration, replacing 5 with r to get accurate performance
   }
}
// tree fractal function
// slope denotes angle of branches
// l denotes length of branch
// (x,y) denotes branching point
// theta carries the angle the old branch is at
void tree(int slope, int l, float x, float y, float theta) {
   if (abs(l) < 2) return; // stop if branch is <2
   float angleR = theta + (M_PI/2 - (M_PI/(slope+1))); // right fork
   float angleL = theta - (M_PI/2 - (M_PI/(slope+1))); // left fork
   l = l*2/3; // new branch is 2/3 old branch
   float xR = x + l*sin(angleR); // right branch endpt x component
   float yR = y - l*cos(angleR); // right branch endpt y component
   float xL = x + l*sin(angleL); // left branch endpt x component
   float yL = y - l*cos(angleL); // left branch endpt y component
   gfx_line(x, y, xR, yR); // draws right branch
   gfx_line(x, y, xL, yL); // draws left branch
   tree(slope, l, xR, yR, angleR); // to repeat process on right branch
   tree(slope, l, xL, yL, angleL); // to repeat process on left branch
}
// fern fractal function
// slope denotes angle of branch
// l denotes length of branch
// (x,y) denotes branching point
// theta carries angle the old branch is at
void fern(int slope, int l, float x, float y, float theta) {
   if (abs(l) < 6) return; // stop if branch is <6
   float angleR = theta + (M_PI/2 - (M_PI/(slope+1))); // right fork
   float angleL = theta - (M_PI/2 - (M_PI/(slope+1))); // left fork
   int newl = l/4; // do divide old branch up into 4 equal pieces
   l = l/3; // new branch is 1/3 length of old branch
   for(int i = 0; i <= 3; i++) { // draws four forks on old branch
   float newx = x - i*sin(theta)*newl; // forking location x component
   float newy = y + i*cos(theta)*newl; // forking location y component
   float xR = newx + l*sin(angleR); // right branch endpt x component
   float yR = newy - l*cos(angleR); // right branch endpt y component
   float xL = newx + l*sin(angleL); // left branch endpt x component
   float yL = newy - l*cos(angleL); // left branch endpt y component
   gfx_line(newx, newy, xR, yR); // draws right branch
   gfx_line(newx, newy, xL, yL); // draws left branch
   fern(slope, l, xR, yR, angleR); // to repeat process on right branch
   fern(slope, l, xL, yL, angleL); // to repeat process on left branch
   }
}
