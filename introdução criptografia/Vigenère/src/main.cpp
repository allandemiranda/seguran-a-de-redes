/**
 * @file main.cpp
 * @author Allan de Miranda
 * @brief Main
 * @version 0.1
 * @date 2019-08-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>
#include <string>

#include "DataSet.h"
#include "Decrypt.h"

int main(int argc, char const* argv[]) {
  std::string code = argv[1];

  std::cout << "Abrindo arquivo criptografado" << std::endl;
  std::cout << std::endl;
  DataSet mensagem("data/mensagem.txt");
  std::cout << "----------------------------------------------------------"
            << std::endl;
  for (int i(0); i < mensagem.getNumberOfLine(); ++i) {
    std::cout << mensagem.getLine(i) << std::endl;
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "Abrindo arquivo do alfabeto" << std::endl;
  DataSet alfabeto("data/alfabeto.txt");

  std::cout << std::endl;
  std::cout << "----------------------------------------------------------"
            << std::endl;
  for (int i(0); i < alfabeto.getNumberOfLine(); ++i) {
    std::cout << alfabeto.getLine(i) << std::endl;
  }
  std::cout << "----------------------------------------------------------"
            << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "Descriptografando com código " << code << std::endl;
  Decrypt descriptografia(mensagem, alfabeto, code);

  return 0;
}
