// Eric Layne
// CSE20311
// sailboat.cpp
// An extensive modification of Prof. Bualuan's spaceship.cpp

#include <iostream>
using std::cout;
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include "gfxnew.h"

void drawBoat(float posx, float posy, float theta, float size);
void drawHelm(float helm);

int main() {
  const float WINDOW_WID = 1200;    // window size
  const float WINDOW_HGT = 400;

  float posx = 2*WINDOW_WID / 3;     // initial sailboat position
  float posy = WINDOW_HGT / 2;
  const float size = 20;   // sailboat size
  float shiptheta = 0;         // begins straight up, redefined theta coordinates
  float helmtheta = 0;
  float velocity = 6;      // initial velocity

  char event;              // get the key press
  bool loop = true;        // flag to check for animation termination

  gfx_open (WINDOW_WID, WINDOW_HGT, "Eric Layne ~ SAILBOAT");   // open a window

  gfx_clear_color(0, 76, 153);
 // display help menu for user
  cout << "  left arrow for left turn\n";
  cout << "  right arrow for right turn\n";
  cout << "  q to quit\n";
  // start the continuous loop; keep looping while "loop" is true
  while(loop) {  
    gfx_clear();   // clear the screen

    // waves
    gfx_color(255, 255, 255);
    gfx_arc(715-15, 200, 30, 10, 0, -90);
    gfx_arc(715+15, 200, 30, 10, 180, 90);
    gfx_color(255, 255, 255);
    gfx_arc(1100-15, 60, 30, 10, 0, -90);
    gfx_arc(1100+15, 60, 30, 10, 180, 90);
    gfx_color(102, 255, 255);
    gfx_arc(1000-15, 250, 30, 10, 0, -90);
    gfx_arc(1000+15, 250, 30, 10, 180, 90);
    gfx_color(102, 255, 255);
    gfx_arc(955-15, 320, 30, 10, 0, -90);
    gfx_arc(955+15, 320, 30, 10, 180, 90);
    gfx_color(102, 255, 178);
    gfx_arc(620-15, 330, 30, 10, 0, -90);
    gfx_arc(620+15, 330, 30, 10, 180, 90);
    gfx_color(102, 255, 178);
    gfx_arc(530-15, 100, 30, 10, 0, -90);
    gfx_arc(530+15, 100, 30, 10, 180, 90);

    // draw the boat and the wheel
    drawBoat(posx, posy, shiptheta, size);
    drawHelm(helmtheta);

    gfx_flush();   // flush the output

    posx = posx + velocity * sin(shiptheta);
    posy = posy - velocity * cos(shiptheta);

    usleep(30000);  // pause

    // let user change the direction of the sailboat
    // with arrow keys
    if (gfx_event_waiting()) {

      event = gfx_wait();
      switch (event) {
      // left turn
        case 'Q':  // 'Q' is left arrow
          helmtheta = helmtheta - 0.25;
        break;
      // right turn
        case 'S':  // 'S' is right arrow
          helmtheta = helmtheta + 0.25;
        break;
      // quit
        case 'q':  // hitting the 'q' key quits the animation 
          loop = false;
        break;
      }
    }
    shiptheta = shiptheta + 0.1*(helmtheta/0.25/10);

    // Detect collision
    if (posx < WINDOW_WID/3)
      posx = WINDOW_WID;
    else if (posx > WINDOW_WID)
      posx = WINDOW_WID/3;

    if (posy < 0)
      posy = WINDOW_HGT;
    else if (posy > WINDOW_HGT)
      posy = 0;
  
    if (helmtheta >= 3) {
      helmtheta = 3;
    }
    if (helmtheta <= -3) {
      helmtheta = -3;
    }

  }

  return 0;
}

