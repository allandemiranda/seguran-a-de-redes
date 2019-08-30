/**
 * @file SubKeyGenerate.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "SubKeyGenerate.h"

#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Construct a new Sub Key Generate:: Sub Key Generate object
 *
 * @param keyMaster Chave principal
 */
SubKeyGenerate::SubKeyGenerate(std::string keyMaster) {
  // Obtendo configuração Feistel
  try {
    std::ifstream file(feistelConfigPath);
    std::string line;
    unsigned int position = 0;
    while (std::getline(file, line)) {
      feistelConfigVector[position] = line;
      ++position;
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << e.what() << '\n';
  }

}

SubKeyGenerate::~SubKeyGenerate() {}