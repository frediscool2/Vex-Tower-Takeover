#include "../src/LodePNG/lodepng.h"
#include "string.h"
#include "vex.h"
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace lodepng;

class Animation {
#define YSIZE 272;
#define XSIZE 480;

public:
  static void updateScreen() {
    std::vector<unsigned char> png;
    std::vector<unsigned char> image;
    int start = clock() / 10;
    std::string filePaths[6] = {"ball-2.png", "ball-3.png", "ball-4.png",
                                "ball-5.png", "ball-6.png", "ball-7.png"};
    double waitTimes[6] = {250, 250, 250, 250, 250, 250};
    int i = 0, itterator = 1;

    unsigned width, height;
    static_assert(std::is_same<unsigned char, uint8_t>::value, "foo");

    while (true) {
      load_file(png, filePaths[i].data());
      decode(image, width, height, png);

      uint8_t *buffer = image.data();

      Brain.Screen.drawImageFromBuffer(buffer, 0, 0, image.size());

      if (i <= 0) {
        itterator = 1;
      }

      if (i >= 5) {
        itterator = -1;
      }

      start = clock() / 10;
      i += itterator;

      wait(waitTimes[i], msec);
    }
  }
};