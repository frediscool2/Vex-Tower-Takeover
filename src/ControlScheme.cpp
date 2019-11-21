#include "vex.h"
// this comment is here because they auto format formats include lines by
// alphabetical order which fucks up some dependancies
#include <iostream>

class ControllerInteraction {

public:
  static void leftJoystickChange() {
    leftMotors.setVelocity(Controller.Axis3.position(pct), velocityUnits::pct);
    leftMotors.spin(fwd);
  }

  static void rightJoystickChange() {
    rightMotors.setVelocity(Controller.Axis2.position(pct), velocityUnits::pct);
    rightMotors.spin(fwd);
  }

  static void bL1Pressed() {
    // Intake Motor fwd 50% power
    intakeMotors.setVelocity(50, velocityUnits::pct);
    intakeMotors.spin(fwd);
  }

  static void bL2Pressed() {
    // Intake Motor rev 50% power
    intakeMotors.setVelocity(50, velocityUnits::pct);
    intakeMotors.spin(directionType::rev);
  }

  static void bL3Pressed() {
    // Arm Motor Forward
    armMotor.setVelocity(50, pct);
    armMotor.spin(fwd);
  }

  static void cLPressed() {
    // Arm Motor Reverse 50% power
    armMotor.setVelocity(50, pct);
    armMotor.spin(directionType::rev);
  }

  /* empty functions will be called later once the drive team figures out their
   * layout*/
  static void bR1Pressed() {
    //    ObjectTracking::setVisionIndex(ObjectTracking::getVisionIndex() + 1);

    driveForDistance(distanceUnits::cm, 111.76, velocityUnits::pct, 50,
                     leftMotors);
    driveForDistance(distanceUnits::cm, 111.76, velocityUnits::pct, 50,
                     rightMotors);
  }

  static void bR2Pressed() {}

  static void bR3Pressed() {
    // Piston Motor Forward 50% power
    pistonMotor.setVelocity(50, pct);
    pistonMotor.spin(fwd);
  }

  static void cRPressed() {
    // Arm Motor Forward 50% power
    pistonMotor.setVelocity(100, pct);
    pistonMotor.spin(directionType::rev);
  }

  // Released Functions
  static void bLReleased() {
    // Stopping Left Intake Motor
    intakeMotors.stop();
  }

  static void bL3Released() {
    // Stopping Arm Motor
    armMotor.stop(hold);
  }

  static void cLReleased() { armMotor.stop(hold); }

  // right bumper release
  static void bRReleased() { intakeMotors.stop(); }

  static void bR3Released() {
    // Stopping  Piston Motor
    pistonMotor.stop();
  }

  static void driveForDistance(distanceUnits distanceUnit, double distanceVal,
                               velocityUnits velcUnit, double velVal,
                               motor_group motorGroup) {
    if (distanceUnit == distanceUnits::cm) {
      distanceVal = distanceVal / 2.54;
    } else if (distanceUnit == mm) {
      distanceVal = (distanceVal * 10) / 2.54;
    }

    double inchesPerDegree = (3.14159 * 3.25) / 360;
    distanceVal = distanceVal / inchesPerDegree;

    motorGroup.rotateTo(distanceVal, deg, velVal, velcUnit, false);
  }

  static void driveForDistance(distanceUnits distanceUnit, double distanceVal,
                               velocityUnits velcUnit, double velVal,
                               motor motorGroup) {
    if (distanceUnit == distanceUnits::cm) {
      distanceVal = distanceVal / 2.54;
    } else if (distanceUnit == mm) {
      distanceVal = (distanceVal * 10) / 2.54;
    }

    double inchesPerDegree = (3.14159 * 3.25) / 360;
    distanceVal = distanceVal / inchesPerDegree;

    motorGroup.rotateTo(distanceVal, deg, velVal, velcUnit, false);
  }
};