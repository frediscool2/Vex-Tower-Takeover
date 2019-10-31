#include "LodePNG/lodepng.h"
#include "string.h"
#include "vex.h"
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace lodepng;

class Animation {
public:
  static void updateScreen() {
    unsigned width = 480, height = 272;

    std::vector<unsigned char> png;
    std::vector<unsigned char> image;
    int start = clock() / 10;
    std::string filePaths[6] = {"ball-2.png", "ball-3.png", "ball-4.png",
                                "ball-5.png", "ball-6.png", "ball-7.png"};
    double waitTimes[6] = {250, 250, 250, 250, 250, 250};
    int i = 0, itterator = 1;

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

private:
  static int generateRawPixelData(unsigned width, unsigned height) {
    // vector to store our raw pixel data
    std::vector<unsigned char> image;

    // setting vector size to size of image
    image.resize(width * height * 4);

    // Loop for y rows
    for (unsigned y = 0; y < height; y++)
      // Loop for columns
      for (unsigned x = 0; x < width; x++) {
        // generating image data
        image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
        image[4 * width * y + 4 * x + 1] = x ^ y;
        image[4 * width * y + 4 * x + 2] = x | y;
        image[4 * width * y + 4 * x + 3] = 255;
      }
    // image data -> buffer
    uint8_t *buffer = image.data();

    // returning buffer
    return *buffer;
  }
};