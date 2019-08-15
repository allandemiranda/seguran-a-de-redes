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
#include "SetResult.h"

int main(void) {
  std::cout << "Abrindo arquivo criptografado" << std::endl;
  DataSet mensagem("data/mensagem.txt");

  std::cout << "Abrindo arquivo do alfabeto" << std::endl;
  DataSet alfabeto("data/alfabeto.txt");

#pragma omp parallel for
  for (unsigned long i = 0; i < alfabeto.getLine(0).size(); ++i) {
    std::cout << "Descriptografando com código " << i << std::endl;
    Decrypt descriptografia(mensagem, alfabeto, i);
    std::cout << "Criando arquivo descriptografado com código " << i
              << std::endl;
    SetResult descriptografado(descriptografia);
  }

  std::cout << "Descriptografia concluída" << std::endl;

  return 0;
}
