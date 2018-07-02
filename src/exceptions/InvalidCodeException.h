//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_INVALIDCODEEXCEPTION_H
#define TRABALHO_PROG3_INVALIDCODEEXCEPTION_H


#include <exception>
#include <string>

using namespace std;
/**
*****************************************************************************************
*  @brief      Exception de codigos invalidos
*
*  @param      const Tipo&               Tipo do codigo inconsistente
*  @param      const string&             Codigo inconsistente
*  @param      const string&             Nome do objeto de codigo inconsistente
*
****************************************************************************************/
class InvalidCodeException : public std::exception
{
public:
    /**
    *****************************************************************************************
    *  @brief     Enum de tipos de erro
    *  @enum      Enum de tipos de erro
    *
    ****************************************************************************************/
    enum Tipo
    {
        DOCENTE_DISCIPLINA,         ///< Codigo de docente invalido na disciplina
        DOCENTE_ORIENTACAO,         ///< Codigo de docente invalido na orientacao
        DOCENTE_PUBLICACAO,         ///< Codigo de docente invalido na publicacao
        CURSO_ORIENTACAO,           ///< Codigo de curso invalido na orientacao
        CURSO_DISCIPLINA            ///< Codigo de curso invalido na disciplina
    };

    explicit InvalidCodeException(const Tipo& tipo, const string& code, const string& nome);

    virtual ~InvalidCodeException() throw (){}

    virtual const char* what() const throw (){
        return msg_.c_str();
    }

protected:
    std::string msg_;       ///< Mensagem de erro
    Tipo tipo;              ///< Tipo de erro
};


#endif //TRABALHO_PROG3_INVALIDCODEEXCEPTION_H
