//
// Created by gabriel on 19/06/18.
//

#include "OrientaPos.h"

namespace prog3 {

    OrientaPos::OrientaPos(Docente& docente, int cargaSemanal, Discente& discente, string dataIngresso,
                           string programa) : Orientacao(docente, cargaSemanal, discente) {
        this->programa = programa;
        this->dataIngresso = cpp_util::parseDate(dataIngresso, cpp_util::DATE_FORMAT_PT_BR_SHORT);
    }

    OrientaPos::~OrientaPos() {

    }
}
