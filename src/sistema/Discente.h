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
    /**
     *****************************************************************************************
     *  @brief      Classe de domínio Discente
     *
     *  @usage      Utilizada na classe de domínio sistema
     *
     *  @param      string Nome do discente
     *  @param      long Matrícula do discente
     *  @param      Curso* Curso do discente
     *
     ****************************************************************************************/
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

        long getMatricula() { return this->matricula; }
        string getNome() { return this->nome; }

        // Operator overloads
        friend ostream &operator<<(ostream &os, const Discente &dis);

        friend ostream &operator<<(ostream &os, const Discente *dis);

    };

}
#endif //TRABALHO_PROG3_DISCENTE_H
