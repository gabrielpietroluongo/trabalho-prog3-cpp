//
// Created by gabriel on 19/06/18.
//

#include "OrientaGrad.h"
namespace prog3 {

    OrientaGrad::OrientaGrad(Docente& docente, Discente& discente,
                             Curso& curso, int cargaSemanal) : Orientacao(docente, cargaSemanal, discente) {
        this->curso = &curso;
        this->curso->adicionaOrientaGrad(*this);
    }

    OrientaGrad::~OrientaGrad() {

    }
}