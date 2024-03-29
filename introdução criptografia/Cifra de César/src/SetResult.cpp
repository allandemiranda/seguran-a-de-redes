/**
 * @file SetResult.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "SetResult.h"

#include <fstream>  // std::ifstream, std::ofstream
#include <iostream>
#include <string>

/**
 * @brief Set the Result:: Set Result object
 *
 * @param text Texto descriptografado
 * @param code Código usado
 */
SetResult::SetResult(Decrypt text) {
  std::ofstream newFile;
  std::string fileName = "result/" + std::to_string(text.getCode()) + ".txt";
  newFile.open(fileName, std::ios::app);
  for (auto i(0u); i < text.getNumberOfLine(); ++i) {
    newFile << text.getLine(i) << std::endl;
  }
  newFile.close();
}

/**
 * @brief Set the Result::~ Set Result object
 *
 */
SetResult::~SetResult() {}