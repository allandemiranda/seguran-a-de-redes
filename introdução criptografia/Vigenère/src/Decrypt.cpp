/**
 * @file Decrypt.cpp
 * @author Allan de Miranda
 * @brief Descriptografia de dados
 * @version 0.1
 * @date 2019-08-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Decrypt.h"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Construct a new Decrypt:: Decrypt object
 *
 * @param msg Texto criptografado
 * @param alphabet Alfabeto da crifra
 * @param code Código ou senha da cifra
 */
Decrypt::Decrypt(DataSet msg, DataSet alphabet, std::string code) {
  // Criando mapa do alfabeto
  std::cout << std::endl;
  std::cout << "Crinado mapa do alfabeto ..." << std::endl;
  std::cout << std::endl;
  std::vector<std::vector<char>> mapAlphabet;
  for (auto i(0u); i < alphabet.getLine(0).size(); ++i) {
    std::vector<char> tempLine;
    for (auto j(0u); j < alphabet.getLine(0).size(); ++j) {
      auto position = j + i;
      if (position >= alphabet.getLine(0).size()) {
        position = position % alphabet.getLine(0).size();
      }
      tempLine.push_back(alphabet.getLine(0)[position]);
    }
    mapAlphabet.push_back(tempLine);
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  std::cout << std::endl;
  for (auto i(0u); i < mapAlphabet.size(); ++i) {
    for (auto j(0u); j < mapAlphabet[i].size(); ++j) {
      std::cout << mapAlphabet[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  std::cout << std::endl;

  // Gerando contra texto cifrado
  std::cout << std::endl;
  std::cout << "Gerando contra texto cifrado com a senha informada ..."
            << std::endl;
  std::cout << std::endl;
  std::vector<std::string> msgCode;
  auto condNumberPosition = 0;
  for (auto i(0u); i < msg.getNumberOfLine(); ++i) {
    std::string lineMsgCode;
    for (auto j(0u); j < msg.getLine(i).size(); ++j) {
      bool flag_not = true;
#pragma omp for
      for (unsigned long k = 0; k<mapAlphabet[0].size(); ++k){
        if (msg.getLine(i)[j] == mapAlphabet[0][k]){
#pragma omp critical
          { 
            flag_not = false;
            lineMsgCode.push_back(code[condNumberPosition++ % code.size()]);
          }
#pragma omp cancel for
        }
      }
      if(flag_not){
        lineMsgCode.push_back(msg.getLine(i)[j]);
      }
    }
    msgCode.push_back(lineMsgCode);
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  for (auto i(0u); i < msgCode.size(); ++i) {
    std::cout << msgCode[i] << std::endl;
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  std::cout << std::endl;

  // Decodificando texto
  std::cout << std::endl;
  std::cout << "Mensagem decodificada:" << std::endl;
  std::cout << std::endl;
  std::vector<std::string> msgDecode;
  for (auto i(0u); i < msgCode.size(); ++i) {
    std::string lineDecode;
    for (auto j(0u); j < msgCode[i].size(); ++j) {
      char lookingX = msg.getLine(i)[j];
      bool flag_not = true;
      char lookingY = msgCode[i][j];
      for (auto i(0u); i < mapAlphabet[0].size(); ++i) {        
        if (lookingY == mapAlphabet[i][0]) {
#pragma omp for
          for (unsigned long j = 0; j < mapAlphabet[i].size(); ++j) {
            if (lookingX == mapAlphabet[i][j]) {
#pragma omp critical
              { 
                lineDecode.push_back(mapAlphabet[0][j]); 
                flag_not = false;
              }
#pragma omp cancel for
            }
          }
          break;
        }        
      }
      if(flag_not){
        lineDecode.push_back(lookingY);
      }
    }
    msgDecode.push_back(lineDecode);
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  for (auto i(0u); i < msgDecode.size(); ++i) {
    std::cout << msgDecode[i] << std::endl;
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  std::cout << std::endl;
}

/**
 * @brief Destroy the Decrypt:: Decrypt object
 *
 */
Decrypt::~Decrypt() {}

/**
 * @brief Adicionar o código de descriptografia
 *
 * @param newCode Código ou senha
 */
void Decrypt::setCode(std::string newCode) {
  code = newCode;
}

/**
 * @brief Retorna o código usado
 *
 * @return std::string Código ou senha
 */
std::string Decrypt::getCode(void) {
  return code;
}