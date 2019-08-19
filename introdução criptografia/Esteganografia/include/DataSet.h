/**
 * @file DataSet.h
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-19
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
  std::string msg;

 public:
  DataSet(std::string);
  ~DataSet();
  std::string getMsg(void);
};

#endif /* DATASET_H_ */