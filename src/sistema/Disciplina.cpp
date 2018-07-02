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
        cur.adicionaHorasADocente(d, cSemestral);
        d.adicionaHorasAulaSemanais(cSemanal);
        d.adicionaHorasAulaSemestrais(cSemestral);
    }

    Disciplina::~Disciplina() {
    }

    vector<string> Disciplina::getCSVData() {
        vector<string> vec = {
                this->docente->getNome(),
                this->codigo,
                this->nome,
                std::to_string(this->cargaSemestral)
        };
        return vec;
    }

    bool operator<(Disciplina const& a, Disciplina const& b) {
        // Se o nome for igual, compara os codigos
        if(a.docente->getNome() == b.docente->getNome()) {
             return cpp_util::stringCompare(a.codigo, b.codigo);
        } else {
            return cpp_util::stringCompare(a.docente->getNome(), b.docente->getNome());
        }
    }
}