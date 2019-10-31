#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors

// leftt and right wheel motors
motor rightWheelMotorA = motor(PORT1, ratio18_1, true);
motor rightWheelMotorC = motor(PORT2, ratio18_1, true);
motor leftWheelMotorB = motor(PORT3, ratio18_1, false);
motor leftWheelMotorD = motor(PORT4, ratio18_1, false);

// left and right intake motors
motor leftIntakeMotor = motor(PORT5, ratio18_1, false);
motor rightIntakeMotor = motor(PORT6, ratio18_1, true);

// Arm motor
motor armMotor = motor(PORT7, ratio18_1, false);

// Piston motor
motor pistonMotor = motor(PORT8, ratio18_1, false);

// Controller
controller Controller = controller(primary);

// ~~~ Motor Groups ~~~
motor_group leftMotors = motor_group(leftWheelMotorB, leftWheelMotorD);
motor_group rightMotors = motor_group(rightWheelMotorA, rightWheelMotorC);
motor_group intakeMotors = motor_group(leftIntakeMotor, rightIntakeMotor);

// Drivetrain
drivetrain driveTrain =
    drivetrain(leftMotors, rightMotors, 299.24, 31.75, 130, mm, 1);

// sdcard
brain::sdcard sdcard = brain::sdcard();

// vision sensor
vision Vision = vision(PORT7);

// Vison Signatures
signature VisionBLUEBOX = // values were taken from vex
    signature(1, -3441, -2785, -3113, 8975, 10355, 9665, 2.5, 0);
signature VisionGREENBOX =
    signature(2, -5767, -4965, -5366, -3803, -2861, -3332, 2.5, 0);
signature VisionREDBOX =
    signature(3, 8099, 8893, 8496, -1505, -949, -1227, 2.5, 0);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {}
