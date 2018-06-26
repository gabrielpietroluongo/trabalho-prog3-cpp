//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_DISCENTE_H
#define TRABALHO_PROG3_DISCENTE_H

#include <string>
#include <iostream>
#include <vector>

#include "Curso.h"

using namespace std;

namespace prog3 {

    //Forward declaration
    class Curso;
    class Orientacao;

    class Discente {
    private:
        string nome;
        long matricula;
        Curso* curso;
        vector<Orientacao*> orientacoes;
    public:
        Discente(string = "", long = 0, Curso* = NULL);
        ~Discente();
        void adicionaOrientacao(Orientacao& o);
    };

}
#endif //TRABALHO_PROG3_DISCENTE_H
