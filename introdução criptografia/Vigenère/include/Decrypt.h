/**
 * @file Decrypt.h
 * @author Allan de Miranda
 * @brief
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
  std::vector<std::string> decryptText;
  std::string code;
  void setCode(std::string);

 public:
  unsigned int getNumberOfLine();     // Número de linhas do texto
  std::string getLine(unsigned int);  // Pegar a linha
  std::string getCode();              // Pegar código de César
  Decrypt(DataSet, DataSet, std::string);
  ~Decrypt();
};

#endif /* DECRYPT_H_ */