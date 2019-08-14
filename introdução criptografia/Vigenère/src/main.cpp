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

int main(int argc, char const* argv[]) {
  if (argc != 1) {
    std::cout << "Digite o númerodo de César corretamente" << std::endl;
    return 0;
  }

  if (atoi(argv[1]) < 0){
    std::cout << "Digite o númerodo de César corretamente" << std::endl;
    return 0;
  }

  unsigned int code = atoi(argv[1]);

  std::cout << "Abrindo arquivo criptografado" << std::endl;
  DataSet mensagem("data/mensagem.txt");
  std::cout << "Abrindo arquivo do alfabeto" << std::endl;
  DataSet alfabeto("data/alfabeto.txt");

  std::cout << "Descriptografando com código " << code << std::endl;
  Decrypt descriptografia(mensagem, alfabeto, code);
  std::cout << "Criando arquivo descriptografado com código " << code
            << std::endl;
  SetResult descriptografado(descriptografia);

  std::cout << "Descriptografia concluída" << std::endl;

  return 0;
}
