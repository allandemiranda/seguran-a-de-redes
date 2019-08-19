/**
 * @file main.cpp
 * @author Allan de Miranda
 * @brief Main
 * @version 0.1
 * @date 2019-08-18
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include <bitset>

#include "DataSet.h"
#include "bitmap_image.hpp"

int main(int argc, char const* argv[]) {
  DataSet msg("data/mensagem.txt");
  std::string msgBinary;
  for (unsigned long i(0); i < msg.getMsg().size(); ++i) {
    msgBinary += std::bitset<8>(msg.getMsg()[i]).to_string();
  }

  std::string file_name(argv[1]);
  // bitmap_image image(file_name);
  bitmap_image image("data/image.bmp");
  if (!image) {
    printf("Error - Failed to open '%s'\n", file_name.c_str());
    return 0;
  }
  unsigned int total_number_of_pixels = 0;

  const unsigned int height = image.height();
  const unsigned int width = image.width();

  unsigned long positionMsg = 0;

  bitmap_image image_out(height, width);

  for (std::size_t y = 0; y < height; ++y) {
    for (std::size_t x = 0; x < width; ++x) {
      rgb_t colour;
      image.get_pixel(x, y, colour);
      
      image_out.set_pixel(x, y, colour);
    }
  }

  image_out.save_image("key.bmp");

  return 0;
}
