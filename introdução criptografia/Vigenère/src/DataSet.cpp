/**
 * @file DataSet.cpp
 * @author Allan de Miranda
 * @brief
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

void split1(const std::string& str, std::vector<std::string>& cont) {
  std::istringstream iss(str);
  std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(), std::back_inserter(cont));
}

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
 * @brief Obter linha solicitada do texto
 *
 * @param numberLine Número da linha (inicia em 0)
 * @return std::vector<std::string>
 */
std::vector<std::string> DataSet::getLine(unsigned int numberLine) {
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
 * @brief obter quantidade de linhas que tem no texto
 *
 * @return unsigned int Número de linhas do texto
 */
unsigned int DataSet::getNumberOfLine(void) {
  return text.size();
}