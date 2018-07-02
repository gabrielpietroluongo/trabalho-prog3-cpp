//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_CLASSINCONSISTENCYEXCEPTION_H
#define TRABALHO_PROG3_CLASSINCONSISTENCYEXCEPTION_H


#include <exception>
#include <string>

using namespace std;
/**
    *****************************************************************************************
    *  @brief      Exception de inconsistencias
    *
    *  @param      const string& codigo      Codigo inconsistente
    *  @param      const string& nome        Nome do curso inconsistente
    *
    ****************************************************************************************/
class ClassInconsistencyException : public std::exception
{
public:

    explicit ClassInconsistencyException(const string& codigo, const string& nome);

    virtual ~ClassInconsistencyException() throw (){}

    virtual const char* what() const throw (){
        return msg_.c_str();
    }

protected:

    std::string msg_;       ///< Mensagem de erro
};



#endif //TRABALHO_PROG3_CLASSINCONSISTENCYEXCEPTION_H
