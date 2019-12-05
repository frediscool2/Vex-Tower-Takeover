#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors

// leftt and right wheel motors
motor leftWheelMotor = motor(PORT4, ratio18_1, false);
motor rightWheelMotor = motor(PORT2, ratio18_1, true);

// left and right intake motors
motor leftIntakeMotor = motor(PORT1, ratio18_1, false);
motor rightIntakeMotor = motor(PORT5, ratio18_1, true);

// Arm motor
motor leftArmMotor = motor(PORT8, ratio36_1, true);
motor rightArmMotor = motor(PORT7, ratio36_1, false);

// Piston motor

motor leftPistonMotor = motor(PORT10, ratio36_1, true);
motor rightPistonMotor = motor(PORT9, ratio36_1, false);

// Controller
controller Controller = controller(primary);

// ~~~ Motor Groups ~~~
motor_group IntakeMotors = motor_group(leftIntakeMotor, rightIntakeMotor);
motor_group ArmMotors = motor_group(leftArmMotor, rightArmMotor);
motor_group PistonMotors = motor_group(leftPistonMotor, rightPistonMotor);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {}
