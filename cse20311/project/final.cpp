// Eric Layne
// CSE 20311
// Final project
// final.cpp

#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "gfx.h"
#include <list>
using namespace std;

struct vect {  // holds vector x and y components 
   float xcomp;
   float ycomp;
};

vect make_vect(float&, float&); // makes vector

struct boid { // holds information of a boid
   float xpos; // x position
   float ypos; // y position
   vect v; // a vector of its direction
   int live; // whether or not it is live or stationary (a block)
};

boid make_boid(float&, float&, vect, bool); // makes a boid

void circle(int, int); // draws boid
void square(int, int); // draws block
vect cohesion(boid, list<boid>); // cohesive function
vect alignment(boid, list<boid>); // alignment function
vect separation(boid, list<boid>); // boids repel
vect blockrepulsion(boid, list<boid>); // only blocks repel

int main() {
   int win_wd = 600, win_ht = 400; // window size
   
   gfx_open (win_wd, win_ht+50, "Eric Layne ~ final.cpp ~ BOIDS"); // window

   float xtri; // float to hold boid x position later
   float ytri; // float to hold boid y position later

   srand(time(NULL)); // rand initialization

   int numboids = 40; // number of initial boids
//	int numboids = 0;

   list<boid> boids; // list of all the boids, containing boid info

   float vmax = 5; // max velocity

   float angle; // variables

   // randomly places boids on board, with random initial directions
   for (int i = 0; i < numboids; i++) {
         float x = rand()%(win_wd - 2) + 1; // x position
         float y = rand()%(win_ht - 2) + 1; // y position
         angle = rand()%360; // direction
         float theta = angle*(2*M_PI)/360; // degree to radian
         float vel = 1; // initial velocity
         float xvec = vel*cos(theta); // x component of vector
         float yvec = vel*sin(theta); // y component of vector
         vect v = make_vect(xvec, yvec); // vector of boid direction
         boids.push_back(make_boid(x, y, v, true)); // add boid to list
   }

   bool loop = true; // controls program quit
   bool cohn = true; // controls cohesion active
   bool sepn = true; // controls separation active
   bool algn = true; // controls alignment active
   bool noise = true; // controls noise active
   vect v1, v2, v3; // vectors for cohesion, separation, alignment

   float x0 = 0; // zeroed x position variable
   float y0 = 0; // zeroed y position variable
   float xmouse; // mouse position variable
   float ymouse; // mouse position variable
   vect v; // initialized vector variable
   float xnoise, ynoise; // noise variables

   while(loop) {

      gfx_clear();

      gfx_line(0, win_ht, win_wd, win_ht);
      gfx_text(470, win_ht + 20, "Q: QUIT");
      gfx_text(5, win_ht + 40, "LEFT CLICK: ADD BOID  |  RIGHT CLICK: ADD BLOCK  |  P: PAUSE");

      // animates all boids in list
      for (auto it = boids.begin(); it != boids.end(); it++) {
         xtri = (*it).xpos; // boid x position
         ytri = (*it).ypos; // boid y position

         if((*it).live == true) { // if boid is alive draw circle
            circle(xtri, ytri);
            gfx_line(xtri, ytri, 1.5*(*it).v.xcomp+xtri, 1.5*(*it).v.ycomp+ytri); // shows direction of boid and length corresponds to velocity
         }
         else { // draws stationary block
            square(xtri, ytri);
         }

         if (cohn) { // if cohesion active
            v1 = cohesion((*it), boids); // call cohesion function
            gfx_text(5, win_ht + 20, "1: COHESION ON  |");
         }
         else {
            v1 = make_vect(x0, y0); // vector v1 is empty
            gfx_text(5, win_ht + 20, "1: COHESION OFF |");
         }
         if (sepn) { // if separation active
            v2 = separation((*it), boids); // call separation function
            gfx_text(120, win_ht + 20, "2: SEPARATION ON  |");
         }
         else {
            v2 = blockrepulsion((*it), boids); // ensure blocks still repel
            gfx_text(120, win_ht + 20, "2: SEPARATION OFF |");
         }
         if (algn) { // if alignment active
            v3 = alignment((*it), boids); // call alignment function
            gfx_text(250, win_ht + 20, "3: ALIGNMENT ON  |");
         }
         else {
            v3 = make_vect(x0, y0); // vector v3 is empty
            gfx_text(250, win_ht + 20, "3: ALIGNMENT OFF |");
         }

         gfx_flush();

         if (xtri > win_wd) { // right side
            xtri = 0; // move to left side
         }
         else if (xtri < 0) { // left side
            xtri = win_wd; // move to right side
         }
         if (ytri >= win_ht - 15) { // bounce off bottom
            (*it).v.ycomp = -(*it).v.ycomp;
            ytri = win_ht - 15;
         }
         else if (ytri <= 4) { // bounce off top
            (*it).v.ycomp = -(*it).v.ycomp;
            ytri = 4;
         }
         
         // math for boid's velocity in x direction
         (*it).v.xcomp = (*it).v.xcomp + v1.xcomp/8 + 2*v2.xcomp + v3.xcomp/5;
         if ((*it).v.xcomp >= vmax) { // if velocity is too positive
            (*it).v.xcomp = vmax;
         }
         else if ((*it).v.xcomp <= -vmax) { // if velocity is too negative
            (*it).v.xcomp = -vmax;
         }
         // math for boid's velocity in y direction
         (*it).v.ycomp = (*it).v.ycomp + v1.ycomp/8 + 2*v2.ycomp + v3.ycomp/5;
         if ((*it).v.ycomp >= vmax) {
            (*it).v.ycomp = vmax;
         }
         else if ((*it).v.ycomp <= -vmax) {
            (*it).v.ycomp = -vmax;
         }

         if (noise) { // if true generate noise
            xnoise = (rand()%3 - 2)/4;
            ynoise = (rand()%3 - 2)/4;
            gfx_text(370, win_ht + 20, "4: NOISE ON  |");
         }
         else {
            xnoise = 0;
            ynoise = 0;
            gfx_text(370, win_ht + 20, "4: NOISE OFF |");
         }
         
         if ((*it).live == 1) { // give boid motion if alive
            (*it).xpos = xtri + (*it).v.xcomp + xnoise;
            (*it).ypos = ytri + (*it).v.ycomp + ynoise;
         }
         else { // keep stationary boid stationary
            (*it).xpos = xtri;
            (*it).ypos = ytri;
         }

      }

      if (gfx_event_waiting()) { // keyboard and user inputs
         char c = gfx_wait();
         switch (c) {
            case '1': // toggle cohesion
               cohn = !cohn;
               break;
            case '2': // toggle separation
               sepn = !sepn;
               break;
            case '3': // toggle alignment
               algn = !algn;
               break;
            case '4': // toggle noise
               noise = !noise;
               break;
            case 'p': // pause
               gfx_text(win_wd/2-80, win_ht/2, "PRESS ANY KEY TO RESUME");
               gfx_wait();
               break;
            case 1: // add a boid with mouse
               xmouse = gfx_xpos();
               ymouse = gfx_ypos();
               v = make_vect(x0, y0);
               boids.push_back(make_boid(xmouse, ymouse, v, true));
               break;
            case 3: // add a block with mouse
               xmouse = gfx_xpos();
               ymouse = gfx_ypos();
               v = make_vect(x0, y0);
               boids.push_back(make_boid(xmouse, ymouse, v, false));
               break;
            case 'q': // quit
               loop = !loop;
               break;
         }
      }

      usleep(80000); //80000 is optimal for my PC
   
   }
}

