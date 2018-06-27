//
// Created by gabriel on 19/06/18.
//

#include "Orientacao.h"

namespace prog3 {
    Orientacao::Orientacao(Docente& docente, int cargaSemanal, Discente& discente) : Atividade(docente, cargaSemanal) {
        this->discente = &discente;
        this->discente->adicionaOrientacao(*this);
    }
    Orientacao::~Orientacao() {

    }
}