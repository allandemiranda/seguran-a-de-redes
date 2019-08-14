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
      text.push_back(line);
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
 * @return std::string Texto da linha
 */
std::string DataSet::getLine(unsigned int numberLine) {
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