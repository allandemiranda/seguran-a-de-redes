/**
 * @file SubKeyGenerate.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "SubKeyGenerate.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Construct a new Sub Key Generate:: Sub Key Generate object
 *
 * @param keyMaster Chave principal
 */
SubKeyGenerate::SubKeyGenerate(std::string keyPath, unsigned long nodes,
                               std::string pMaster, std::string pSecond) {
  if (keyPath != "") {
    masterKeyPath = keyPath;
  }
  if (nodes != 0) {
    numberOfNodes = nodes;
  }
  if (pMaster != "") {
    PMaster = pMaster;
  }
  if (pSecond != "") {
    PSecond = pSecond;
  }
  masterKey = getMasterKey(keyPath);
  PMasterVector = explode(PMaster);
  PSecondVector = explode(PSecond);
}

SubKeyGenerate::~SubKeyGenerate() {}

/**
 * @brief Função para abrir ler arquivo da chave principal
 *
 * @param keyPath Caminho da chave
 * @return std::string Chave principal
 */
std::string SubKeyGenerate::getMasterKey(std::string keyPath) {
  std::string key;
  try {
    std::ifstream file(keyPath);
    std::string line;
    std::getline(file, line);
    key = line;
  } catch (const std::ios_base::failure& e) {
    std::cerr << "Erro ao abrir a chave" << std::endl;
  }
  return key;
}

/**
 * @brief Função para converter a string em um vetor de números
 *
 * @param P String com a sequência de manipulação
 * @return const std::vector<std::string>
 */
const std::vector<unsigned long> SubKeyGenerate::explode(const std::string& P) {
  char c = ' ';
  std::string buff{""};
  std::vector<unsigned long> v;

  for (auto n : P) {
    if (n != c) {
      buff += n;
    } else if (n == c && buff != "") {
      v.push_back(std::stoi(buff));
      buff = "";
    }
  }
  if (buff != "") {
    v.push_back(std::stoi(buff));
  }

  return v;
}

/**
 * @brief Verificador de consistência de configurações para geração de chave
 *
 * @param nSize Tamanho da chave principal
 * @param Pvector Vetor com refências de permutação de posições
 * @return true Posições compatíveis
 * @return false Posições não compatíveis
 */
bool SubKeyGenerate::checkPVector(unsigned long nSize,
                                  std::vector<unsigned long>& Pvector) {
  for (unsigned long i = 0; i < Pvector.size(); ++i) {
    if ((Pvector[i] < 0) or (Pvector[i] >= nSize)) {
      throw "Inconpatibilidade entre o tamanho da chave e configuração de criação";
    }
  }
}