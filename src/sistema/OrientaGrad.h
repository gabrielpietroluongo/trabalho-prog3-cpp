//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ORIENTAGRAD_H
#define TRABALHO_PROG3_ORIENTAGRAD_H

#include "Orientacao.h"

namespace prog3 {

    class OrientaGrad : public Orientacao {
    private:
        Curso* curso;
    public:
        OrientaGrad(Docente& docente, Discente& discente, Curso& curso, int cargaSemanal);
        ~OrientaGrad();
    };

}

#endif //TRABALHO_PROG3_ORIENTAGRAD_H
