//
// Created by gabriel on 18/06/18.
//

#include "Discente.h"

namespace prog3 {

    Discente::Discente(string n, long m, Curso* c) {
        this->nome = n;
        this->matricula = m;
        this->curso = c;
        c->adicionaDiscente(*this);
    }

    Discente::~Discente() {

    }

    void Discente::adicionaOrientacao(Orientacao& o) {
        this->orientacoes.push_back(&o);
    }

}