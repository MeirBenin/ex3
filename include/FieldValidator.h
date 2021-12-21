
#pragma once
#include <cctype>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <iostream>
#include "Utilities.h"
//================================================================
//----------------------------------------------------------------
template <typename T>
class FieldValidator {
public:
    virtual bool isValid(T) = 0;
    virtual std::string getErorrMsg()const =0;
};
