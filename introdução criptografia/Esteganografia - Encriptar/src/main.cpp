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
  std::cout << std::endl;
  std::cout << "Lendo arquivo com mensagem ..." << std::endl;
  DataSet msg("data/mensagem.txt");
  std::cout << std::endl;
  std::string msgBinary;
  std::cout << "Convertendo mensagem em um texto binário ..." << std::endl;
  for (auto i(0u); i < msg.getMsg().size(); ++i) {
    msgBinary += std::bitset<8>(msg.getMsg()[i]).to_string();
  }
  std::cout << std::endl;
  std::cout << "-----------------------------------------------";
  for (auto i(0u); i < msgBinary.size(); ++i) {
    if ((i % 50) == 0) {
      std::cout << std::endl;
    }
    std::cout << msgBinary[i];
  }
  std::cout << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << std::endl;

  std::string file_name(argv[1]);
  std::cout << "Verificanod imagem " << file_name << " ..." << std::endl;
  bitmap_image image(file_name);
  if (!image) {
    printf("Error - Failed to open '%s'\n", file_name.c_str());
    return 0;
  }

  const unsigned int height = image.height();
  const unsigned int width = image.width();

  if ((msg.getMsg().size() * 3) >= (height * width)) {
    std::cout << "Imagem não possui tamanho suficiente para guardar mensagem !"
              << std::endl;
    return 0;
  }

  unsigned long positionImg = 0;

  bitmap_image image_out(height, width);

  std::cout << std::endl;
  std::cout << "Criptografando mensagem na imagem ..." << std::endl;
  for (std::size_t y = 0; y < height; ++y) {
    for (std::size_t x = 0; x < width; ++x) {
      rgb_t colour;
      image.get_pixel(x, y, colour);

      if ((3 * positionImg) <= msg.getMsg().size()) {
        if ((positionImg % 3) != 2) {
          std::bitset<8> red = std::bitset<8>(colour.red);
          if (red[0] != msg.getMsg()[((3 * positionImg) + 0)]) {
            red.flip(0);
          }
          colour.red = red.to_ullong();
          std::bitset<8> green = std::bitset<8>(colour.green);
          if (green[0] != msg.getMsg()[((3 * positionImg) + 1)]) {
            green.flip(0);
          }
          colour.green = green.to_ullong();

          std::bitset<8> blue = std::bitset<8>(colour.blue);
          if (blue[0] != msg.getMsg()[((3 * positionImg) + 1)]) {
            blue.flip(0);
          }
          colour.blue = blue.to_ullong();
        } else {
          std::bitset<8> red = std::bitset<8>(colour.red);
          if (red[0] != msg.getMsg()[((3 * positionImg) + 0)]) {
            red.flip(0);
          }

          colour.red = red.to_ullong();
          std::bitset<8> green = std::bitset<8>(colour.green);
          if (green[0] != msg.getMsg()[((3 * positionImg) + 1)]) {
            green.flip(0);
          }
          colour.green = green.to_ullong();
        }
      }
      ++positionImg;
      image_out.set_pixel(x, y, colour);
    }
  }

  std::cout << std::endl;
  image_out.save_image("result/key.bmp");
  std::cout << "Imagem com a mensagem disponível em 'result/key.bmp' !"
            << std::endl;
  std::cout << std::endl;

  return 0;
}
