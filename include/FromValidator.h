#pragma once
#include <string.h>
//================================================================
class FormValidator {
public:
    virtual bool isValid() = 0;
    virtual void fillFields() = 0;
    virtual std::string getErorrMsg() = 0;
};
