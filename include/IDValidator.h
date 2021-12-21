#pragma once
#include "FieldValidator.h"
//============================================================
class IDValidator  :public FieldValidator<uint32_t> {
    std::string m_erorrMsg = "Wrong control digit";
public:
    std::string getErorrMsg()const{return m_erorrMsg;}
    bool isValid(uint32_t);
};
//------------------------------------------------------------
bool IDValidator::isValid(uint32_t id){
    unsigned int sum = 0, tempNum, Weight, validNum;
    
    if (numLength(id) != 9)return false;
    
    validNum = id % 10;
    id /= 10;
    
    for (int i = 0; i < 8; i++) {
        Weight = (i % 2)? 1:2;
        tempNum = id % 10 ;
        tempNum = tempNum * Weight;
        sum += (tempNum > 9) ? tempNum - 9 : tempNum;
        id /= 10;
    }
    return (((sum + validNum) % 10) == 0);
     
}
