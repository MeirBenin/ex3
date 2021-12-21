
#pragma once
#include "FieldValidator.h"
//================================================================
//----------------------------------------------------------------
class NoDigitValidator : public FieldValidator<std::string>{
    std::string m_erorrMsg = "Can't contain digits";
public:
    std::string getErorrMsg()const{return m_erorrMsg;}
    bool isValid(std::string);
};
//================================================================
bool is_digit(char c){return isdigit(c);}

bool NoDigitValidator::isValid(std::string str){
    return std::none_of(str.begin(), str.end(), is_digit);
}
