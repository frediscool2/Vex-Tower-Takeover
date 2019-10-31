using namespace vex;
using signature = vision::signature;;
extern brain Brain;

// VEXcode devices
extern motor armMotor;
extern motor pistonMotor;
extern controller Controller;

extern motor rightWheelMotorA;
extern motor rightWheelMotorC;
extern motor leftWheelMotorB;
extern motor leftWheelMotorD;

extern motor_group leftMotors;
extern motor_group rightMotors;
extern motor_group intakeMotors;
extern drivetrain driveTrain;
extern brain::sdcard sdcard;

extern vision Vision;
extern signature VisionBLUEBOX;
extern signature VisionGREENBOX;
extern signature VisionREDBOX;
extern signature VisionFooSignature;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);