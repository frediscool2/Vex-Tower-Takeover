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
    intakeMotors.spin(fwd, 50, pct);
  }

  static void pullIntake() {
    // Intake Motor rev 50% power
    intakeMotors.spin(reverse, 50, pct);
  }

  static void liftArm() {
    // Arm Motor Forward
    armMotors.spin(fwd, 50, pct);
  }

  static void lowerArm() {
    // Arm Motor Reverse 50% power
    armMotors.spin(reverse, 50, pct);
  }

  static void pistonExtend() {
    // Piston Motor Forward 50% power
    pistonMotor.spin(fwd, 50, pct);
  }

  static void pistonRetract() {
    // Arm Motor Forward 50% power
    pistonMotor.spin(reverse, 100, pct);
  }

  // Released Functions
  static void stopIntake() {
    // Stopping Left Intake Motor
    intakeMotors.stop();
  }

  static void stopArm() {
    // Stopping Arm Motor
    armMotors.stop();
  }

  static void stopPiston() {
    // Stopping  Piston Motor
    pistonMotor.stop();
  }
};

static void Nothing() {}

class Driver {

public:
  static void SetDriverCieran() {
    //
    // Reset the driver
    //
    Controller.ButtonUp.pressed(Nothing);
    Controller.ButtonRight.pressed(Nothing);
    Controller.ButtonLeft.pressed(Nothing);

    // Robot Movement Setup
    // Tank Controls

    // Set the left joystick Y Axis to move the left side of the robot
    Controller.Axis3.changed(ControllerInteraction::moveLeftSide);

    // Set the right joystick Y Axis to move the right side of the robot
    Controller.Axis2.changed(ControllerInteraction::moveRightSide);

    // Arm Movement Setup
    // Controls for the arm

    // Sets the left down button to lower the robot's arms
    Controller.ButtonDown.pressed(ControllerInteraction::lowerArm);

    // Sets the right down button(B) to raise the robot's arm
    Controller.ButtonB.pressed(ControllerInteraction::liftArm);

    // Piston Control Setup
    // Controls for the piston

    // Sets the lowest front left button to lower the piston
    Controller.ButtonL2.pressed(ControllerInteraction::pistonRetract);

    // Sets the lowest front right button to raise the piston
    Controller.ButtonR2.pressed(ControllerInteraction::pistonExtend);

    // Intake Control Setup
    // Controls for the intake system

    // Sets the highest front left button to have the intake system pull objects
    // towards the bot
    Controller.ButtonL1.pressed(ControllerInteraction::pullIntake);

    // Sets the highest front right button to have the intake system push
    // objects away from the bot
    Controller.ButtonR1.pressed(ControllerInteraction::pushIntake);

    Controller.Screen.clearScreen();
    Controller.Screen.print("Hello Cieran!");
  }

  static void SetDriverCharlie() {
    //
    // Reset the driver
    //
    Controller.ButtonUp.pressed(Nothing);
    Controller.ButtonRight.pressed(Nothing);
    Controller.ButtonLeft.pressed(Nothing);

    Controller.Screen.clearScreen();
    Controller.Screen.print("Hello Charlie!");
  }

  static void SetDriverAndrew() {
    //
    // Reset the driver
    //
    Controller.ButtonUp.pressed(Nothing);
    Controller.ButtonRight.pressed(Nothing);
    Controller.ButtonLeft.pressed(Nothing);

    // Robot Movement Setup
    // Tank Controls

    // Set the left joystick Y Axis to move the left side of the robot
    Controller.Axis3.changed(ControllerInteraction::moveLeftSide);

    // Set the right joystick Y Axis to move the right side of the robot
    Controller.Axis2.changed(ControllerInteraction::moveRightSide);

    // Arm Movement Setup
    // Controls for the arm

    // Sets the left down button to lower the robot's arms
    Controller.ButtonDown.pressed(ControllerInteraction::lowerArm);

    // Sets the right down button(B) to raise the robot's arm
    Controller.ButtonB.pressed(ControllerInteraction::liftArm);

    // Piston Control Setup
    // Controls for the piston

    // Sets the lowest front left button to lower the piston
    Controller.ButtonL2.pressed(ControllerInteraction::pistonRetract);

    // Sets the lowest front right button to raise the piston
    Controller.ButtonR2.pressed(ControllerInteraction::pistonExtend);

    // Intake Control Setup
    // Controls for the intake system

    // Sets the highest front left button to have the intake system pull objects
    // towards the bot
    Controller.ButtonL1.pressed(ControllerInteraction::pullIntake);

    // Sets the highest front right button to have the intake system push
    // objects away from the bot
    Controller.ButtonR1.pressed(ControllerInteraction::pushIntake);

    Controller.Screen.clearScreen();
    Controller.Screen.print("Hello Andrew!");
  }

  static void SetDriver() {
    Controller.Screen.print("Choose the new Driver");
    Controller.Screen.newLine();
    Controller.Screen.print("Left: Cieran, X: Andrew, A: Charlie");

    Controller.ButtonLeft.pressed(SetDriverCieran);
    Controller.ButtonX.pressed(SetDriverAndrew);
    Controller.ButtonA.pressed(SetDriverCharlie);
  }
};