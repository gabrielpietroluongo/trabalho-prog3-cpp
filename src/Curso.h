//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_CURSO_H
#define TRABALHO_PROG3_CURSO_H

#include <string>
#include <iostream>
#include <vector>

#include "Sistema.h"

using namespace std;

namespace prog3 {

    //Forward declaration
    class Discente;

    class Curso {
    private:
        int codigo;
        string nome;
        bool grad;
        vector<Discente*> discentes;
    public:
        Curso(string = "", int = 0, bool = false);
        ~Curso();
        int getCodigo();
        void adicionaDiscente(Discente &d);
    };

}
#endif //TRABALHO_PROG3_CURSO_H
