#include "auto.h"

void Auto::driveForDistance(double distanceVal, motor_group motorGroup,
                            bool wait, double velVal,
                            velocityUnits velcUnits,
                            distanceUnits distanceUnit) {

  if (distanceUnit == distanceUnits::cm) {
    distanceVal = distanceVal / 2.54;
  } else if (distanceUnit == mm) {
    distanceVal = (distanceVal * 10) / 2.54;
  }

  switch (distanceUnit) {
  case distanceUnits::cm:
    distanceVal = distanceVal / Math::cmPerDegree;
    break;
  case distanceUnits::mm:
    distanceVal = distanceVal / Math::cmPerDegree;
    break;
  case distanceUnits::in:
    distanceVal = distanceVal / Math::inchesPerDegree;
    break;
  }
  motorGroup.rotateTo(distanceVal, deg, velVal, velocityUnits::pct, wait);
}

// Left side autonomous of the blue side
// Note: Left is refering to the the left of someone looking at blue side to the
// red side
void Auto::blueLeftAuto() {}

// Left side autonomous of the blue side
// Note: Right is refering to the the right of someone looking at blue side to
// the red side
void Auto::blueRightAuto() {}

// Left side autonomous of the blue side
// Note: Left is refering to the the left of someone looking at red side to the
// blue side
void Auto::redLeftAuto() {
  
}

// Left side autonomous of the blue side
// Note: Right is refering to the the right of someone looking at red side to
// the blue side
void Auto::redRightAuto() {

  // section 1
  /* driveForDistance((distanceUnits)deg, 1087.2, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, 1058.4, 50, RightMotors, true);

   driveForDistance((distanceUnits)deg, -568, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, -251.6, 50, RightMotors, true);

   driveForDistance((distanceUnits)deg, 0000, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, 0000, 50, RightMotors, true);

   driveForDistance((distanceUnits)deg, 0000, 50, LeftMotors, false);
   driveForDistance((distanceUnits)deg, 0000, 50, RightMotors, true);
 */
  // section 2
  driveForDistance(1150.4, LeftMotors);
  driveForDistance(1099.2, RightMotors, true);

  driveForDistance(-269.6, LeftMotors);
  driveForDistance(-270.8, RightMotors, true);

  driveForDistance(86, LeftMotors);
  driveForDistance(-732, RightMotors, true);

  driveForDistance(411.2, LeftMotors);
  driveForDistance(428.4, RightMotors, true);

  driveForDistance(-295.2, LeftMotors);
  driveForDistance(-507.2, RightMotors, true);
}