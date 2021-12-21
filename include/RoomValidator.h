#pragma once
#include "FromValidator.h"
//================================================================
class RoomValidator  :public FormValidator {
    Field<int> *m_total, *m_pair, *m_family;
    std::string m_erorrMsg;
    bool m_isEmpty = true;
public:
    RoomValidator(std::string erorrMsg, Field<int>* pair, Field<int>* family, Field<int>* total)
         : m_erorrMsg(erorrMsg), m_total(total), m_pair(pair), m_family(family){}
    bool isValid();
    void fillFields();
    std::string getErorrMsg();
};
//================================================================
bool RoomValidator::isValid(){
    return (m_total->getContent() <= m_family->getContent()*5 + m_pair->getContent()*2);
}
//------------------------------------------------------------
void RoomValidator::fillFields(){
    m_total->readData();
    m_family->readData();
    m_pair->readData();
}
//------------------------------------------------------------
std::string RoomValidator::getErorrMsg(){
    return m_erorrMsg;
}
