//
// Created by gabriel on 18/06/18.
//

#include "Curso.h"

namespace prog3 {

    Curso::Curso(string n, int c, bool g) {
        this->nome = n;
        this->codigo = c;
        this->grad = g;
    }

    Curso::~Curso() {

    }
    int Curso::getCodigo() {
        return this->codigo;
    }
}