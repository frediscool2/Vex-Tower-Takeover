#include "../src/LodePNG/lodepng.h"
#include "string.h"
#include "vex.h"
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace vex;

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

  // generates a white black gradient image
  private:
  static void generateRawPixelData(unsigned width, unsigned height) {
    // our buffer
    uint32_t *buffer;

    // setting the size of our buffer
    buffer = new uint32_t[height * width];

    // checking if buffer is null
    if (buffer != NULL) {
      printf("buffer is good\n");
      // Loop for rows
      for (int y = 0; y < height; y++) {
        // loop for colums
        for (int x = 0; x < width; x++) {
          // create rgb value
          int32_t rgb = (x << 16) + (x << 8) + x;
          buffer[y * width + x] = rgb;
        }
      }
      // drawing buffer
      Brain.Screen.drawImageFromBuffer(buffer, 0, 0, width, height);

      // delete buffer
      delete buffer;
    }
  }
};