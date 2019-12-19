#include "auto.h"
#include "ControlScheme.h"
#include "stdio.h" #

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
  spinForDegrees(1250.4, leftWheelMotor, false, 60);
  spinForDegrees(1199.2, rightWheelMotor, true, 60);

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
  spinForDegrees(1200.4, leftWheelMotor, false, 60);
  spinForDegrees(1149.2, rightWheelMotor, true, 60);

  spinForDegrees(500, leftWheelMotor, false, 35);
  spinForDegrees(-500, rightWheelMotor, true, 35);

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

  spinForDegrees(-475, leftWheelMotor, false, 30);
  spinForDegrees(475, rightWheelMotor, true, 30);

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
  spinForDegrees(-50, rightWheelMotor);
  spinForDegrees(250, leftWheelMotor, true);

  spinForDegrees(475, leftWheelMotor);
  spinForDegrees(455, rightWheelMotor);

  spinForDegrees(-225, leftPistonMotor, true);
  spinForDegrees(-225, rightPistonMotor);

  spinForDegrees(-440, rightArmMotor, 70); // raises arm too high at 460
  spinForDegrees(-440, leftArmMotor, true, 70);

  spinForDegrees(-720, leftIntakeMotor);
  spinForDegrees(-720, rightIntakeMotor, true);

  // after tower
  spinForDegrees(440, rightArmMotor, 70);
  spinForDegrees(440, leftArmMotor, 70);

  spinForDegrees(225, leftPistonMotor);
  spinForDegrees(225, rightPistonMotor);

  // I want to switch this to a set rotation instead of a constant spin
  IntakeMotors.spin(fwd, 100, pct);

  spinForDegrees(-75, rightWheelMotor);
  spinForDegrees(-425, leftWheelMotor, true);

  spinForDegrees(50, leftWheelMotor, true);

  spinForDegrees(1990, leftWheelMotor);
  spinForDegrees(1210, rightWheelMotor, true);

  IntakeMotors.stop(hold);
}