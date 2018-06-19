//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_ATIVIDADE_H
#define TRABALHO_PROG3_ATIVIDADE_H

#include <iostream>
#include <string>
#include "Docente.h"

namespace prog3 {

    //Forward declaration
    class Docente;

    class Atividade {
    private:
        int cargaSemanal;
        Docente* docente;
    public:
        Atividade(Docente&, int = 0);
        ~Atividade();
    };
}

#endif //TRABALHO_PROG3_ATIVIDADE_H
