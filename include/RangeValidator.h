#pragma once
#include "FieldValidator.h"
//================================================================
template <typename T>
class RangeValidator :public FieldValidator<int> {
    T m_minYear;
    T m_maxYear;
    std::string m_erorrMsg = "Out of range";
public:
    std::string getErorrMsg()const{return m_erorrMsg;}
    RangeValidator(T min,T max): m_minYear(min),m_maxYear(max){}
    bool isValid(T);
};
//================================================================
template <typename T>
bool  RangeValidator<T>::isValid(T Year){
    return (Year > m_minYear && Year < m_maxYear);
}
