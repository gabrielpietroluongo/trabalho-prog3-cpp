//
// Created by gabriel on 18/06/18.
//

#include "Atividade.h"

namespace prog3 {
    Atividade::Atividade(Docente& d, int c) {
        this->docente = &d;
        this->cargaSemanal = c;
        d.adicionaAtividade(*this);
    }

    Atividade::~Atividade() {

    }
}