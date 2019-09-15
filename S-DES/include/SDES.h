/**
 * @file SDES.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class com funcinalidades do S-DES
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SDES_H_
#define SDES_H_

#include <string>    // std::string

class SDES {
 public:
  SDES(std::string, std::string, std::string);
  SDES(std::string, std::string);
  ~SDES(void);
};

#endif