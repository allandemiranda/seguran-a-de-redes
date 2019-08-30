/**
 * @file KeyGenerate.cpp
 * @author Allan de Miranda
 * @brief Métodos da classe KeyGenerate
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "KeyGenerate.h"

#include <bitset>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

/**
 * @brief Construct a new Key Generate:: Key Generate object
 *
 * @param keySize Tamanho da chake em bit's a ser gerada
 */
KeyGenerate::KeyGenerate(unsigned long keySize) {
  std::time_t time = std::time(NULL);  // Hora do sistema
  std::string timeString =
      std::asctime(std::localtime(&time));  // Transformar data em string
  unsigned long timeStringSize =
      timeString.size();  // Tamanho da string da data
  std::string key;        // Chave final
  std::srand(std::time(nullptr));
  for (auto i(0u); i < keySize; ++i) {
    unsigned long positionDate =
        std::rand() / ((RAND_MAX + 1u) /
                       timeStringSize);  // Pegar uma posição aleatória da data
    unsigned int positionBit =
        std::rand() /
        ((RAND_MAX + 1u) / 8);  // Pegar uma posição aleatória de 8 bits
    key.push_back(
        std::bitset<8>(timeString[positionDate]).to_string()[positionBit]);
  }
  std::ofstream newFile;
  keySavePath += "KEY.sdes";
  newFile.open(keySavePath, std::ios::app);
  for (char n : key) {
    newFile << n;
  }
  newFile.close();
}

/**
 * @brief Destroy the Key Generate:: Key Generate object
 *
 */
KeyGenerate::~KeyGenerate() {}
