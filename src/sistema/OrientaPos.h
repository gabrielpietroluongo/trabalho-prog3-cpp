//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ORIENTAPOS_H
#define TRABALHO_PROG3_ORIENTAPOS_H

#include <string>
#include <iostream>
#include <ctime>
#include "../utils/cpp_utils/DateUtils.h"

#include "Orientacao.h"

namespace prog3 {

    class OrientaPos : public Orientacao {
    private:
        time_t dataIngresso;
        string programa;
    public:
        OrientaPos(Docente& docente, int cargaSemanal, Discente& discente, string dataIngresso, string programa);
        ~OrientaPos();
    };

}
#endif //TRABALHO_PROG3_ORIENTAPOS_H
