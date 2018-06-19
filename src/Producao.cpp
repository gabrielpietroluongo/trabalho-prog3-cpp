//
// Created by gabriel on 18/06/18.
//

#include "Producao.h"

namespace prog3 {

    Producao::Producao(Docente& d, string t, bool q) {
        this->titulo = t;
        this->docente = &d;
        this->qualificada = q;
    }

    Producao::~Producao() {

    }
}