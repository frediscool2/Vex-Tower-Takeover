#include "vex.h";

namespace Math
{
  const double inchesPerDegree = (3.14159 * 3.25) / 360;
}

static void driveForDistance(distanceUnits distanceUnit, double distanceVal,
                               velocityUnits velcUnit, double velVal,
                               motor_group motorGroup) {
    if (distanceUnit == distanceUnits::cm) {
      distanceVal = distanceVal / 2.54;
    } else if (distanceUnit == mm) {
      distanceVal = (distanceVal * 10) / 2.54;
    }
    
    distanceVal = distanceVal / Math::inchesPerDegree;

    motorGroup.rotateTo(distanceVal, deg, velVal, velcUnit, false);
  }

  static void driveForDistance(distanceUnits distanceUnit, double distanceVal,
                               velocityUnits velcUnit, double velVal,
                               motor mMotor) {
    if (distanceUnit == distanceUnits::cm) {
      distanceVal = distanceVal / 2.54;
    } else if (distanceUnit == mm) {
      distanceVal = (distanceVal * 10) / 2.54;
    }

    
    distanceVal = distanceVal / Math::inchesPerDegree;

    mMotor.rotateTo(distanceVal, deg, velVal, velcUnit, false);
  }

  namespace Autonomous
{
  void RightAuto()
  {
    driveForDistance(distanceUnits::cm, 111.76, velocityUnits::pct, 50,
                     leftMotors);
    driveForDistance(distanceUnits::cm, 111.76, velocityUnits::pct, 50,
                     rightMotors);
  }

  void LeftAuto()
  {

  }
}