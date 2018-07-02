//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_REPEATEDCODEEXCEPTION_H
#define TRABALHO_PROG3_REPEATEDCODEEXCEPTION_H



#include <exception>
#include <string>

using namespace std;

class RepeatedCodeException : public std::exception
{
public:

    enum Tipo
    {
        DOCENTE,
        DISCENTE,
        CURSO,
        DISCIPLINA
    };

    explicit RepeatedCodeException(const Tipo& t, const string& code);

    virtual ~RepeatedCodeException() throw (){}

    virtual const char* what() const throw (){
        return msg_.c_str();
    }

protected:
    std::string msg_;
    Tipo tipo;
};



#endif //TRABALHO_PROG3_REPEATEDCODEEXCEPTION_H