// Draw a triangular sailboat
// Arguments:
//  - posx and posy: center reference of sailboat
//  - theta: angle of sailboat with respect to vertical
//  - size: length from center to top corner
void drawBoat(float posx, float posy, float theta, float size) {
  float xTop, yTop, xBotLeft, yBotLeft, xBotRight, yBotRight;
  float xMid, yMid, xsL, ysL, xsR, ysR;

  // Determine positions of the corners
  const float ang = 2*M_PI/3;
  
  // draw and fill the boat
  float i = 1;
  gfx_color(204, 102, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .9; 
  gfx_color(204, 102, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .8; 
  gfx_color(184, 92, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .7; 
  gfx_color(164, 82, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .6; 
  gfx_color(144, 72, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .5; 
  gfx_color(124, 62, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .4; 
  gfx_color(64, 32, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .3; 
  gfx_color(64, 32, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .2; 
  gfx_color(64, 32, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
  i = .1; 
  gfx_color(64, 32, 0);
  xTop = posx + i * size * sin(theta);
  yTop = posy - i * size * cos(theta);
  xBotLeft = posx + i * 0.5 * size * sin(theta - ang);
  yBotLeft = posy - i * 0.5 * size * cos(theta - ang);
  xBotRight = posx + i * 0.5 * size * sin(theta + ang);
  yBotRight = posy - i * 0.5 * size * cos(theta + ang);
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
 
  // draw the sail
  xMid = posx + size / 4 * sin(theta);
  yMid = posy - size / 4 * cos(theta);
  xsL = xMid + size * 0.7  * cos(theta);
  ysL = yMid + size * 0.7 * sin(theta);
  xsR = xMid - size * 0.7 * cos(theta);
  ysR = yMid - size * 0.7 * sin(theta);
  gfx_color(255, 255, 255);
  gfx_line(xsL, ysL, xsR, ysR);
  gfx_line(xsL, ysL+1, xsR, ysR+1);
  gfx_line(xsL, ysL-1, xsR, ysR-1);

}

void drawHelm(float theta) {
  gfx_color(0, 0, 0);
  gfx_fill_rectangle(0, 0, 400, 400); // background rectangle
  
  float x2, y2; // endpoint of spokes on helm

  x2 = 200 + 160*sin(theta);
  y2 = 200 - 160*cos(theta);

  gfx_color(255, 0, 0); // upper spoke will be red for easy reference
  gfx_line(200, 200, x2, y2);
 
  gfx_fill_circle(x2, y2, 7); // upper decorative bulb

  // draws the other seven brown spokes
  gfx_color(154, 87, 20);
  x2 = 200 + 160*sin(theta + M_PI/4);
  y2 = 200 - 160*cos(theta + M_PI/4);
  gfx_line(200, 200, x2, y2); // spoke
  gfx_fill_circle(x2, y2, 7); // bulb
  x2 = 200 + 160*sin(theta + M_PI/4*2);
  y2 = 200 - 160*cos(theta + M_PI/4*2);
  gfx_line(200, 200, x2, y2);
  gfx_fill_circle(x2, y2, 7);
  x2 = 200 + 160*sin(theta + M_PI/4*3);
  y2 = 200 - 160*cos(theta + M_PI/4*3);
  gfx_line(200, 200, x2, y2);
  gfx_fill_circle(x2, y2, 7);
  x2 = 200 + 160*sin(theta + M_PI/4*4);
  y2 = 200 - 160*cos(theta + M_PI/4*4);
  gfx_line(200, 200, x2, y2);
  gfx_fill_circle(x2, y2, 7);
  x2 = 200 + 160*sin(theta + M_PI/4*4);
  y2 = 200 - 160*cos(theta + M_PI/4*4);
  gfx_line(200, 200, x2, y2);
  gfx_fill_circle(x2, y2, 7);
  x2 = 200 + 160*sin(theta + M_PI/4*5);
  y2 = 200 - 160*cos(theta + M_PI/4*5);
  gfx_line(200, 200, x2, y2);
  gfx_fill_circle(x2, y2, 7);
  x2 = 200 + 160*sin(theta + M_PI/4*6);
  y2 = 200 - 160*cos(theta + M_PI/4*6);
  gfx_line(200, 200, x2, y2);
  gfx_fill_circle(x2, y2, 7);
  x2 = 200 + 160*sin(theta + M_PI/4*7);
  y2 = 200 - 160*cos(theta + M_PI/4*7);
  gfx_line(200, 200, x2, y2);
  gfx_fill_circle(x2, y2, 7);

  // draws outer ring and inner circle 
  gfx_color(204, 102, 0);
  for (int i = 0; i <= 10; i++) {
      gfx_circle(200, 200, 100-i);
      gfx_circle(200, 200, i);
  } 
}
