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

#include "ControlScheme.cpp"

#include <vector>

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

  // setting up sensor
  // objectTracker.intiSensor();
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

     */

    // left 1,2
    Controller.ButtonL1.pressed(ControllerInteraction::bL1Pressed);
    Controller.ButtonL2.pressed(ControllerInteraction::bL2Pressed);

    // right 1,2
    Controller.ButtonR1.pressed(ControllerInteraction::bR1Pressed);
    Controller.ButtonR2.pressed(ControllerInteraction::bR2Pressed);
    Controller.ButtonRight.pressed(ControllerInteraction::bL3Pressed);

    Controller.ButtonDown.pressed(ControllerInteraction::cLPressed);

    Controller.ButtonY.pressed(ControllerInteraction::bR3Pressed);
    Controller.ButtonB.pressed(ControllerInteraction::cRPressed);

    // left 1,2 released
    Controller.ButtonL1.released(ControllerInteraction::bLReleased);
    Controller.ButtonL2.released(ControllerInteraction::bLReleased);

    // right 1,2 released
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

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

/*
  TODO:
-Test values that the sensor returns we know the following
  a) all x values grabbed from object will be between 0 and 315
  b) all y values grabbed from object will be betweenn 0 and 211
  c) we have methods that can grab the width, height, angle, centerX, centerY,
      orginX and orginY. Values

    Questions:
      -Lets say we fetch the centerX value of the object.
        what does this value represent?
        is 0 the very left limit of the sensors view and 315 the right limit?
        If so is an x val of 157.5 -                            dead center?
        How precice are the values, do we need to add a range of .5 or 5?
      -What is the max range of the sensor?
      -What is the max effetive range of the sensor?
      -What is the poll rate of the sensor?
      -Correct brightness setting of the vision sensor on init see vision docs
          for details
      -Effectivness of automatic brightness setting vs manaul
      -LED interaction
      -

*/
