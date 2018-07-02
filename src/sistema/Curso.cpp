#include "Curso.h"

namespace prog3 {
    /**
     *****************************************************************************************
     *  @brief      Classe de domínio Curso
     *
     *  @usage       Utilizada na classe de domínio sistema
     *
     *  @param      string Nome do curso
     *  @param      int Código do curso
     *  @param      bool É curso de graduação?
     *
     ****************************************************************************************/
    Curso::Curso(string n, int c, bool g) {
        this->nome = n;
        this->codigo = c;
        this->grad = g;
    }

    Curso::~Curso() {

    }

    int Curso::getCodigo() {
        return this->codigo;
    }

    void Curso::adicionaDiscente(Discente& d) {
        this->discentes.push_back(&d);
    }

    void Curso::adicionaDisciplina(Disciplina& d) {
        this->disciplinas.push_back(&d);
    }

    void Curso::adicionaOrientaGrad(OrientaGrad& o) {
        this->orientacoesGrad.push_back(&o);
    }

    void Curso::adicionaHorasADocente(Docente& doc, int val) {
        this->horasDocente[&doc] += val;
    }

}