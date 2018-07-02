//
// Created by gabriel on 02/07/18.
//

#ifndef TRABALHO_PROG3_CLASSINCONSISTENCYEXCEPTION_H
#define TRABALHO_PROG3_CLASSINCONSISTENCYEXCEPTION_H


#include <exception>
#include <string>

using namespace std;

class ClassInconsistencyException : public std::exception
{
public:

    explicit ClassInconsistencyException(const string& codigo, const string& nome);

    virtual ~ClassInconsistencyException() throw (){}

    virtual const char* what() const throw (){
        return msg_.c_str();
    }

protected:

    std::string msg_;
};



#endif //TRABALHO_PROG3_CLASSINCONSISTENCYEXCEPTION_H
