#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "FieldValidator.h"
//================================================================
class FieldBase{
protected:
    std::string m_msg;
public:
    FieldBase(std::string msg):m_msg(msg){}
    std::string getMsg()const {return m_msg;}
    virtual bool isValid()const =0;
    virtual bool isEmpty()const =0;
    virtual std::string getErorrMsg()const =0;
    virtual void readData() =0;
    virtual std::string getDataString()const =0;
};


