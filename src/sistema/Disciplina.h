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
    /**
    *****************************************************************************************
    *  @brief      Classe de dominio Disciplina
    *
    *  @param      string Curso da disciplina
    *  @param      string Nome da disciplina
    *  @param      Docente& Docente responsavel pela disciplina
    *  @param      int Carga Semanal
    *  @param      int Carga Semestral
    *  @param      Curso& Curso relacionado
    *
    ****************************************************************************************/
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
        string getCodigo() { return this->codigo; }
        friend bool operator<(Disciplina const& a, Disciplina const& b);
    };
}

#endif //TRABALHO_PROG3_DISCIPLINA_H
