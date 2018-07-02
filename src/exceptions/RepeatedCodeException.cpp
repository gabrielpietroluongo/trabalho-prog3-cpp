//
// Created by gabriel on 02/07/18.
//

#include "RepeatedCodeException.h"

RepeatedCodeException::RepeatedCodeException(const Tipo& t, const string& code) {
    this->tipo = t;
    switch(this->tipo)
    {
        case DOCENTE:
            this->msg_ = "Código repetido para docente: " + code + ".";
            break;
        case DISCENTE:
            this->msg_ = "Código repetido para discente: " + code + ".";
            break;
        case CURSO:
            this->msg_ = "Código repetido para curso: " + code + ".";
            break;
        case DISCIPLINA:
            this->msg_ = "Código repetido para disciplina: " + code + ".";
            break;
    }
}