#include "vex.h"

class Animation {
public:
  static void updateScreen() {
    int i = 0, itterator = 0, start = clock() / CLOCKS_PER_SEC;

    std::string filePaths[6] = {"ball-2.png", "ball-3.png", "ball-4.png",
                                "ball-5.png", "ball-6.png", "ball-7.png"};
    double waitTimes[6] = {250, 250, 250, 250, 250, 250};

    Brain.Screen.drawImageFromFile(filePaths[i].data(), 0, 0);

    if (i > 3 || i < 0) {
      itterator *= -1;
    }

    start = clock() / CLOCKS_PER_SEC;
    i += itterator;

    wait(waitTimes[i], msec);
  }
};