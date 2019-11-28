#include "vex.h"

namespace Math {
const double inchesPerDegree = (3.14159 * 3.25) / 360;
const double cmPerDegree = (3.1459 * 8.255) / 360;
const double mmPerDegree = (3.14159 * 82.55) / 360;
} // namespace Math

static void driveForDistance(distanceUnits distanceUnit, double distanceVal,
                             double velVal, motor_group motorGroup, bool wait) {
  if (distanceUnit == distanceUnits::cm) {
    distanceVal = distanceVal / 2.54;
  } else if (distanceUnit == mm) {
    distanceVal = (distanceVal * 10) / 2.54;
  } else

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
    default:
      break;
    }
  motorGroup.rotateTo(distanceVal, deg, velVal, velocityUnits::pct, wait);
}

namespace Autonomous {
void RightAuto(int a) {

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
  driveForDistance((distanceUnits)deg, 1150.4, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, 1099.2, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, -269.6, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, -270.8, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, 86, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, -732, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, 411.2, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, 428.4, 50, RightMotors, true);

  driveForDistance((distanceUnits)deg, -295.2, 50, LeftMotors, false);
  driveForDistance((distanceUnits)deg, -507.2, 50, RightMotors, true);
}

} // namespace Autonomous