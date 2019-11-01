#include "vex.h"
// this comment is here because they auto format formats include lines by
// alphabetical order which fucks up some dependancies
#include "ObjectTracking.cpp"
#include <iostream>

class ControllerInteraction {

public:
  static void leftJoystickChange() {
    leftMotors.setVelocity(Controller.Axis3.position(pct), velocityUnits::pct);
    leftMotors.spin(fwd);
    task::sleep(10);
  }

public:
  static void rightJoystickChange() {
    rightMotors.setVelocity(Controller.Axis2.position(pct), velocityUnits::pct);
    rightMotors.spin(fwd);
    task::sleep(10);
  }

public:
  static void bL1Pressed() {
    // Intake Motor fwd 50% power
    intakeMotors.setVelocity(50, velocityUnits::pct);
    intakeMotors.spin(fwd);
    task::sleep(10);
  }

public:
  static void bL2Pressed() {
    // Intake Motor rev 50% power
    intakeMotors.setVelocity(50, velocityUnits::pct);
    intakeMotors.spin(directionType::rev);
    task::sleep(10);
  }

public:
  static void bL3Pressed() {
    // Arm Motor Forward
    armMotor.setVelocity(50, pct);
    armMotor.spin(fwd);
    task::sleep(10);
  }

public:
  static void cLPressed() {
    // Arm Motor Reverse 50% power
    armMotor.setVelocity(50, pct);
    armMotor.spin(directionType::rev);
    task::sleep(10);
  }

  /* empty functions will be called later once the drive team figures out their
   * layout*/
public:
  static void bR1Pressed() {
//    ObjectTracking::setVisionIndex(ObjectTracking::getVisionIndex() + 1);
  }

public:
  static void bR2Pressed() {}

public:
  static void bR3Pressed() {
    // Piston Motor Forward 50% power
    pistonMotor.setVelocity(50, pct);
    pistonMotor.spin(fwd);
  }

public:
  static void cRPressed() {
    // Arm Motor Forward 50% power
    pistonMotor.setVelocity(50, pct);
    pistonMotor.spin(directionType::rev);
    task::sleep(10);
  }

  // Released Functions
public:
  static void bLReleased() {
    // Stopping Left Intake Motor
    intakeMotors.stop();
    task::sleep(10);
  }

public:
  static void bL3Released() {
    // Stopping Arm Motor
    armMotor.stop();
    task::sleep(10);
  }

public: // right bumper release
  static void bRReleased() { intakeMotors.stop(); }

public:
  static void bR3Released() {
    // Stopping  Piston Motor
    pistonMotor.stop();
  }
};