
#include "Form.h"
//================================================================
void Form::fillForm(){
    
    //It's ugly but at the fault of whoever wrote the mine.cc file....
    bool firstTimeflage = true;
    if (!m_fields[0] -> isEmpty()) firstTimeflage = false;
    
    for (int i = 0 ; i < m_fields.size(); i++) {
        if (m_fields[i] -> isEmpty() ||
            !m_fields[i] -> isValid() ){
            m_fields[i] -> readData();
        }
    }
    
    if (!firstTimeflage)
        for (int i = 0 ; i < m_validators.size(); i++)
            if (!m_validators[i] -> isValid() )
                m_validators[i] -> fillFields();
    
    
    
}

//----------------------------------------------------------------
void Form::addValidator(FormValidator* fv){
    m_validators.push_back(fv);
}
//----------------------------------------------------------------
bool Form::validateForm(){
    for (int i = 0 ; i < m_fields.size(); i++)
        if (!m_fields[i] -> isValid())
            return false;
    for (int i = 0 ; i < m_validators.size(); i++)
        if (!m_validators[i] -> isValid())
            return false;
    return true;
}
//----------------------------------------------------------------
//----------------------------------------------------------------
std::ostream& operator << (std::ostream& ostr, const Form& form)
{
    for (int i = 0; i < form.getFields().size(); i++) {
        ostr << "------------------------------------------------";
        ostr << std::endl;
        ostr << form.getFields()[i] -> getMsg();
        ostr << " = ";
        ostr << form.getFields()[i] -> getDataString();
        if (!form.getFields()[i] -> isValid()) {
            ostr << "    !!! ";
            ostr << form.getFields()[i] -> getErorrMsg();
        }
        ostr << std::endl;
        ostr << "------------------------------------------------";
        ostr << std::endl;
    }
    
    for (int i = 0; i < form.getFromValidators().size(); i++) {
        if (!form.getFromValidators()[i] -> isValid()){
            ostr << "------------------------------------------------";
            ostr << std::endl;
            ostr << form.getFromValidators()[i] -> getErorrMsg();
            ostr << std::endl;
            
        }
    }
    return ostr;
}
