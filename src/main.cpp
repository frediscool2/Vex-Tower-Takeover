// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
//
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
//
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window.
//
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----
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

#include "vex.h"
///
#include "Animation.cpp"
#include "ControlScheme.cpp"
#include <vector>

using namespace vex;

// A global instance of competition
competition Competition;

// object and animation interfaces
ObjectTracking objectTracker;
Animation animation;

// checkSignature event for vision
event checkSignature = event();

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

  // setting up sensor
  objectTracker.intiSensor();
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void usercontrol(void) {
  // User control code here, inside the loop
  Brain.Screen.render(true);
  while (1) {
    //~~~ Pressed Functions ~~~
    /*Currently I have the functions named as the input they are described as in
     * the Controllerler layout sheet. I am doing it this way so when we have
     * our mutiple Controller scheme files for each driver we will only have to
     * swap out the ControllerScheme.cpp file ansd will not have to change
     * anything else. This can cause confusion for those who have not looked at
     * the control layout. Please do so

      Also the motors are labeled by the letter taped onto them again this was a
     drive team instruction and is a temp solution

     The alternative to an if else chain is an event based code system using the
     pressed() functions. The downside to the event based aproach is a lower
     update rate for motor values

     */
    Controller.ButtonL1.pressed(ControllerInteraction::bL1Pressed);
    Controller.ButtonL2.pressed(ControllerInteraction::bL2Pressed);
    Controller.ButtonR1.pressed(ControllerInteraction::bR1Pressed);
    Controller.ButtonRight.pressed(ControllerInteraction::bL3Pressed);
    Controller.ButtonDown.pressed(ControllerInteraction::cLPressed);
    Controller.ButtonY.pressed(ControllerInteraction::bR3Pressed);
    Controller.ButtonB.pressed(ControllerInteraction::cRPressed);

    Controller.ButtonL1.released(ControllerInteraction::bLReleased);
    Controller.ButtonL2.released(ControllerInteraction::bLReleased);
    Controller.ButtonR1.released(ControllerInteraction::bRReleased);
    Controller.ButtonR2.released(ControllerInteraction::bRReleased);
    Controller.ButtonRight.released(ControllerInteraction::bL3Released);
    Controller.ButtonY.released(ControllerInteraction::bR3Released);

    // ~~~ JoyStick Controllers ~~~

    // TL left,right
    Controller.Axis3.changed(ControllerInteraction::leftJoystickChange);

    // TR left,right
    Controller.Axis2.changed(ControllerInteraction::rightJoystickChange);

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

  // check signature event setup
  checkSignature(ObjectTracking::hasSignatureCallback);

  // task setup
  task screenRefresh = task(Animation::updateScreen);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    checkSignature.broadcastAndWait();
    wait(100, msec);
  }
}
