/**
 * @file imgSet.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-19
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "../include/ImgSet.h"

#include <fstream>  //!< std::ifstream
#include <iostream>
#include <string>

ImgSet::ImgSet(std::string fileName) {
  try {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
      img.push_back(line);
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << e.what() << '\n';
  }
}

ImgSet::~ImgSet() {}