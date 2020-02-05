/*----------------------------------------------------------------------------*/
/*    Module:       main.cpp    F */
/*    Author:       VEX */
/*    Created:      Thu Sep 26 2019 */
/*    Description:  Competition Template */
/* */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rightWheelMotorB     motor         1
// rightWheelMotorD     motor         2
// leftWheelMotorA      motor         3
// leftWheelMotorC      motor         4
// leftIntakeMotor      motor         5
// rightIntakeMotor     motor         6
// armMotor             motor         7
// pistonMotor          motor         8
// Controller          controller
// ---- END VEXCODE CONFIGURED DEVICES ----
//
#include "ControlScheme.h"
#include "auto.h"
#include "vex.h"

// using namespace Autonomous;
using namespace vex;

distanceUnits cm = distanceUnits::cm;

// A global instance of competition
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void resetEncoders() {
  leftWheelMotor.resetRotation();
  rightWheelMotor.resetRotation();
  leftArmMotor.resetRotation();
  rightArmMotor.resetRotation();
  leftPistonMotor.resetRotation();
  rightPistonMotor.resetRotation();
  leftIntakeMotor.resetRotation();
  rightIntakeMotor.resetRotation();
}

int updateMotorEncoders() {
  resetEncoders();
  while (true) {
    Controller.Screen.clearScreen();
    printf("~~~~ Motor Encoders ~~~\n\n");
    printf("DriveL:  %.2f DriveR:  %.2f\n", leftWheelMotor.rotation(deg),
           rightWheelMotor.rotation(deg));
    printf("PistonL: %.2f  PistonR: %.2f\n", leftPistonMotor.rotation(deg),
           rightPistonMotor.rotation(deg));
    printf("ArmL: %.2f  ArmR: %.2f\n", leftArmMotor.rotation(deg),
           rightArmMotor.rotation(deg));
    printf("IntakeL: %.2f IntakeR:  %.2f\n", leftIntakeMotor.rotation(deg),
           rightIntakeMotor.rotation(deg));

    printf("~~~~ Motor Temperatures  ~~~\n\n");
    printf("DriveL:  %.1f DriveR:  %.1f\n", leftWheelMotor.temperature(celsius),
           rightWheelMotor.temperature(celsius));
    printf("PistonL:  %.1f PistonR: %.1f\n",
           leftPistonMotor.temperature(celsius),
           rightPistonMotor.temperature(celsius));
    printf("ArmL:  %.1f ArmR:  %.1f\n", leftArmMotor.temperature(celsius),
           rightArmMotor.temperature(celsius));
    printf("IntakeL: %.1f IntakeR: %.1f\n",
           leftIntakeMotor.temperature(celsius),
           rightIntakeMotor.temperature(celsius));

    Controller.Screen.setCursor(1, 0);
    Controller.Screen.print("DL: %.1f DR: %.1f",
                            leftWheelMotor.temperature(celsius),
                            rightWheelMotor.temperature(celsius));

    Controller.Screen.setCursor(2, 0);
    Controller.Screen.print("LI: %.1f RI: %.1f",
                            leftIntakeMotor.temperature(celsius),
                            rightIntakeMotor.temperature(celsius));

    Controller.Screen.setCursor(3, 0);
    Controller.Screen.print("A1: %.1f A2: %.1f", leftArmMotor.rotation(deg),
                            rightArmMotor.rotation(deg));

    wait(10, msec); // motors has a max poll rate of 10 msec
  }
  return -1;
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  leftWheelMotor.resetRotation();
  rightWheelMotor.resetRotation();

  leftWheelMotor.setBrake(coast);
  rightWheelMotor.setBrake(coast);

  leftArmMotor.setBrake(hold);
  rightArmMotor.setBrake(hold);

  leftPistonMotor.setBrake(hold);
  rightPistonMotor.setBrake(hold);

  leftIntakeMotor.setBrake(hold);
  rightIntakeMotor.setBrake(hold);

  // DEBUG
  Driver::setDriverCharlie();
}

void autonomous(void) {

  Auto::autoSkills();
  /* fold out
    // PISTON
    Auto::spinForDegrees(-277.4, leftPistonMotor);
    Auto::spinForDegrees(-281, rightPistonMotor, true);

    Auto::spinForDegrees(709.8, leftArmMotor);
    Auto::spinForDegrees(709.8, rightArmMotor, true);

    Auto::spinForDegrees(277.4, leftPistonMotor);
    Auto::spinForDegrees(281, rightPistonMotor, true);

    Auto::redRightAuto();
    */
}

void usercontrol(void) {
  // User control code here, inside the loop
  task updateEncoders = task(updateMotorEncoders);

  while (1) {
    if (Controller.ButtonX.pressing()) {
      resetEncoders();
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}