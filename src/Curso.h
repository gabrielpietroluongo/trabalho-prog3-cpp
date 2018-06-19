//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_CURSO_H
#define TRABALHO_PROG3_CURSO_H

#include <string>
#include <iostream>

using namespace std;

namespace prog3 {

    class Curso {
    private:
        int codigo;
        string nome;
        bool grad;
    public:
        Curso(string = "", int = 0, bool = false);
        ~Curso();
        int getCodigo();
    };

}
#endif //TRABALHO_PROG3_CURSO_H
