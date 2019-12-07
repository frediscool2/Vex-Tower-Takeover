#include "auto.h"
#include "ControlScheme.h"
#include "stdio.h" #

using namespace vex;

void waitFoo() { wait(5, sec); }

void Auto::driveForDistance(double distanceVal, motor Motor, bool wait,
                            distanceUnits distanceUnit, double velVal,
                            velocityUnits velcUnits) {
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
// red side ETHAN

// Left side autonomous of the blue side
// Note: Right is refering to the the right of someone looking at blue side to
// the red side THAYEN
void Auto::blueRightAuto() {
  ArmMotors.rotateFor(fwd, 39, deg);
  driveForDistance(23, rightWheelMotor, true);
  // Spin the Intake Motors
  ControllerInteraction::pullIntake();

  // To counter an initial force from starting the intake system
  rightWheelMotor.spinFor(directionType::fwd, 20, deg);

  // Drive forward towards the first block
  driveForDistance(35, leftWheelMotor, false);
  driveForDistance(35, rightWheelMotor, true);

  // Spin 45 degress towards the last block
  leftWheelMotor.spinFor(directionType::fwd, 990.4, deg);

  // Drive forwards towards the last block
  driveForDistance(37, rightWheelMotor, false);
  driveForDistance(37, leftWheelMotor, true);

  // Stop the motors from spinning
  IntakeMotors.stop();

  // Drop off
}

// Left side autonomous of the blue side
// Note: Left is refering to the the left of someone looking at red side to the
// blue side THAYEN
void Auto::redLeftAuto() {
  IntakeMotors.spin(fwd, 100, velocityUnits::pct);
  driveForDistance(23, leftWheelMotor);
  driveForDistance(23, rightWheelMotor, true);

  driveForDistance(5, leftWheelMotor);
  driveForDistance(5, rightWheelMotor, true);

  ArmMotors.rotateTo(30, deg);

  driveForDistance(36, leftWheelMotor);
  driveForDistance(36, rightWheelMotor, true);
}

// Left side autonomous of the blue side
// Note: Left is refering to the the left of someone looking at blue side to the
// red side ETHAN
// Left side autonomous of the blue side
// Note: Right is refering to the the right of someone looking at red side to
// the blue side ETHAN
void Auto::redRightAuto() {

  // section 2 spinForDegrees
  ArmMotors.rotateFor(fwd, 20, deg, true);
  IntakeMotors.spin(fwd, 100, pct);
  // collect 4 wih 5th ontop of 4th
  spinForDegrees(1250.4, leftWheelMotor, false);
  spinForDegrees(1199.2, rightWheelMotor, true);

  // backup
  spinForDegrees(-269.6, leftWheelMotor);
  spinForDegrees(-270.8, rightWheelMotor, true);

  // turn left FLAG
  spinForDegrees(-310, leftWheelMotor, true);

  // backup into wall FLAG
  spinForDegrees(-1000, leftWheelMotor);
  spinForDegrees(-1270, rightWheelMotor, true);

  wait(50, msec);
  // collect 3
  spinForDegrees(1200.4, leftWheelMotor);
  spinForDegrees(1149.2, rightWheelMotor, true);

  spinForDegrees(475, leftWheelMotor, false, 30);
  spinForDegrees(-475, rightWheelMotor, true, 30);

  IntakeMotors.stop();

  dropOff();

  /*spinForDegrees(-732, leftWheelMotor);
  spinForDegrees(86, rightWheelMotor, true);

  return;

  spinForDegrees(411.2, leftWheelMotor);
  spinForDegrees(428.4, rightWheelMotor, true);

  spinForDegrees(-295.2, leftWheelMotor);
  spinForDegrees(-507.2, rightWheelMotor, true);*/
}

void Auto::blueLeftAuto() {}

void Auto::dropOff() {

  spinForDegrees(607.6, leftWheelMotor);
  spinForDegrees(596, rightWheelMotor, true);

  IntakeMotors.stop(hold);

  spinForDegrees(-1174.6, leftPistonMotor);
  spinForDegrees(-1174.6, rightPistonMotor, true);

  spinForDegrees(587.3, leftPistonMotor);
  spinForDegrees(587.3, rightPistonMotor, true);

  IntakeMotors.spin(reverse, 100, pct);

  wait(100, msec);

  spinForDegrees(-607.6, leftWheelMotor);
  spinForDegrees(-596, rightWheelMotor, true);

  IntakeMotors.stop();

  //  spinForDegrees(-464.40, leftIntakeMotor);
  // spinForDegrees(-464.40, rightIntakeMotor, true);
}