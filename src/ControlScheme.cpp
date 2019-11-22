#include "vex.h"
// this comment is here because they auto format formats include lines by
// alphabetical order which fucks up some dependancies
#include <iostream>

class ControllerInteraction {

public:
  static void moveLeftSide() {
    leftMotors.setVelocity(Controller.Axis3.position(pct), velocityUnits::pct);
    leftMotors.spin(fwd);
  }

  static void moveRightSide() {
    rightMotors.setVelocity(Controller.Axis2.position(pct), velocityUnits::pct);
    rightMotors.spin(fwd);
  }

  static void pushIntake() {
    // Intake Motor fwd 50% power
    intakeMotors.setVelocity(50, velocityUnits::pct);
    intakeMotors.spin(fwd);
  }

  static void pullIntake() {
    // Intake Motor rev 50% power
    intakeMotors.setVelocity(50, velocityUnits::pct);
    intakeMotors.spin(directionType::rev);
  }

  static void liftArm() {
    // Arm Motor Forward
    armMotor.setVelocity(50, pct);
    armMotor.spin(fwd);
  }

  static void lowerArm() {
    // Arm Motor Reverse 50% power
    armMotor.setVelocity(50, pct);
    armMotor.spin(directionType::rev);
  }

  static void pistonExtend() {
    // Piston Motor Forward 50% power
    pistonMotor.setVelocity(50, pct);
    pistonMotor.spin(fwd);
  }

  static void pistonRetract() {
    // Arm Motor Forward 50% power
    pistonMotor.setVelocity(100, pct);
    pistonMotor.spin(directionType::rev);
  }

  // Released Functions
  static void stopIntake() {
    // Stopping Left Intake Motor
    intakeMotors.stop();
  }

  static void stopArm() {
    // Stopping Arm Motor
    armMotor.stop(hold);
  }

  static void stopPiston() {
    // Stopping  Piston Motor
    pistonMotor.stop();
  }
};