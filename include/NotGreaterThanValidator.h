#pragma once
#include "FieldValidator.h"
//================================================================
template <typename T>
class NotGreaterThanValidator  :public FieldValidator<T> {
    T m_rooms;
    std::string m_erorrMsg = "The maximum is "+ std::to_string(m_rooms)+" rooms";
public:
    std::string getErorrMsg()const{return m_erorrMsg;}
    NotGreaterThanValidator(T num):m_rooms(num){};
    bool isValid(T);
};
//================================================================
template <typename T>
bool NotGreaterThanValidator<T>::isValid(T num){
    return (num <= m_rooms);
}
