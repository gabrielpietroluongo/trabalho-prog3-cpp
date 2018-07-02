//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_INVALIDDATEEXCEPTION_H
#define TRABALHO_PROG3_INVALIDDATEEXCEPTION_H


#include <exception>
#include <string>

using namespace std;
/**
*****************************************************************************************
*  @brief     Exception de data invalida.
*
*
*  Chamada quando a data de ingresso do discente esta no futuro
*
*
*  @param     const string&         Nome do discente
*  @param     const string&         Data invalida
*
****************************************************************************************/
class InvalidDateException : public std::exception
{
public:

    explicit InvalidDateException(const string& nome, const string& data);

    virtual ~InvalidDateException() throw (){}

    virtual const char* what() const throw (){
        return msg_.c_str();
    }

protected:

    std::string msg_;
};


#endif //TRABALHO_PROG3_INVALIDDATEEXCEPTION_H
