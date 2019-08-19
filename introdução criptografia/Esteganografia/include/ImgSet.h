/**
 * @file ImgSet.h
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-19
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef IMGSET_H_
#define IMGSET_H_

#include <string>
#include <vector>

class ImgSet
{
private:
    std::vector <std::string> img;
public:
    ImgSet(std::string);
    ~ImgSet();
};

#endif /* IMGSET_H_ */