// makes a boid
boid make_boid(float& xpos, float& ypos, vect v, bool live) {
   boid x;
   x.xpos = xpos; // x position
   x.ypos = ypos; // y position
   x.v = v; // direction vector
   x.live = live; // alive or stationary
   return x;
}

// makes a vector
vect make_vect(float& xcomp, float& ycomp) {
   vect x;
   x.xcomp = xcomp; // x component
   x.ycomp = ycomp; // y component
   return x;
}

// draws a square
void square(int x, int y) {
   gfx_line(x-3, y-3, x-3, y+3);
   gfx_line(x-3, y-3, x+3, y+3);
   gfx_line(x-3, y-3, x+3, y-3);
   gfx_line(x+3, y-3, x+3, y+3);
   gfx_line(x+3, y+3, x-3, y+3);
   gfx_line(x-3, y+3, x+3, y-3);
}

// draws a circle
void circle(int xc, int yc) {
   gfx_circle(xc, yc, 4);
}

// cohesion function: boids attracted to center of mass of other boids within 
// radius
vect cohesion(boid bd, list<boid> boids) {
   float xint = bd.xpos; // initial x position
   float yint = bd.ypos; // initial y position
   float xcenter = 0; // will hold average x
   float ycenter = 0; // will hold average y
   float radius = 50; // boundary for detection
   int n = 0; // important for tracking number of boids in radius
   // go through list of boids
   for (auto it = boids.begin(); it != boids.end(); it++) {
      float xpoint = (*it).xpos; // x position of other boid
      float ypoint = (*it).ypos; // y position of other boid
      // distance from initial boid to new boid
      float d = sqrt(pow((xpoint - xint),2)+pow((ypoint - yint),2));
      // living boids within the radius affect the center of mass 
      if (d <= radius && d != 0 && (*it).live == true) { 
         xcenter = xcenter + (*it).xpos; // add up x positions
         ycenter = ycenter + (*it).ypos; // add up y positions
         n++;
      }
   }
   xcenter = xcenter / n; // average x positions
   ycenter = ycenter / n; // average y positions
   float xdiff = xcenter - xint; // x vector from center of mass to boid
   float ydiff = ycenter - yint; // y vector from center of mass to boid
   if (n == 0) {  // if no boids detected in the radius
      xdiff = 0; // no center of mass
      ydiff = 0; // no center of mass
   }
   vect z = make_vect(xdiff, ydiff); // return vector
   return z;
}

