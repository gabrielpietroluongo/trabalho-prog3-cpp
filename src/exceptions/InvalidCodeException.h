//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_INVALIDCODEEXCEPTION_H
#define TRABALHO_PROG3_INVALIDCODEEXCEPTION_H


#include <exception>
#include <string>

using namespace std;

class InvalidCodeException : public std::exception
{
public:

    enum Tipo
    {
        DOCENTE_DISCIPLINA,
        DOCENTE_ORIENTACAO,
        DOCENTE_PUBLICACAO,
        CURSO_ORIENTACAO,
        CURSO_DISCIPLINA
    };

    explicit InvalidCodeException(const Tipo& tipo, const string& code, const string& nome);

    virtual ~InvalidCodeException() throw (){}

    virtual const char* what() const throw (){
        return msg_.c_str();
    }

protected:
    std::string msg_;
    Tipo tipo;
};


#endif //TRABALHO_PROG3_INVALIDCODEEXCEPTION_H
