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

/**
 * @brief Construct a new Decrypt:: Decrypt object
 *
 * @param msg Texto cifrado
 * @param alphabet Alfabeto usando na codificação
 * @param code Número de César
 */
Decrypt::Decrypt(DataSet msg, DataSet alphabet, unsigned long code) {
  setCode(code);

  try {
    if (alphabet.getNumberOfLine() > 1) {
      throw("O alfabeto deve está todo em uma única linha");
    }
  } catch (std::string msg) {
    std::cerr << msg << std::endl;
  }

  for (auto i(0); i < msg.getNumberOfLine(); ++i) {
    std::string newLineDecrypt = "";
    for (auto j(0); j < msg.getLine(i).size(); ++j) {
      for (auto k(0); k < alphabet.getLine(0).size(); ++k) {
        if (alphabet.getLine(0)[k] == msg.getLine(i)[j]) {
          auto position = (k + getCode()) % alphabet.getLine(0).size();
          newLineDecrypt = newLineDecrypt + alphabet.getLine(0)[position];
          break;
        }
      }
    }
    decryptText.push_back(newLineDecrypt);
  }
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
 * @param newCode Códgo de César
 */
void Decrypt::setCode(unsigned long newCode) {
  code = newCode;
}

/**
 * @brief Retorna o código usado
 *
 * @return unsigned long Código de César
 */
unsigned long Decrypt::getCode(void) {
  return code;
}