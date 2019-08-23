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

int main(int argc, char const* argv[]) {
  std::string file_name(argv[1]);
  std::cout << "Verificanod imagem " << file_name << " ..." << std::endl;
  bitmap_image image(file_name);
  if (!image) {
    printf("Error - Failed to open '%s'\n", file_name.c_str());
    return 0;
  }

  const unsigned int height = image.height();
  const unsigned int width = image.width();

  auto bitsetPositionAll(0u);
  std::vector<std::bitset<8>> msgBinary;
  std::bitset<8> caracter;

  // auto vectorPosition(0u);

  std::cout << std::endl;
  std::cout << "Retirando mensagem em binário da imagem ..." << std::endl;
  std::cout << std::endl;
  for (std::size_t y = 0; y < height; ++y) {
    for (std::size_t x = 0; x < width; ++x) {
      rgb_t colour;
      image.get_pixel(x, y, colour);
      auto bitsetPositionTrue(bitsetPositionAll % 8);

      if (bitsetPositionTrue == 0) {
        std::bitset<8> red = std::bitset<8>(colour.red);
        if (red[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << "[" << vectorPosition << "] "
        //             << " PX*" << ((y * width) + x) << " R->" << red[0];
        // }
        ++bitsetPositionAll;
        bitsetPositionTrue = (bitsetPositionAll % 8);

        std::bitset<8> green = std::bitset<8>(colour.green);
        if (green[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << " G->" << green[0];
        // }
        ++bitsetPositionAll;
        bitsetPositionTrue = (bitsetPositionAll % 8);

        std::bitset<8> blue = std::bitset<8>(colour.blue);
        if (blue[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << " B->" << blue[0];
        // }
        ++bitsetPositionAll;
      }
      if (bitsetPositionTrue == 3) {
        std::bitset<8> red = std::bitset<8>(colour.red);
        if (red[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << " PX*" << ((y * width) + x) << " R->" << red[0];
        // }
        ++bitsetPositionAll;
        bitsetPositionTrue = (bitsetPositionAll % 8);

        std::bitset<8> green = std::bitset<8>(colour.green);
        if (green[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << " G->" << green[0];
        // }
        ++bitsetPositionAll;
        bitsetPositionTrue = (bitsetPositionAll % 8);

        std::bitset<8> blue = std::bitset<8>(colour.blue);
        if (blue[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << " B->" << blue[0];
        // }
        ++bitsetPositionAll;
      }
      if (bitsetPositionTrue == 6) {
        std::bitset<8> red = std::bitset<8>(colour.red);
        if (red[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << " PX*" << ((y * width) + x) << " R->" << red[0];
        // }
        ++bitsetPositionAll;
        bitsetPositionTrue = (bitsetPositionAll % 8);

        std::bitset<8> green = std::bitset<8>(colour.green);
        if (green[0] == 1) {
          caracter.set(bitsetPositionTrue);
        }
        // if (vectorPosition <= 130) {
        //   std::cout << " G->" << green[0] << std::endl;
        // }
        // vectorPosition++;
        ++bitsetPositionAll;
        if (caracter.to_string() == "00000011") {
          std::cout << "ALLAN" << std::endl;
          break;
        }
        msgBinary.push_back(caracter);
        caracter.reset();
      }
    }
    if (caracter.to_string() == "00000011") {
      std::cout << "ALLAN" << std::endl;
      break;
    }
  }
  std::cout << std::endl;
  std::cout << "----------------------------" << std::endl;
  std::cout << std::endl;
  for (auto i(0u); i < 130; ++i) {
    std::cout << msgBinary[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "----------------------------" << std::endl;
  std::cout << std::endl;

  std::cout << "Convertendo de binário para texto ..." << std::endl;

  std::string msgFinal;

  for (auto i(0u); i < msgBinary.size(); ++i) {
    unsigned long j = msgBinary[i].to_ulong();
    unsigned char c = static_cast<unsigned char>(j);
    msgFinal.push_back(c);
  }

  std::ofstream newFile;
  std::string fileName = "result/keyMsg.txt";
  newFile.open(fileName, std::ios::app);
  newFile << msgFinal << std::endl;
  newFile.close();

  std::cout << std::endl;
  std::cout << "Mensagem final disponível em result/keyMsg.txt" << std::endl;
  std::cout << std::endl;

  return 0;
}
