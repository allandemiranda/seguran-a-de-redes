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

#include "../include/DataSet.h"
#include "bitmap_image.hpp"

int main(int argc, char const* argv[]) {
  std::cout << std::endl;
  std::cout << "Lendo arquivo com mensagem ..." << std::endl;
  DataSet msg("data/mensagem.txt");
  std::cout << std::endl;

  std::cout << "Convertendo mensagem em um texto binário ..." << std::endl;
  std::cout << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::vector<std::bitset<8>> msgBinary;
  for (auto i(0u); i < msg.getMsg().size(); ++i) {
    std::cout << "[" << i << "] '" << msg.getMsg()[i] << "' "
              << std::bitset<8>(msg.getMsg()[i]).to_string() << std::endl;
    msgBinary.push_back(std::bitset<8>(msg.getMsg()[i]));
  }
  std::cout << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  for (auto i(0u); i < msgBinary.size(); ++i) {
    std::cout << msgBinary[i] << " ";
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

  auto vectorPosition(0u);
  auto bitsetPositionAll(0u);

  bitmap_image image_out(width,height);

  std::cout << std::endl;
  std::cout << "Criptografando mensagem na imagem ... " << std::endl;
  std::cout << std::endl;
  for (std::size_t y = 0; y < height; ++y) {
    for (std::size_t x = 0; x < width; ++x) {
      rgb_t colour;
      image.get_pixel(x, y, colour);
      auto bitsetPositionTrue(bitsetPositionAll % 8);

      if (vectorPosition < msgBinary.size()) {
        if (bitsetPositionTrue == 0) {
          std::bitset<8> red = std::bitset<8>(colour.red);
          std::cout << " [" << vectorPosition << "] "
                    << " PX*" << ((y * width) + x) << " R(" << red[0] << ")->";
          if (red[0] != msgBinary[vectorPosition][0]) {
            red.flip(0);
          }
          colour.red = red.to_ulong();
          std::cout << red[0];
          ++bitsetPositionAll;

          std::bitset<8> green = std::bitset<8>(colour.green);
          std::cout << " G(" << green[0] << ")->";
          if (green[0] != msgBinary[vectorPosition][1]) {
            green.flip(0);
          }
          colour.green = green.to_ulong();
          std::cout << green[0];
          ++bitsetPositionAll;

          std::bitset<8> blue = std::bitset<8>(colour.blue);
          std::cout << " B(" << blue[0] << ")->";
          if (blue[0] != msgBinary[vectorPosition][2]) {
            blue.flip(0);
          }
          colour.blue = blue.to_ulong();
          std::cout << blue[0];
          ++bitsetPositionAll;
        }
        if (bitsetPositionTrue == 3) {
          std::bitset<8> red = std::bitset<8>(colour.red);
          std::cout << " PX*" << ((y * width) + x) << " R(" << red[0] << ")->";
          if (red[4] != msgBinary[vectorPosition][3]) {
            red.flip(0);
          }
          colour.red = red.to_ulong();
          std::cout << red[0];
          ++bitsetPositionAll;

          std::bitset<8> green = std::bitset<8>(colour.green);
          std::cout << " G(" << green[0] << ")->";
          if (green[0] != msgBinary[vectorPosition][4]) {
            green.flip(0);
          }
          colour.green = green.to_ulong();
          std::cout << green[0];
          ++bitsetPositionAll;

          std::bitset<8> blue = std::bitset<8>(colour.blue);
          std::cout << " B(" << blue[0] << ")->";
          if (blue[0] != msgBinary[vectorPosition][5]) {
            blue.flip(0);
          }
          colour.blue = blue.to_ulong();
          std::cout << blue[0];
          ++bitsetPositionAll;
        }
        if (bitsetPositionTrue == 6) {
          std::bitset<8> red = std::bitset<8>(colour.red);
          std::cout << " PX*" << ((y * width) + x) << " R(" << red[0] << ")->";
          if (red[4] != msgBinary[vectorPosition][6]) {
            red.flip(0);
          }
          colour.red = red.to_ulong();
          std::cout << red[0];
          ++bitsetPositionAll;

          std::bitset<8> green = std::bitset<8>(colour.green);
          std::cout << " G(" << green[0] << ")->";
          if (green[0] != msgBinary[vectorPosition][7]) {
            green.flip(0);
          }
          colour.green = green.to_ulong();
          std::cout << green[0] << std::endl;
          ++bitsetPositionAll;
          ++vectorPosition;
        }
      }
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
