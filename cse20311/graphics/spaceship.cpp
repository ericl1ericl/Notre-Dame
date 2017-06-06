// spaceship.cpp
//
// The program displays a tiny triangular spaceship with user control,
//  either with wasd keys or with arrow keys
//   'w' or up arrow for acceleration
//   'a' or left arrow for left turn
//   's' or down arrow for deceleration
//   'd' or right arrow for right turn
// When the spaceship goes to one end of the screen,
//  it is teleported to the other end.
//

#include <iostream>
using std::cout;
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include "gfx.h"
using namespace std;

void drawSpaceship(float posx, float posy, float theta, float size);

int main() {
  const float WINDOW_WID = 700;    // window size
  const float WINDOW_HGT = 500;

  float posx = WINDOW_WID / 2;     // initial spaceship position
  float posy = WINDOW_HGT / 2;
  const float size = 20;   // spaceship size
  float theta = 0;         // begins straight up, redefined theta coordinates
  float velocity = 2;      // initial velocity

  char event;              // get the key press
  bool loop = true;        // flag to check for animation termination

  gfx_open (WINDOW_WID, WINDOW_HGT, "Spaceship");   // open a window
  gfx_color(255, 255, 0);  // set color to yellow

  // display help menu for user
  cout << "  'w' or up arrow for acceleration\n";
  cout << "  'a' or left arrow for left turn\n";
  cout << "  's' or down arrow for deceleration\n";
  cout << "  'd' or right arrow for right turn\n";

  // start the continuous loop; keep looping while "loop" is true
  while(loop) {  

    gfx_clear();   // clear the screen

    // draw the spaceship
    drawSpaceship(posx, posy, theta, size);

    gfx_flush();   // flush the output

    posx = posx + velocity * sin(theta);
    posy = posy - velocity * cos(theta);

    usleep(8000);  // pause for 8 milliseconds

    // let user change the speed and direction of the spaceship
    // either with wasd keys or with arrow keys
    if (gfx_event_waiting()) {
      event = gfx_wait();
//      cout << event << endl;
      switch (event) {
      // accelerate
        case 'w':
        case 'R':  // 'R' is up arrow
          velocity = velocity + 0.25;
        break;
      // left turn
        case 'a':
        case 'Q':  // 'Q' is left arrow
          theta = theta - 0.25;
        break;
      // decelerate
        case 's':
        case 'T':  // 'T' is down arrow
          velocity = (velocity-0.25 < 0) ? 0 : velocity - 0.25;
        break;
      // right turn
        case 'd':
        case 'S':  // 'S' is right arrow
          theta = theta + 0.25;
        break;
      // quit
        case 'q':  // hitting the 'q' key quits the animation 
          loop = false;
        break;
      }
    }

    // Detect collision
    if (posx < 0)
      posx = WINDOW_WID;
    else if (posx > WINDOW_WID)
      posx = 0;

    if (posy < 0)
      posy = WINDOW_HGT;
    else if (posy > WINDOW_HGT)
      posy = 0;
  }

  return 0;
}

// Draw a triangular spaceship
// Arguments:
//  - posx and posy: center reference of spaceship
//  - theta: angle of spaceship with respect to vertical
//  - size: length from center to top corner
void drawSpaceship(float posx, float posy, float theta, float size) {
  float xTop, yTop, xBotLeft, yBotLeft, xBotRight, yBotRight;

  // Determine positions of the corners
  const float ang = 2*M_PI/3;
  xTop = posx + size * sin(theta);
  yTop = posy - size * cos(theta);
  xBotLeft = posx + 0.5 * size * sin(theta - ang);
  yBotLeft = posy - 0.5 * size * cos(theta - ang);
  xBotRight = posx + 0.5 * size * sin(theta + ang);
  yBotRight = posy - 0.5 * size * cos(theta + ang);

  // Actual drawing
  gfx_line(xTop, yTop, xBotLeft, yBotLeft);
  gfx_line(xBotLeft, yBotLeft, xBotRight, yBotRight);
  gfx_line(xBotRight, yBotRight, xTop, yTop);
}

