
#pragma once
#include "FieldBase.h"
#include <sstream>
//================================================================
template <typename T>
class Field : public FieldBase {
    bool m_isEmptyFlag = true;
    T m_field;
    FieldValidator<T>* m_validator;
public:
    Field(std::string msg):FieldBase(msg){}
    bool isValid()const;
    void addValidator(FieldValidator<T>*);
    void readData();
    bool isEmpty()const;
    T getContent()const;
    std::string getDataString()const;
    std::string getErorrMsg()const;
};
//================================================================
template <typename T>
void Field<T>::readData(){
    std::cout << m_msg <<std::endl;
    std::cin >> m_field;
    m_isEmptyFlag = false;
}
//----------------------------------------------------------------
template <typename T>
std::string Field<T>::getDataString()const{
    auto tempStream = std::stringstream();
    tempStream << m_field;
    return tempStream.str();
}
//----------------------------------------------------------------
template <typename T>
std::string Field<T>::getErorrMsg()const{
    return m_validator -> getErorrMsg();
}
//----------------------------------------------------------------
template <typename T>
void Field<T>::addValidator(FieldValidator<T>* validator){
    m_validator = validator;
}
//----------------------------------------------------------------
template <typename T>
bool Field<T>::isValid() const{
    return m_validator -> isValid(m_field);
}
//----------------------------------------------------------------
template <typename T>
bool Field<T>::isEmpty() const{
    return m_isEmptyFlag;
}
//----------------------------------------------------------------
template <typename T>
T Field<T>::getContent()const{
    return m_field;
}
