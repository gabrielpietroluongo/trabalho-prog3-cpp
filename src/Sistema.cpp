//
// Created by gabriel on 18/06/18.
//

#include "Sistema.h"

namespace prog3 {

    Sistema::Sistema() {
        //Void?
    }

    Sistema::~Sistema() {
        //TODO
    }

    void Sistema::WIP_carrega_dados() {

    }

    void Sistema::adicionaDocente(int codigo, string nome, string departamento) {
        Docente *d = new Docente(codigo, nome, departamento);
        this->docentes.insert(pair<int, Docente>(codigo, d));
    }

    void Sistema::adicionaDiscente(long matricula, string nome, int codigoCurso) {
        //TODO
    }

    void Sistema::adicionaProducao(int codigo, string titulo, bool qualificada) {
        //TODO
    }

    void Sistema::adicionaCurso(int codigo, string nome, bool grad) {
        Curso* c = new Curso(nome, codigo, grad);
        this->cursos.insert(pair<int, Curso>(codigo, nome));
    }

    void Sistema::adicionaDisciplina(int codigoMateria, string nome, int codigoDocente, int cargaSemanal,
                            int cargaSemestral, int codigoCurso) {
        //TODO
    }

    void Sistema::adicionaOrientacaoGrad(int codigoDocente, long matriculaDiscente, int codigoCurso, int cargaSemanal) {
        //TODO
    }

    void Sistema::adicionaOrientacaoPos(int codigoDocente, int matriculaDiscente, int dataIngresso,
                               string programa, int cargaSemanal) {
        //TODO
    }
}