// alignment function: boids tend to match velocity with other boids within
// radius
vect alignment(boid bd, list<boid> boids) {
   float xint = bd.xpos; // initial boid x position
   float yint = bd.ypos; // initial boid y position
   float xvelocity = 0; // variable to hold x vectors
   float yvelocity = 0; // variable to hold y vectors
   float radius = 50; // radius to check
   int n = 0; // important for tracking number of boids in radius
   // go through list of boids
   for (auto it = boids.begin(); it != boids.end(); it++) {
      float xpoint = (*it).xpos; // x position of new boid
      float ypoint = (*it).ypos; // y postiion of new boid
      // distance from initial boid to new boid
      float d = sqrt(pow((xpoint - xint),2)+pow((ypoint - yint),2));
      // living boids within the radius affect the vectors
      if (d <= radius && d != 0 && (*it).live == true) {
         xvelocity = xvelocity + (*it).v.xcomp; // add x vectors
         yvelocity = yvelocity + (*it).v.ycomp; // add y vectors
         n++;
      }
   }
   xvelocity = xvelocity / n; // average x velocity of flock
   yvelocity = yvelocity / n; // average y velocity of flock
   if (n == 0) { // if no boids detected in the radius
      xvelocity = 0; // no additional velocity
      yvelocity = 0; // no additional velocity
   }
   vect z = make_vect(xvelocity, yvelocity); // return vector
   return z;
}

// separation function: boids repel each other if they get too close
vect separation(boid bd, list<boid> boids) {
   float xint = bd.xpos; // intitial boid x position
   float yint = bd.ypos; // initial boid y position
   float radius = 15; // smaller radius around boid
   vect z; // vector
   float xdiff = 0; // x vector to repulse boid
   float ydiff = 0; // y vector to repulse boid
   // go through list of boids
   for (auto it = boids.begin(); it != boids.end(); it++) {
      float xpoint = (*it).xpos; // new boid x position
      float ypoint = (*it).ypos; // new boid y position
      // distance from initial boid to new boid
      float d = sqrt(pow((xpoint - xint),2)+pow((ypoint - yint),2));
      // repulse boid based on anythin in radius, even blocks
      if (d <= radius && d > 0) {
         xdiff = xdiff - (xpoint - xint); // repulse in x direction
         ydiff = ydiff - (ypoint - yint); // repulse in y direction
      }
   }
   z = make_vect(xdiff, ydiff); // return vector
   return z;
}

// block repulstion function: used when separation function is deactivated.
// ensures that blocks always repel
vect blockrepulsion(boid bd, list<boid> boids) {
   float xint = bd.xpos; // initial boid x position
   float yint = bd.ypos; // initial boid y position
   float radius = 15; // smaller radius around bid
   vect z; // vector
   float xdiff = 0; // x vector to repulse boid
   float ydiff = 0; // y vector to repulse boid
   // go through list of boids
   for (auto it = boids.begin(); it != boids.end(); it++) {
      float xpoint = (*it).xpos; // new boid x position
      float ypoint = (*it).ypos; // new boid y position
      // distance from initial boid to new boid
      float d = sqrt(pow((xpoint - xint),2)+pow((ypoint - yint),2));
      // repulse only if boid is stationary - normal repulsion is off
      if (d <= radius && d > 0 && (*it).live == false) {
         xdiff = xdiff - (xpoint - xint); // repulse in x direction
         ydiff = ydiff - (ypoint - yint); // repulse in y direction
      }
   }
   z = make_vect(xdiff, ydiff); // return vector
   return z;
}
