//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_PRODUCAO_H
#define TRABALHO_PROG3_PRODUCAO_H

#include <string>
#include <iostream>
#include "Docente.h"

using namespace std;

namespace prog3 {

    //Forward Declaration
    class Docente;

    class Producao {
    private:
        string titulo;
        bool qualificada;
        Docente* docente;
    public:
        Producao(Docente&, string = "", bool = false);
        ~Producao();
        bool isQualificada();
    };
}
#endif //TRABALHO_PROG3_PRODUCAO_H
