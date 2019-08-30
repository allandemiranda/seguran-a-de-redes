/**
 * @file KeyGenerate.h
 * @author Allan de Miranda
 * @brief Classe para geração das chaves usadas
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef KEYGENERATE_H_
#define KEYGENERATE_H_

#include <string>

class KeyGenerate {
 private:
  std::string keySavePath =
      "result/";  // Caminho para salvar a chave no formato string
 public:
  KeyGenerate(unsigned long);
  ~KeyGenerate(void);
};

#endif /* KEYGENERATE_H_ */
