// Eric Layne
// CSE2011
// bounce.cpp
// adapted from Prof. Bualuan's ball2.cpp

#include <unistd.h>
#include "gfx.h"
#include <cstdlib>
#include <iostream>

int main() {
  int win_wd = 500, win_ht = 500;  // window width and height
  float xc = 100, yc = 100;        // ball initial center
  int rad = 20;                    // ball radius
  float vx = 1, vy = 1;            // velocity vector
  float dt = 5;                    // mult. factor (here, same for both x&y; needn't be)
  char c = ' ';

  gfx_open (win_wd, win_ht, "Eric Layne ~ Moving Ball");

  while(c != 'q') {
    gfx_clear();
    gfx_color(255,255,255);
      
    gfx_circle(xc, yc, rad);
    gfx_flush();
    xc = xc + vx*dt;
    yc = yc + vy*dt;

    srand(time(NULL));

    if(xc >= win_wd-rad) {      // right wall
       vx = -vx;
       xc = win_wd - rad;
    }
    else if(xc <= rad) {       // left wall
       vx = -vx;
       xc = rad;
    }
    else if(yc >= win_ht-rad) { // bottom wall
       vy = -vy;
       yc = win_ht - rad;
    }
    else if(yc <= rad) {       // top wall
       vy = -vy;
       yc = rad;
    }

    gfx_flush();
    usleep(100000);
   
    if(gfx_event_waiting()) {
       c = gfx_wait();
       
       if (c == 1) { // if mouse is clicked

          // sets ball position to cursor location when clicked
          xc = gfx_xpos() ;
          yc = gfx_ypos() ;
 
          // if user tries to place ball in invalid spot on edge of boundary, replaces ball in a valid spot
          if (xc >= win_wd-rad) {  // right
             xc = win_wd - rad - 1;
          }
          else if (xc <= rad) { // left
             xc = rad + 1;
          }
          if (yc >= win_ht-rad) { // bottom
             yc = win_ht - rad - 1;
          }
          else if (yc <= rad) { // top
             yc = rad + 1;
          }
 
          vx = ((rand() % 11)-5);  // randomizes x vector between -5, 5
          vy = ((rand() % 11)-5);  // randomizes y vector between -5, 5
 
       }
    }

  }
  return 0;
}

