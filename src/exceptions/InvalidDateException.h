//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_INVALIDDATEEXCEPTION_H
#define TRABALHO_PROG3_INVALIDDATEEXCEPTION_H


#include <exception>
#include <string>

using namespace std;

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
