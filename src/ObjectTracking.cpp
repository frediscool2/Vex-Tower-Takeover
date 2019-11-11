#include "vex.h"
#include <vector>

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
        If so is an x val of 157.5 -                            dead center?
        How precice are the values, do we need to add a range of .5 or 5?
      -What is the max range of the sensor?
      -What is the max effetive range of the sensor?
      -What is the poll rate of the sensor?
      -Correct brightness setting of the vision sensor on init see vision docs
          for details
      -Effectivness of automatic brightness setting vs manaul
      -LED interaction
      -

*/

class ObjectTracking {

};