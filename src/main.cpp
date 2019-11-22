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
#include "ControlScheme.cpp"
#include "GUI.h"
#include "vex.h"

using namespace vex;

distanceUnits cm = distanceUnits::cm;

// A global instance of competition
competition Competition;

//GUI gui;

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
  armMotor.setBrake(hold);
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void SetDriverCieran()
{
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

  // Sets the highest front left button to have the intake system pull objects towards the bot
  Controller.ButtonL1.pressed(ControllerInteraction::pullIntake);

  // Sets the highest front right button to have the intake system push objects away from the bot
  Controller.ButtonR1.pressed(ControllerInteraction::pushIntake);
}

void SetDriverCharlie()
{

}

void SetDriverAndrew()
{

}

void usercontrol(void) {
  // User control code here, inside the loop
  Brain.Screen.render(true);
  SetDriverCieran();
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

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  //
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    //Brain.Screen.pressed(gui.screenPressed);
    //gui.updateScreen();
    wait(100, msec);
  }
}