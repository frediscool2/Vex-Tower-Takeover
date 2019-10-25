#include "vex.h"
// this comment is here because they auto format formats include lines by
// alphabetical order which fucks up some dependancies
#include <iostream>

class ControllerInteraction {

public:
  static void leftJoystickChange() {
    leftMotors.setVelocity(Controller.Axis3.position(pct), pct);
    leftMotors.spin(fwd);
    std::cout << Controller.Axis3.position(pct);
    wait(10, msec);
  }

public:
  static void rightJoystickChange() {
    rightMotors.setVelocity(Controller.Axis2.position(pct), pct);
    rightMotors.spin(fwd);
    std::cout << Controller.Axis2.position(pct);
    wait(10, msec);
  }

public:
  static void bL1Pressed() {
    // Intake Motor fwd 50% power
    intakeMotors.setVelocity(50, pct);
    intakeMotors.spin(fwd);
  }

public:
  static void bL2Pressed() {
    // Intake Motor rev 50% power
    intakeMotors.setVelocity(50, pct);
    intakeMotors.spin(reverse);
  }

public:
  static void bL3Pressed() {
    // Arm Motor Forward
    armMotor.setVelocity(50, pct);
    armMotor.spin(fwd);
  }

public:
  static void cLPressed() {
    // Arm Motor Reverse 50% power
    armMotor.setVelocity(50, pct);
    armMotor.spin(reverse);
  }

  /* empty functions will be called later once the drive team figures out their
   * layout*/
public:
  static void bR1Pressed() {
    leftMotors.rotateFor(4, rotationUnits::rev, 50, velocityUnits::pct, false);

    rightMotors.rotateFor(4, rotationUnits::rev, 50, velocityUnits::pct, true);
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
    pistonMotor.spin(reverse);
  }

  // Released Functions
public:
  static void bLReleased() {
    // Stopping Left Intake Motor
    intakeMotors.stop();
  }

public:
  static void bL3Released() {
    // Stopping Arm Motor
    armMotor.stop();
  }

public: // right bumper release
  static void bRReleased() { intakeMotors.stop(); }

public:
  static void bR3Released() {
    // Stopping  Piston Motor
    pistonMotor.stop();
  }
};