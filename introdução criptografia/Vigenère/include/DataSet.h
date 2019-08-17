/**
 * @file DataSet.h
 * @author Allan de Miranda
 * @brief Classe para capturar textos
 * @version 0.1
 * @date 2019-08-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef DATASET_H_
#define DATASET_H_

#include <string>
#include <vector>

class DataSet {
 private:
  void split1(const std::string&, std::vector<std::string>&);
  std::vector<std::vector<std::string>> text;  // Texto capturado
 public:
  unsigned long getNumberOfLine();     // Número de linhas do texto
  std::vector<std::string> getLine(unsigned long);  // Pegar a linha
  DataSet(std::string);
  ~DataSet();
};

#endif /* DATASET_H_ */