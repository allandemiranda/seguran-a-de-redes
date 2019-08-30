/**
 * @file SubKeyGenerate.h
 * @author Allan de Miranda
 * @brief Gerador de sub chaves
 * @version 0.1
 * @date 2019-08-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SUBKEYGENERATE_H_
#define SUBKEYGENERATE_H_

#include <string>
#include <vector>

class SubKeyGenerate
{
private:
    void getFeistelConfig(void); // Pegar as configurações Feistel
    std::string feistelConfigPath = "data/feistelConfig.txt"; // Local do arquivo
    std::string feistelConfigVector[3]; // Armazenar as configurações Feistel
public:
    std::vector <std::string> subKey; // Sub chaves finais em ordem de execulção
    SubKeyGenerate(std::string);
    ~SubKeyGenerate(void);
};




#endif /* SUBKEYGENERATE_H_ */