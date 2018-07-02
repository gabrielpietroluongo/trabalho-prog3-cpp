//
// Created by gabriel on 02/07/18.
//

#include "InvalidCodeException.h"

/**
    *****************************************************************************************
    *  @brief      Construtor da classe
    *
    *  @param      const Tipo&               Tipo do codigo inconsistente
    *  @param      const string&             Codigo inconsistente
    *  @param      const string&             Nome do objeto de codigo inconsistente
    *
    ****************************************************************************************/
InvalidCodeException::InvalidCodeException(const Tipo& tipo, const string& code_conv, const string& name) {
    this->tipo = tipo;
    switch(this->tipo)
    {
        case DOCENTE_DISCIPLINA:
            this->msg_ = "Código de docente inválido na disciplina \"" + name + "\": " + code_conv + ".";
            break;
        case DOCENTE_ORIENTACAO:
            this->msg_ = "Código de docente inválido na orientação do aluno \"" + name + "\": " + code_conv + ".";
            break;
        case DOCENTE_PUBLICACAO:
            this->msg_ = "Código de docente inválido na publicação \"" + name + "\": " + code_conv + ".";
            break;
        case CURSO_ORIENTACAO:
            this->msg_ = "Código de curso inválido na orientação do aluno \"" + name + "\": " + code_conv + ".";
            break;
        case CURSO_DISCIPLINA:
            this->msg_ = "Código de curso inválido na disciplina \"" + name + "\": " + code_conv + ".";
            break;
    }
}