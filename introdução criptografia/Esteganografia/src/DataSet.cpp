/**
 * @file DataSet.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-19
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "DataSet.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

DataSet::DataSet(std::string fileName) {
  try {
    std::ifstream file(fileName);
    std::string line;
    bool flag = true;
    while (std::getline(file, line)) {
      if (flag) {
        msg = line;
        flag = false;
      } else {
        msg += " " + line;
      }
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << e.what() << '\n';
  }
}

DataSet::~DataSet() {}

std::string DataSet::getMsg(void) {
  return msg;
}