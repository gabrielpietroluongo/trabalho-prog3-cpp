//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_DISCENTE_H
#define TRABALHO_PROG3_DISCENTE_H

#include <string>
#include <iostream>
#include "Curso.h"

using namespace std;

namespace prog3 {

    //Forward declaration
    class Curso;

    class Discente {
    private:
        string nome;
        long matricula;
        Curso* curso;
    public:
        Discente(string = "", long = 0, Curso* = nullptr);
        ~Discente();
    };

}
#endif //TRABALHO_PROG3_DISCENTE_H
