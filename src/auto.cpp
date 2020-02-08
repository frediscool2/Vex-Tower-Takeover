#include "auto.h"
#include "ControlScheme.h"
#include "stdio.h"

using namespace vex;

void Auto::driveForDistance(double distanceVal, motor Motor, bool wait,
                            distanceUnits distanceUnit, double velVal,
                            velocityUnits velcUnits) {
  switch (distanceUnit) {
  case distanceUnits::cm:
    distanceVal = (distanceVal / 2.54) / Math::cmPerDegree;
    break;
  case distanceUnits::mm:
    distanceVal = (distanceVal * 10) / Math::cmPerDegree;
    break;
  case distanceUnits::in:
    distanceVal = distanceVal / Math::inchesPerDegree;
    break;
  }
  Motor.rotateFor(distanceVal, deg, velVal, velocityUnits::pct, wait);
}

void Auto::spinForDegrees(double distanceVal, motor Motor, bool wait,
                          double velVal, velocityUnits velcUnits) {
  Motor.rotateFor(distanceVal, deg, velVal, velcUnits, wait);
}

void Auto::blueRightAuto() {
  ArmMotors.rotateFor(fwd, 39, deg);
  driveForDistance(23, rightWheelMotor, true);
  // Spin the Intake Motors
  ControllerInteraction::pullIntake();

  // To counter an initial fo    rce from starting the intake system
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

void Auto::redRightAuto() {

  // section 2 spinForDegrees
  ArmMotors.rotateFor(fwd, 10, deg, true);

  IntakeMotors.spin(fwd, 100, pct);
  // collect 4 wih 5th ontop of 4th
  spinForDegrees(1250.4, leftWheelMotor, 60, false);
  spinForDegrees(1199.2, rightWheelMotor, 60, true);

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
  spinForDegrees(1200.4, leftWheelMotor, 60);
  spinForDegrees(1149.2, rightWheelMotor, 60, true);

  spinForDegrees(500, leftWheelMotor, 35, false);
  spinForDegrees(-500, rightWheelMotor, 35, true);

  IntakeMotors.stop();

  dropOff();
}

void Auto::blueLeftAuto() {

  // IS SAME AS RED LEFT NEEDS TO BE CHANGED

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
  spinForDegrees(-310, rightWheelMotor, true);

  // backup into wall FLAG
  spinForDegrees(-1000, leftWheelMotor);
  spinForDegrees(-1270, rightWheelMotor, true);

  wait(50, msec);
  // collect 3
  spinForDegrees(1200.4, leftWheelMotor);
  spinForDegrees(1149.2, rightWheelMotor, true);

  spinForDegrees(-475, leftWheelMotor, 30, false);
  spinForDegrees(475, rightWheelMotor, 30, true);

  IntakeMotors.stop();

  dropOff();
}

void Auto::dropOff() {

  spinForDegrees(607.6, leftWheelMotor);
  spinForDegrees(596, rightWheelMotor, true);

  IntakeMotors.spin(reverse, 100, pct);
  wait(100, msec); // this could be cut down
  IntakeMotors.stop(hold);

  spinForDegrees(-1125.6, leftPistonMotor);
  spinForDegrees(-1125.6, rightPistonMotor, true);

  spinForDegrees(-180, leftIntakeMotor);
  spinForDegrees(-180, rightIntakeMotor);

  spinForDegrees(150, leftPistonMotor);
  spinForDegrees(150, rightPistonMotor, true);

  spinForDegrees(1125.3, leftPistonMotor);
  spinForDegrees(1125.3, rightPistonMotor);

  spinForDegrees(-620.6, leftWheelMotor);
  spinForDegrees(-620.6, rightWheelMotor, true);

  //  spinForDegrees(-464.40, leftIntakeMotor);
  // spinForDegrees(-464.40, rightIntakeMotor, true);
}

void Auto::autoSkills() {
  // Unpack();

  // pushing preload into 4 stack
  spinForDegrees(292, leftWheelMotor, false);
  spinForDegrees(292, rightWheelMotor, true);

  // backing up into wall after pushing preload
  spinForDegrees(-292, leftWheelMotor, false);
  spinForDegrees(-292, rightWheelMotor, true);

  // fold out
  spinForDegrees(-400, rightArmMotor, false, 100);
  spinForDegrees(-400, leftArmMotor, true, 100);

  spinForDegrees(450, rightArmMotor, false, 100);
  spinForDegrees(450, leftArmMotor, true, 100);

  // end fold out
  wait(500, msec);

  // drive forward to preload block in line
  spinForDegrees(155, leftWheelMotor, false);
  spinForDegrees(155, rightWheelMotor, true);

  // drive forward as we collect
  spinForDegrees(125, leftWheelMotor, false, 30);
  spinForDegrees(125, rightWheelMotor, false, 30);

  // collect block
  spinForDegrees(350, leftIntakeMotor, false, 80);
  spinForDegrees(350, rightIntakeMotor, true, 80);

  // turn towards tower
  spinForDegrees(375, leftWheelMotor, false);
  spinForDegrees(-1, rightWheelMotor, true);

  // raise arm while on route to tower
  spinForDegrees(-575, leftArmMotor, false, 100);
  spinForDegrees(-575, rightArmMotor, true, 100);

  // drive towards tower
  spinForDegrees(255, leftWheelMotor, false, 30);
  spinForDegrees(260, rightWheelMotor, true, 30);

  spinForDegrees(-1000, leftIntakeMotor, false, 100);
  spinForDegrees(-1000, rightIntakeMotor, true, 100);

  // turn towards wall with back facing at an angle
  spinForDegrees(-260, leftWheelMotor, false);
  spinForDegrees(-26, rightWheelMotor, true);
  wait(2, sec);

  // lower arm
  spinForDegrees(600, leftArmMotor, false, 100);
  spinForDegrees(600, rightArmMotor, false, 100);

  // backup into wall
  spinForDegrees(-574, leftWheelMotor, false);
  spinForDegrees(-550, rightWheelMotor, true);

  spinForDegrees(-95, leftWheelMotor, true);

  IntakeMotors.spin(fwd, 100, pct);

  spinForDegrees(1320, leftWheelMotor);
  spinForDegrees(1310, rightWheelMotor, true, 50);

  // ~~~ 3 blocks or 4 picked up just about to hit tower at this point~~~

  // just straight
  spinForDegrees(2610, leftWheelMotor);
  spinForDegrees(2600, rightWheelMotor, true, 50);

  //~~~ DROP OFF ~~~
  spinForDegrees(-50, rightWheelMotor, false);
  spinForDegrees(250, leftWheelMotor, true);

  IntakeMotors.stop(hold);

  spinForDegrees(200, rightWheelMotor, false, 30);
  spinForDegrees(200, leftWheelMotor, true, 30);

  spinForDegrees(-125, leftIntakeMotor);
  spinForDegrees(-125, rightIntakeMotor);

  spinForDegrees(50, rightWheelMotor, false, 20);
  spinForDegrees(50, leftWheelMotor, false, 20);

  spinForDegrees(900.6, leftPistonMotor, false);
  spinForDegrees(900.6, rightPistonMotor, true);

  spinForDegrees(50, leftPistonMotor, false, 20);
  spinForDegrees(50, rightPistonMotor, true, 20);

  // why do we do this?

  spinForDegrees(-1125.3, leftPistonMotor);
  spinForDegrees(-1125.3, rightPistonMotor);

  wait(100, msec);

  IntakeMotors.spin(reverse, 50, pct);

  wait(250, msec);

  spinForDegrees(-620.6, leftWheelMotor);
  spinForDegrees(-620.6, rightWheelMotor, true);
  // end drop off
}

void Auto::Unpack() {
  auto movement = 20;
  // Move the arms to unfold the ramp
  ArmMotors.rotateFor(fwd, movement, deg, true);
  ArmMotors.rotateFor(reverse, movement + 5, deg, true);
}