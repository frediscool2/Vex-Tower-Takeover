#include "vex.h"
// Array contains the data for the circles in this format
// x_center, y_center, radius

int circleData[6][3] = {
    {150, 136, 110}, // Start circle main menu
    {345, 136, 110}, // Auto select circle main menu
    {63, 136, 56},   // Auto 1 circle
    {181, 136, 56},  // Auto 2 circlle
    {299, 136, 56},  // Auto 3 circle
    {417, 136, 56},  // Auto 4 circle
};

class Circle {
public:
  // setting up our constructor
  int dx, dy, r;
  Circle(int dx_, int dy_, int r_) {
    dx = dx_;
    dy = dy_;
    r = r_;
  }

  // getter functions
  int getDX() { return dx; }
  int getDY() { return dy; }
  int getRadius() { return r; }

  // setter function
  void setDX(int dx_) { dx = dx_; }
  void setDY(int dy_) { dy = dy_; }
  void setRadius(int r_) { r = r_; }
};

class GUI {
  // displays main menu
  enum STATE { MAIN_MENU, AUTO_SELECT, RUNNING };
  STATE currentState;
Circle a = Circle(1,1,1);
  void intiGUI() {
    // Start Circle and Auto Select Circle
    Brain.Screen.drawCircle(150, 136, 110, red);
    Brain.Screen.drawCircle(345, 136, 110, red);
   
    Brain.Screen.printAt(20, 110, true, "Start");
    Brain.Screen.printAt(270, 110, true, "Auto Select");

    currentState = MAIN_MENU;
  }

  void displayAutoSelect() {
    // i did math to get these values it should look peRfeCTo
    Brain.Screen.drawCircle(63, 136, 56);  // auto 1
    Brain.Screen.drawCircle(181, 136, 56); // auto 2
    Brain.Screen.drawCircle(299, 136, 56); // auto 3
    Brain.Screen.drawCircle(417, 136, 56); // auto 4

    // VALUES ARE PLACEHOLDERS
    Brain.Screen.printAt(20, 110, true, "Start");
    Brain.Screen.printAt(270, 110, true, "Auto Select");
    Brain.Screen.printAt(20, 110, true, "Start");
    Brain.Screen.printAt(270, 110, true, "Auto Select");

    currentState = AUTO_SELECT;
  }

  // https://stackoverflow.com/questions/481144/equation-for-testing-if-a-point-is-inside-a-circle#481150
  bool isCirclePressed(int circleData[]) {
    int dx, dy, r;

    dx = abs(Brain.Screen.xPosition() - circleData[0]);
    dy = abs(Brain.Screen.yPosition() - circleData[1]);
    r = circleData[2];

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
  void screenPressed() {
    switch (currentState) {
    case MAIN_MENU:
      if (isCirclePressed(circleData[0])) {
        Controller.rumble(".");
        Controller.Screen.clearScreen();
        Controller.Screen.print("Start button was pressed!");
        return;
      }
      if (isCirclePressed(circleData[1])) {
        Controller.rumble(". .");
        Controller.Screen.clearScreen();
        Controller.Screen.print("Auto Select button was pressed!");
        return;
      }

    case AUTO_SELECT:
      if (isCirclePressed(circleData[2])) {
        Controller.rumble(". . .");
        Controller.Screen.clearScreen();
        Controller.Screen.print("Auto 1 button was pressed!");
        return;
      }

      if (isCirclePressed(circleData[3])) {
        Controller.rumble(". . . .");
        Controller.Screen.clearScreen();
        Controller.Screen.print("Auto 2 button was pressed!");
        return;
      }

      if (isCirclePressed(circleData[4])) {
        Controller.rumble(". . . . .");
        Controller.Screen.clearScreen();
        Controller.Screen.print("Auto 3 button was pressed!");
        return;
      }

      if (isCirclePressed(circleData[5])) {
        Controller.rumble(". . . . . .");
        Controller.Screen.clearScreen();
        Controller.Screen.print("Auto 4 button was pressed!");
        return;
      }
    case RUNNING:
      break;
    }
  }
};