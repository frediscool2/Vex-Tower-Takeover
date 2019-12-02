#include "vex.h"

namespace Math {
const double inchesPerDegree = (3.14159 * 3.25) / 360;
const double cmPerDegree = (3.1459 * 8.255) / 360;
const double mmPerDegree = (3.14159 * 82.55) / 360;
}; // namespace Math

class Auto {
public:
  static void driveForDistance(double distanceVal, motor Motor,
                               bool wait = false, double velVal = 50,
                               velocityUnits velcUnits = velocityUnits::pct,
                               distanceUnits distanceUnit = inches);

public:
  static void blueLeftAuto();
  static void blueRightAuto();
  static void redLeftAuto();
  static void redRightAuto();
};