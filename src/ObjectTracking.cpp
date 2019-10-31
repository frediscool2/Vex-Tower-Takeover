#include "vex.h"
#include <vector>
using signature = vision::signature;

/*
  TODO:
-Test values that the sensor returns we know the following
  a) all x values grabbed from object will be between 0 and 315
  b) all y values grabbed from object will be betweenn 0 and 211
  c) we have methods that can grab the width, height, angle, centerX, centerY,
      orginX and orginY. Values

    Questions:
      -Lets say we fetch the centerX value of the object.
        what does this value represent?
        is 0 the very left limit of the sensors view and 315 the right limit?
        If so is an x val of 157.5 dead center?
        How precice are the values, do we need to add a range of .5 or 5?

*/

class ObjectTracking {

public:
  static void hasSignatureCallback() {
    // setting up screen
    Brain.Screen.setFont(mono40);
    Brain.Screen.clearLine(1, black);
    Brain.Screen.setCursor(Brain.Screen.row(), 1);
    Brain.Screen.setCursor(1, 1);

    // fetch the list of objects that match our signature
    Vision.takeSnapshot(VisionBLUEBOX);

    // if there is an object matching the signature we are looking for
    if (Vision.objectCount > 0) {
      Brain.Screen.print("Object Found");
    } else {
      Brain.Screen.print("No Object");
    }
    // do stuff
  }

public:
  static void intiSensor() {
    Vision.setWhiteBalanceMode(vision::whiteBalanceMode::automatic);
    Vision.setMode(vision::detectionMode::objectDetect);
    Vision.setWifiMode(vision::wifiMode::off);
    Vision.setLedMode(vision::ledMode::automatic);
  }

  static void getPostionOfObject() {
    for (int i = 0; i < Vision.objectCount; i++) {
      VexVisionObject Object = Vision.objects[i];

      for (int j = 0; j < 0000; j++) {
        // If x center > (0+/-range)
      }
    }
  }
};