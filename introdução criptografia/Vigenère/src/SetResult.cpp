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

#include "../include/SetResult.h"

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
  std::string fileName = "result/" + text.getCode() + ".txt";
  newFile.open(fileName, std::ios::app);
  for (unsigned long i(0); i < text.getNumberOfLine(); ++i) {
    // std::cout << text.getLine(i) << std::endl;
    newFile << text.getLine(i) << std::endl;
  }
  newFile.close();
}

/**
 * @brief Set the Result::~ Set Result object
 *
 */
SetResult::~SetResult() {}