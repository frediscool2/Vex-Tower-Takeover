using namespace vex;

using signature = vision::signature;
extern brain Brain;

// VEXcode devices
extern motor leftWheelMotor;
extern motor rightWheelMotor;
extern motor leftIntakeMotor;
extern motor rightIntakeMotor;

extern motor leftArmMotor;
extern motor rightArmMotor;
extern motor leftPistonMotor;
extern motor rightPistonMotor;
extern controller Controller;

extern motor_group IntakeMotors;
extern motor_group ArmMotors;
extern motor_group PistonMotors;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);