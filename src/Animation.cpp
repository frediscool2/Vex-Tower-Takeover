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
    // waitimes
    double waitTimes[6] = {250, 250, 250, 250, 250, 250};

    // filepath setup
    std::string filePaths[6] = {"ball-2.png", "ball-3.png", "ball-4.png",
                                "ball-5.png", "ball-6.png", "ball-7.png"};

    // setting up stuff for our loops and start time
    int i = 0, itterator = 1, start = clock() / 10;

    // setting up our png and image
    unsigned char *image = 0;
    unsigned char *png = 0;

    // width and height
    unsigned width, height;

    // pngsize
    size_t pngsize;

    while (true) {
      // Loading and decoding the file to raw 32 bit rgb with lodePNG
      lodepng_load_file(&png, &pngsize, filePaths[i].data());
      lodepng_decode32(&image, &width, &height, png, pngsize);

      // converting our image data to a buffer
      uint32_t *buffer = (uint32_t *)image;

      // printing to a screen
      Brain.Screen.drawImageFromBuffer(buffer, 0, 0, 480, 272);

      // i++
      if (i <= 0) {
        itterator = 1;
      }

      // i--
      if (i >= 5) {
        itterator = -1;
      }

      // reset start
      start = clock() / 10;

      // add itterator
      i += itterator;

      // sleep task
      wait(waitTimes[i], msec);
    }
  }

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