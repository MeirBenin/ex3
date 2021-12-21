#pragma once
#include "FieldValidator.h"
//================================================================
//----------------------------------------------------------------
template <typename T>
class DateValidator  :public FieldValidator<T> {
    std::string m_erorrMsg = "The date has passed";
public:
    std::string getErorrMsg()const{return m_erorrMsg;}
    bool isValid(T);
};
//----------------------------------------------------------------
template <typename T>
bool DateValidator<T>::isValid(T date){
    return (conventDataFormat(date) >= time(0));
}
//----------------------------------------------------------------
