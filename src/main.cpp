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
#include "auto.cpp"
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
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  leftWheelMotor.resetRotation();
  rightWheelMotor.resetPosition();

  leftArmMotor.setBrake(hold);
  rightArmMotor.setBrake(hold);

  leftPistonMotor.setBrake(hold);
  rightPistonMotor.setBrake(hold);

  leftIntakeMotor.setBrake(hold);
  rightIntakeMotor.setBrake(hold);

  Controller.Screen.print("A =X, C= Left, Ch=A");
  Driver::setDriverAndrew();
}

void autonomous(void) {
  //  RightAuto(1);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}
// temp function REMOVE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void resetEncoders() {
  leftWheelMotor.resetRotation();
  rightWheelMotor.resetRotation();
}

void usercontrol(void) {
  // User control code here, inside the loop
  Brain.Screen.render(true);

  driveForDistance((distanceUnits)deg, 1150.4, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, 1099.2, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, -269.6, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, -270.8, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, 86, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, -732, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, 411.2, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, 428.4, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, -295.2, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, -507.2, 50, RightMotors, true);

  while (1) {
    Controller.ButtonX.pressed(resetEncoders);
    Controller.Screen.setCursor(1, 0);
    Controller.Screen.clearLine(1);
    Controller.Screen.print("L1: %.3f", leftWheelMotor.rotation(deg));
    Controller.Screen.setCursor(2, 0);
    Controller.Screen.clearLine(2);
    Controller.Screen.print("R1: %.3f", rightWheelMotor.rotation(deg));
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