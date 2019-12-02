#include "auto.h"
#include "stdio.h"

void Auto::driveForDistance(double distanceVal, motor Motor, bool wait,
                            double velVal, velocityUnits velcUnits,
                            distanceUnits distanceUnit) {
  switch (distanceUnit) {
    Controller.Screen.setCursor(3, 0);
    Controller.Screen.clearLine();
  case distanceUnits::cm:
    Controller.Screen.print("CM In Switch;");

    distanceVal = (distanceVal / 2.54) / Math::cmPerDegree;
    break;
  case distanceUnits::mm:
    Controller.Screen.print("CM In Switch;");
    distanceVal = (distanceVal * 10) / Math::cmPerDegree;
    break;
  case distanceUnits::in:
    Controller.Screen.print("CM In Switch;");
    distanceVal = distanceVal / Math::inchesPerDegree;
    break;
  }
  Controller.Screen.setCursor(3, 0);
  Controller.Screen.clearLine();
  Controller.Screen.print("Starting Rotate For");
  Motor.rotateFor(distanceVal, deg, velVal, velocityUnits::pct, wait);
  Controller.Screen.clearLine();
  Controller.Screen.print("Rotate For End");
}

// Left side autonomous of the blue side
// Note: Left is refering to the the left of someone looking at blue side to the
// red side
void Auto::blueLeftAuto() {}

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
  // section 2
  driveForDistance(1150.4, leftWheelMotor);
  driveForDistance(1099.2, rightWheelMotor, true);

  // debug(SHOULD BE DONE ALREADY BEFORE HITTING HERE IF NOT ERROR WITH WAIT
  // BOOL)
  if (leftWheelMotor.isDone() && rightWheelMotor.isDone()) {
    return;
  }

  driveForDistance(-269.6, leftWheelMotor);
  driveForDistance(-270.8, rightWheelMotor, true);

  driveForDistance(86, leftWheelMotor);
  driveForDistance(-732, rightWheelMotor, true);

  driveForDistance(411.2, leftWheelMotor);
  driveForDistance(428.4, rightWheelMotor, true);

  driveForDistance(-295.2, leftWheelMotor);
  driveForDistance(-507.2, rightWheelMotor, true);
}