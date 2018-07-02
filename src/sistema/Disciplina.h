//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_DISCIPLINA_H
#define TRABALHO_PROG3_DISCIPLINA_H

#include <iostream>
#include <string>

#include "Atividade.h"
#include "Curso.h"
#include "Docente.h"

using namespace std;

namespace prog3 {

    class Curso;

    class Disciplina : public Atividade {
    private:
        string codigo;
        string nome;
        int cargaSemestral;
        Curso* curso;
    public:
        Disciplina(string codigo, string nome, Docente& d, int cargaSemanal, int cargaSemestral, Curso& curso);
        ~Disciplina();
        vector<string> getCSVData();
        friend bool operator<(Disciplina const& a, Disciplina const& b);
    };
}

#endif //TRABALHO_PROG3_DISCIPLINA_H
