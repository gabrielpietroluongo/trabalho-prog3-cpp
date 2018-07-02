//
// Created by gabriel on 19/06/18.
//

#include "Disciplina.h"


using namespace std;

namespace prog3 {
    /**
     *****************************************************************************************
     *  @brief      Construtor da classe
     *
     *  @param      string Curso da disciplina
     *  @param      string Nome da disciplina
     *  @param      Docente& Docente responsavel pela disciplina
     *  @param      int Carga Semanal
     *  @param      int Carga Semestral
     *  @param      Curso& Curso relacionado
     *
     ****************************************************************************************/
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

    /**
    *****************************************************************************************
    *  @brief      Retorna os dados formatados em CSV para escrita na saida
    *
    *  @returns    vector<string> lista de strings para escrita
    *
    ****************************************************************************************/
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