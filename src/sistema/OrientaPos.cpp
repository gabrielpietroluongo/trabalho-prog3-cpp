//
// Created by gabriel on 19/06/18.
//

#include "OrientaPos.h"

namespace prog3 {

    OrientaPos::OrientaPos(Docente& docente, int cargaSemanal, Discente& discente, int dataIngresso,
                           string programa) : Orientacao(docente, cargaSemanal, discente) {
        this->dataIngresso = dataIngresso;
        this->programa = programa;
    }

    OrientaPos::~OrientaPos() {

    }
}