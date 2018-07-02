//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ORIENTAGRAD_H
#define TRABALHO_PROG3_ORIENTAGRAD_H

#include "Orientacao.h"

namespace prog3 {
    /**
       *****************************************************************************************
       *  @brief      Classe de dominio Orientaçao de Graduaçao
       *
       *  @params Docente& Docente responsavel pela orientaçao
       *  @params Discente& Discente orientado
       *  @params Curso& Curso do discente
       *  @params int Carga Semanal da orientaçao
       *
       ****************************************************************************************/
    class OrientaGrad : public Orientacao {
    private:
        Curso* curso;
    public:
        OrientaGrad(Docente& docente, Discente& discente, Curso& curso, int cargaSemanal);
        ~OrientaGrad();
    };

}

#endif //TRABALHO_PROG3_ORIENTAGRAD_H
