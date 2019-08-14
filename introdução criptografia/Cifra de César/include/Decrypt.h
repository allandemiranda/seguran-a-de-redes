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
  unsigned long code;
  void setCode(unsigned long);

 public:
  unsigned int getNumberOfLine();     // Número de linhas do texto
  std::string getLine(unsigned int);  // Pegar a linha
  unsigned long getCode();            // Pegar código de César
  Decrypt(DataSet, DataSet, unsigned long);
  ~Decrypt();
};

#endif /* DECRYPT_H_ */