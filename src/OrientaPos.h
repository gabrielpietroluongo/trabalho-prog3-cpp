//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ORIENTAPOS_H
#define TRABALHO_PROG3_ORIENTAPOS_H

#include <string>
#include <iostream>

#include "Orientacao.h"

namespace prog3 {

    class OrientaPos : public Orientacao {
    private:
        int dataIngresso;
        string programa;
    public:
        OrientaPos(Docente& docente, int cargaSemanal, Discente& discente, int dataIngresso, string programa);
        ~OrientaPos();
    };

}
#endif //TRABALHO_PROG3_ORIENTAPOS_H
