/**
 * @file Decrypt.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "../include/Decrypt.h"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Construct a new Decrypt:: Decrypt object
 *
 * @param msg Texto cifrado
 * @param alphabet Alfabeto usando na codificação
 * @param code
 */
Decrypt::Decrypt(DataSet msg, DataSet alphabet, std::string code) {
  // std::vector<std::vector<char>> mapAlphabet;
  // for (auto i(0); i < alphabet.getLine(0).size(); ++i) {
  //   std::vector<char> tempLine;
  //   for (auto j(0); j < alphabet.getLine(0).size(); ++j) {
  //     auto position = j + i;
  //     if (position >= alphabet.getLine(0).size()) {
  //       position = position % alphabet.getLine(0).size();
  //     }
  //     tempLine.push_back(alphabet.getLine(0)[position]);
  //   }
  //   mapAlphabet.push_back(tempLine);
  // }

  // for (int i(0); i < msg.getNumberOfLine(); ++i) {
  //   for (int j(0); j < msg.getNumberOfLine(); ++j) {
  //     std::cout << msg.getLine(i)[j] << " * ";
  //   }
  //   std::cout << std::endl;
  // }
}

/**
 * @brief Destroy the Decrypt:: Decrypt object
 *
 */
Decrypt::~Decrypt() {}

/**
 * @brief Obter linha solicitada do texto
 *
 * @param numberLine Número da linha (inicia em 0)
 * @return std::string Texto da linha
 */
std::string Decrypt::getLine(unsigned int numberLine) {
  try {
    if (numberLine >= getNumberOfLine()) {
      throw("Valor maior que quantidade de linhas do texto");
    }
  } catch (std::string msg) {
    std::cerr << msg << '\n';
  }

  return decryptText[numberLine];
}

/**
 * @brief obter quantidade de linhas que tem no texto
 *
 * @return unsigned int Número de linhas do texto
 */
unsigned int Decrypt::getNumberOfLine(void) {
  return decryptText.size();
}

/**
 * @brief Adicionar o código de descriptografia
 *
 * @param newCode
 */
void Decrypt::setCode(std::string newCode) {
  code = newCode;
}

/**
 * @brief Retorna o código usado
 *
 * @return std::string
 */
std::string Decrypt::getCode(void) {
  return code;
}