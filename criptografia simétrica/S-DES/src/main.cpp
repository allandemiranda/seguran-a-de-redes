/**
 * @file main.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "KeyGenerate.h"
#include "SubKeyGenerate.h"

#include <iostream>
#include <string>

int main(int argc, char const* argv[]) {
  // Opção para o gerador de chave
  if (argc == 3) {
    std::string option = argv[1];
    if (option == "newKey") {
      unsigned long keySize = atoi(argv[2]);
      try {
        KeyGenerate novaChave(keySize, "");
        std::cout << "Chave criada com sucesso" << std::endl;
      } catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
    }
  }
  if (argc == 4) {
    std::string option = argv[1];
    if (option == "newKey") {
      unsigned long keySize = atoi(argv[2]);
      std::string pach = argv[3];
      try {
        KeyGenerate novaChave(keySize, pach);
        std::cout << "Chave criada com sucesso" << std::endl;
      } catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
    }
  }

  // Codificar 
  
  try {
    SubKeyGenerate novo("", 0, "", "");
  } catch (const char* msg) {
    std::cerr << msg << std::endl;
  }

  return 0;
}
