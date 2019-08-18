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

#include <algorithm>
#include <fstream>
#include <iostream>
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
 * @brief Obter a linha do texto
 *
 * @param numberLine Número da linha
 * @return std::string
 */
std::string DataSet::getLine(unsigned long numberLine) {
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
 * @brief Obter número de linhas que o texto possui
 *
 * @return unsigned long Número de linhas
 */
unsigned long DataSet::getNumberOfLine(void) {
  return text.size();
}