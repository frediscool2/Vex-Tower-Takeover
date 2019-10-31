/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp    F */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
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
ObjectTracking objectTracker;
Animation animation;

// define your global instances of motors and other devices here
event checkSignature = event();
event screenRefresh = event();

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
    // BL 1,2 and BL release
    if (Controller.ButtonL1.pressing()) {
      ControllerInteraction::bL1Pressed();
    } else if (Controller.ButtonL2.pressing()) {
      ControllerInteraction::bL2Pressed();
    } else {
      ControllerInteraction::bLReleased();
    }

    if (Controller.ButtonR1.pressing()) {
      ControllerInteraction::bR1Pressed();
    }
    // BL 3 and CL
    if (Controller.ButtonRight.pressing()) {
      ControllerInteraction::bL3Pressed();
    } else if (Controller.ButtonDown.pressing()) {
      ControllerInteraction::cLPressed();
    } else {
      ControllerInteraction::bL3Released();
    }

    // BR 3 and CR
    if (Controller.ButtonY.pressing()) {
      ControllerInteraction::bL3Pressed();
    } else if (Controller.ButtonB.pressing()) {
      ControllerInteraction::cRPressed();
    } else {
      ControllerInteraction::bR3Released();
    }

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

  screenRefresh(Animation::updateScreen);
  checkSignature(ObjectTracking::hasSignatureCallback);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    checkSignature.broadcastAndWait();
    screenRefresh.broadcastAndWait();
    wait(100, msec);
  }
}
