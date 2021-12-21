#pragma once
#include "FieldValidator.h"
//================================================================
//----------------------------------------------------------------
template <typename T>
class NonNegativeValidator  :public FieldValidator<T> {
    std::string m_erorrMsg = "Can't be negative";
public:
    std::string getErorrMsg()const{return m_erorrMsg;}
    bool isValid(T);
};
//================================================================
template <typename T>
bool NonNegativeValidator<T>::isValid(T n){
    return (n > 0);
}
