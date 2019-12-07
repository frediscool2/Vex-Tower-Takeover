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
// temp function REMOVE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void resetEncoders() {
  leftWheelMotor.resetRotation();
  rightWheelMotor.resetRotation();
  leftPistonMotor.resetRotation();
  rightPistonMotor.resetRotation();
}

int updateMotorEncoders() {
  resetEncoders();
  while (true) {
    Controller.Screen.setCursor(1, 0);
    Controller.Screen.clearLine(1);
    Controller.Screen.print("L: %.2f R: %.2f", leftWheelMotor.rotation(deg),
                            rightWheelMotor.rotation(deg));
    Controller.Screen.setCursor(2, 0);
    Controller.Screen.clearLine(2);
    Controller.Screen.print("P1: %.2f P2: %.2f", leftPistonMotor.rotation(deg),
                            rightPistonMotor.rotation(deg));

    Controller.Screen.setCursor(3, 0);
    Controller.Screen.clearLine(3);
    Controller.Screen.print("Lt: %.2f    Rt: %.2f",
                            leftWheelMotor.temperature(celsius),
                            rightWheelMotor.temperature(celsius));

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
  Driver::setDriverCieran();
}

void autonomous(void) {
  // just for debugging purposes

  Auto::redRightAuto();

  //  RightAuto(1);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
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