/**
 * @file Decrypt.h
 * @author Allan de Miranda
 * @brief Descriptografia de dados
 * @version 0.1
 * @date 2019-08-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef DECRYPT_H_
#define DECRYPT_H_

#include <string>
#include <vector>

#include "DataSet.h"

class Decrypt {
 private:
  std::string code;           // Guardar o código
  void setCode(std::string);  // Gravar código

 public:
  std::string getCode();  // Pegar código
  Decrypt(DataSet, DataSet, std::string);
  ~Decrypt();
};

#endif /* DECRYPT_H_ */