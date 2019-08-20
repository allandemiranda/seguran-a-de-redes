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

#include "bitmap_image.hpp"

int main(void) {
  std::string file_name("data/key.bmp");
  std::cout << "Verificanod imagem " << file_name << " ..." << std::endl;
  bitmap_image image(file_name);
  if (!image) {
    printf("Error - Failed to open '%s'\n", file_name.c_str());
    return 0;
  }

  const unsigned int height = image.height();
  const unsigned int width = image.width();

  unsigned long positionImg = 0;
  std::string mensagem;

  std::cout << std::endl;
  std::cout << "Retirando mensagem em binário da imagem ..." << std::endl;
  for (std::size_t y = 0; y < height; ++y) {
    for (std::size_t x = 0; x < width; ++x) {
      rgb_t colour;
      image.get_pixel(x, y, colour);

      if ((positionImg % 3) != 2) {
        std::bitset<8> red = std::bitset<8>(colour.red);
        mensagem.push_back(red[0]);

        std::bitset<8> green = std::bitset<8>(colour.green);
        mensagem.push_back(green[0]);

        std::bitset<8> blue = std::bitset<8>(colour.blue);
        mensagem.push_back(blue[0]);
      } else {
        std::bitset<8> red = std::bitset<8>(colour.red);
        mensagem.push_back(red[0]);

        std::bitset<8> green = std::bitset<8>(colour.green);
        mensagem.push_back(green[0]);
      }
      ++positionImg;
    }
  }

  std::cout << std::endl;
  std::cout << "Convertendo de binário para texto ..." << std::endl;  

  std::string msgFinal;

  for (auto i(0u); i < (mensagem.size() / 8); ++i) {
    std::bitset<8> letra;
    for (auto j(8); j >= 0; --j) {
      if (mensagem[(i * 8) + j] == 1) {
        letra.set(std::abs(j - 8));
      }
    }
    std::cout << (char)letra.to_ulong() << std::endl;
    msgFinal += letra.to_string();
  }

  std::cout << std::endl;
  std::cout << msgFinal << std::endl;

  return 0;
}
