/**
 * @file SaveBinaryFile.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Class para salvar arquivo binário gerado
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SAVEBINARYFILE_H_
#define SAVEBINARYFILE_H_

#include <string>  // std::string
#include <vector>  // std::vector

class SaveBinaryFile {
 public:
  SaveBinaryFile(std::vector<char>, std::string);
  ~SaveBinaryFile(void);
};

#endif