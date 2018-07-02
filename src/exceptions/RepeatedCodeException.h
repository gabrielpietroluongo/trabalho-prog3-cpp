//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_REPEATEDCODEEXCEPTION_H
#define TRABALHO_PROG3_REPEATEDCODEEXCEPTION_H



#include <exception>
#include <string>

using namespace std;
/**
*****************************************************************************************
*  @brief     Exception de codigo repetido
*
*
*  @param      const Tipo&          Tipo do exception
*  @param      const string&        Codigo invalido
*
****************************************************************************************/
class RepeatedCodeException : public std::exception
{
public:
/**
*****************************************************************************************
*  @enum     Enum de tipos de codigo
*
****************************************************************************************/
    enum Tipo
    {
        DOCENTE,        ///< Docente
        DISCENTE,       ///< Discente
        CURSO,          ///< Curso
        DISCIPLINA      ///< Disciplina
    };

    explicit RepeatedCodeException(const Tipo& t, const string& code);

    virtual ~RepeatedCodeException() throw (){}

    virtual const char* what() const throw (){
        return msg_.c_str();
    }

protected:
    std::string msg_;           ///< Mensagem de erro
    Tipo tipo;                  ///< Tipo do erro
};



#endif //TRABALHO_PROG3_REPEATEDCODEEXCEPTION_H
