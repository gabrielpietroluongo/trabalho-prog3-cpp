//
// Created by gabriel on 19/06/18.
//

#include "Disciplina.h"


using namespace std;

namespace prog3 {
    Disciplina::Disciplina(string c, string n, Docente& d, int cSemanal, int cSemestral,
                           Curso& cur) : Atividade(d, cSemanal) {
        this->curso = &cur;
        this->nome = n;
        this->codigo = c;
        this->cargaSemestral = cSemestral;
        cur.adicionaDisciplina(*this);
        d.adicionaHorasAulaSemanais(cSemanal);
        d.adicionaHorasAulaSemestrais(cSemestral);
    }

    Disciplina::~Disciplina() {

    }
}