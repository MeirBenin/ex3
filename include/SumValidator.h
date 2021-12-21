
#pragma once
#include "FromValidator.h"
//================================================================
template <typename T>
class Field;
//================================================================
class SumValidator  :public FormValidator {
    Field<int> *m_total, *m_kids, *m_adults;
    std::string m_erorrMsg;
public:
    SumValidator(std::string erorrMsg, Field<int>* total, Field<int>* kids, Field<int>* adults)
                :m_erorrMsg(erorrMsg),m_total(total), m_kids(kids), m_adults(adults){}
    bool isValid();
    void fillFields();
    std::string getErorrMsg();
};
//================================================================
bool SumValidator::isValid(){
    return(m_total->getContent() == m_kids->getContent() + m_adults->getContent());
}
//------------------------------------------------------------
void SumValidator::fillFields(){
    m_total->readData();
    m_kids->readData();
    m_adults->readData();
}
//------------------------------------------------------------
std::string SumValidator::getErorrMsg(){
    return m_erorrMsg;
}
