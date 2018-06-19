//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ORIENTACAO_H
#define TRABALHO_PROG3_ORIENTACAO_H

#include <iostream>
#include <string>

#include "Atividade.h"
#include "Discente.h"

using namespace std;

namespace prog3 {

    class Orientacao : public Atividade {
    private:
        Discente* discente;
    public:
        Orientacao(Docente& docente, int cargaSemanal, Discente& discente);
    };
}

#endif //TRABALHO_PROG3_ORIENTACAO_H
