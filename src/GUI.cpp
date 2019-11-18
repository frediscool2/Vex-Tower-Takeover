#include "vex.h"
#include <vector>

using namespace std;
enum STATE { MAIN_MENU, AUTO_SELECT, RUNNING };

class Circle {
public:
  // setting up our constructor
  int dx, dy, r;
  STATE triggerState;

  /*
  @param dx_ = center_x of the circle
  @param dy_ = center_y of the circle
  @param r_ = radius of the circle
  @param triggerState = when the circle/bound is pressed the currentState of GUI
      will switch to this value
  */

  /*
  TODO:
    -Convert Circle -> Button
      -Add a string x,y postion arg
      -Add a string text arg
      -Add a buttonName to output ButtonName was selected debug feature that
  will be removed later

    way more then that just all I can think of its 11pm and I wrote this all in
  one day without any testing so you know bugs
  */
  Circle(int dx_, int dy_, int r_, STATE triggerState_) {
    dx = dx_;
    dy = dy_;
    r = r_;
    triggerState = triggerState_;
  }

  // getter functions
  int getDX() { return dx; }
  int getDY() { return dy; }
  int getRadius() { return r; }
  STATE getTriggerState() { return triggerState; }

  // setter function
  void setDX(int dx_) { dx = dx_; }
  void setDY(int dy_) { dy = dy_; }
  void setRadius(int r_) { r = r_; }
  void getTriggerState(STATE triggerState_) { triggerState = triggerState_; }
};

// i did math to get these values it should look peRfeCTo or trash
// ¯\_(ツ)_/¯
vector<Circle> menuBounds = {
    Circle(150, 136, 110, RUNNING),    // start circle
    Circle(150, 136, 110, AUTO_SELECT) // auto select circle
};

vector<Circle> autoBounds = {
    Circle(63, 136, 56, MAIN_MENU),  // auto 1 circle
    Circle(181, 136, 56, MAIN_MENU), // auto 2 circle
    Circle(299, 136, 56, MAIN_MENU), // auto 3 circle
    Circle(417, 136, 56, MAIN_MENU)  // auto 4 circle
};

// placeholder ***
vector<Circle> runningBounds = {};

// god this is ugly
class GUI {
  STATE currentState;

  void updateScreen() {
    // see screen pressed so this makes sense
    /*thats right folks I am using a function with a switch statment to call a
     * function with the exact same switch statement but with a different
     * operation within it. */

    switch (currentState) {
    case MAIN_MENU:
      displayMainMenu();
      break;
    case AUTO_SELECT:
      displayAutoSelect();
      break;
    case RUNNING:
      displayRunning();
      break;
    }
  }

  void displayMainMenu() {
    for (Circle circle : menuBounds) {
      Brain.Screen.drawCircle(circle.getDX(), circle.getDY(),
                              circle.getRadius());
    }

    // VALUES ARE PLACEHOLDERS MOVE TO ENHCANCED FOR LOOP AFTER
    Brain.Screen.printAt(20, 110, true, "Start");
    Brain.Screen.printAt(270, 110, true, "Auto Select");

    currentState = MAIN_MENU;
  }

  void displayAutoSelect() {
    for (Circle circle : autoBounds) {
      // Drawing circle bounds
      Brain.Screen.drawCircle(circle.getDX(), circle.getDY(),
                              circle.getRadius());
    }

    // VALUES ARE PLACEHOLDERS MOVE TO ENHCANCED FOR LOOP AFTER
    Brain.Screen.printAt(20, 110, true, "Start");
    Brain.Screen.printAt(270, 110, true, "Auto Select");
    Brain.Screen.printAt(20, 110, true, "Start");
    Brain.Screen.printAt(270, 110, true, "Auto Select");

    currentState = AUTO_SELECT;
  }

  // placeholder
  void displayRunning() {
    for (Circle circle : runningBounds) {
      Brain.Screen.drawCircle(circle.getDX(), circle.getDY(),
                              circle.getRadius());
    }
  }

  // https://stackoverflow.com/questions/481144/equation-for-testing-if-a-point-is-inside-a-circle#481150
  bool isCirclePressed(Circle bound) {
    int dx, dy, r;

    dx = abs(Brain.Screen.xPosition() - bound.getDX());
    dy = abs(Brain.Screen.yPosition() - bound.getDY());
    r = bound.getRadius();

    if (dx + dy <= r) {
      return true;
    }
    if (dx > r) {
      return false;
    }
    if (dy > r) {
      return false;
    }
    if (dx ^ 2 + dy ^ 2 <= r ^ 2) {
      return true;
    }
    return false;
  }

public:
  /*ok so here is the thing I fucking hate this right now. Let me clarify the
   * function is just ugly. a return and break function come on. Yes they server
   * a purpose but there has to be and is a better way to do this but its 11:30
   * and I am tired. see updateScreen for the other issue with this\

    We calll the update screen function which has this same switch statement
   because we dont know what the state is going to change to once a button is
   pressed we know it will be that buttons triggerState but we dont know what
   that state is so we cannont display the correct ui. We to call another
   function and check the current state their we could have a chain of ifs in
   teh switch but I would hang myself first this is ugly already

   end rant

   oh also we do not need to call it in every case we can just call it after the
   switch but we have to change up the return and breaks. The return is to
   prevent wasted resources looping through the rest of the array again a
   miiscule impact but good practice
   */

  void screenPressed() {
    switch (currentState) {
    case MAIN_MENU:
      for (Circle bound : menuBounds) {
        if (isCirclePressed(bound)) {
          currentState = bound.getTriggerState();
          updateScreen();
          return;
        }
      }
      break;
    case AUTO_SELECT:
      for (Circle bound : autoBounds) {
        if (isCirclePressed(bound)) {
          currentState = bound.getTriggerState();
          updateScreen();
          return;
        }
      }
      break;

    case RUNNING:
      for (Circle bound : runningBounds) {
        if (isCirclePressed(bound)) {
          currentState = bound.getTriggerState();
          updateScreen();
          return;
        }
      }
      break;
    }
  }
};