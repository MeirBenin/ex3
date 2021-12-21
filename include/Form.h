#pragma once
#include "Field.h"
#include <vector>
#include "FromValidator.h"
//================================================================
//----------------------------------------------------------------
class Form  {
    std::vector <FieldBase*> m_fields;
    std::vector <FormValidator*> m_validators;
public:
    template <typename T>
    void addField(Field<T>* newField);
    void fillForm();
    bool validateForm();
    void addValidator(FormValidator*);
    const std::vector<FieldBase*>& getFields() const{return m_fields;}
    const std::vector<FormValidator*>& getFromValidators() const{return m_validators;}
    
};
//================================================================
template <typename T>
void Form::addField(Field<T>* newField){
    m_fields.push_back(newField);
}
std::ostream& operator << (std::ostream& ostr, const Form& form);
