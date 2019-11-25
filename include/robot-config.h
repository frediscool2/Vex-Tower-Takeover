using namespace vex;

using signature = vision::signature;
extern brain Brain;

// VEXcode devices
extern motor armMotorA;
extern motor armMotorB;
extern motor pistonMotor;
extern controller Controller;

extern motor_group leftMotors;
extern motor_group rightMotors;
extern motor_group intakeMotors;
extern motor_group armMotors;
extern motor_group driveTrain;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);