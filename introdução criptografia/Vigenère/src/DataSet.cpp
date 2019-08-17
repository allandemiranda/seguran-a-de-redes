/**
 * @file DataSet.cpp
 * @author Allan de Miranda
 * @brief Dados capturados para o sistema
 * @version 0.1
 * @date 2019-08-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "../include/DataSet.h"

#include <fstream>  //!< std::ifstream
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

/**
 * @brief Construct a new Data Set:: Data Set object
 * 
 * @param nameFile Nome do arquivo
 */
DataSet::DataSet(std::string nameFile) {
  try {
    std::ifstream file(nameFile);
    std::string line;
    while (std::getline(file, line)) {
      std::vector<std::string> words;
      split1(line, words);
      text.push_back(words);
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << e.what() << '\n';
  }
}

/**
 * @brief Destroy the Data Set:: Data Set object
 * 
 */
DataSet::~DataSet() {}

/**
 * @brief 
 * 
 * @param numberLine 
 * @return std::vector<std::string> 
 */
std::vector<std::string> DataSet::getLine(unsigned long numberLine) {
  try {
    if (numberLine >= getNumberOfLine()) {
      throw("Valor maior que quantidade de linhas do texto");
    }
  } catch (std::string msg) {
    std::cerr << msg << '\n';
  }

  return text[numberLine];
}

/**
 * @brief 
 * 
 * @return unsigned long 
 */
unsigned long DataSet::getNumberOfLine(void) {
  return text.size();
}

void DataSet::split1(const std::string& str, std::vector<std::string>& cont) {
  std::istringstream iss(str);
  std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(), std::back_inserter(cont));
}