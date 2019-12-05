#include "auto.h"
#include "stdio.h"
using namespace vex;

void waitFoo() { wait(5, sec); }

void Auto::driveForDistance(double distanceVal, motor Motor,
                            distanceUnits distanceUnit, bool wait,
                            double velVal, velocityUnits velcUnits) {
  switch (distanceUnit) {
    Controller.Screen.setCursor(3, 0);
    Controller.Screen.clearLine();
  case distanceUnits::cm:
    Controller.Screen.print("CM In Switch;");
    distanceVal = (distanceVal / 2.54) / Math::cmPerDegree;
    break;
  case distanceUnits::mm:
    Controller.Screen.print("mm In Switch;");
    distanceVal = (distanceVal * 10) / Math::cmPerDegree;
    break;
  case distanceUnits::in:
    Controller.Screen.print("inch In Switch;");
    distanceVal = distanceVal / Math::inchesPerDegree;
    break;
  default:
    Controller.Screen.print("Default");
    break;
  }

  Controller.Screen.setCursor(3, 0);
  Controller.Screen.clearLine();
  Controller.Screen.print("Starting Rotate For");
  Motor.rotateFor(distanceVal, deg, velVal, velocityUnits::pct, wait);
  Controller.Screen.clearLine();
  Controller.Screen.print("Rotate For End");
}

void Auto::spinForDegrees(double distanceVal, motor Motor, bool wait,
                          double velVal, velocityUnits velcUnits) {
  Motor.rotateFor(distanceVal, deg, velVal, velcUnits, wait);
}

// Left side autonomous of the blue side
// Note: Left is refering to the the left of someone looking at blue side to the
// red side
void Auto::blueLeftAuto() { ; }

// Left side autonomous of the blue side
// Note: Right is refering to the the right of someone looking at blue side to
// the red side
void Auto::blueRightAuto() {}

// Left side autonomous of the blue side
// Note: Left is refering to the the left of someone looking at red side to the
// blue side
void Auto::redLeftAuto() {}

// Left side autonomous of the blue side
// Note: Right is refering to the the right of someone looking at red side to
// the blue side
void Auto::redRightAuto() {

  // section 1
  /* driveForDistance((distanceUnits)deg, 1087.2, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, 1058.4, 50, RightMotors, true);

   driveForDistance((distanceUnits)deg, -568, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, -251.6, 50, RightMotors, true);

   driveForDistance((distanceUnits)deg, 0000, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, 0000, 50, RightMotors, true);

   driveForDistance((distanceUnits)deg, 0000, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, 0000, 50, RightMotors, true);
 */
  // section 2 spinForDegrees
  spinForDegrees(1150.4, leftWheelMotor);
  spinForDegrees(1099.2, rightWheelMotor, true);

  
  // debug(SHOULD BE DONE ALREADY BEFORE HITTING HERE IF NOT ERROR WITH WAIT
  // BOOL)

  spinForDegrees(-269.6, leftWheelMotor);
  spinForDegrees(-270.8, rightWheelMotor, true);

  spinForDegrees(-732, leftWheelMotor);
  spinForDegrees(86, rightWheelMotor, true);

  spinForDegrees(411.2, leftWheelMotor);
  spinForDegrees(428.4, rightWheelMotor, true);

  spinForDegrees(-295.2, leftWheelMotor);
  spinForDegrees(-507.2, rightWheelMotor, true);
}