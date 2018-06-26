//
// Created by gabriel on 18/06/18.
//

#include "Sistema.h"

namespace prog3 {

    Sistema::Sistema(map<string, string> args) {
        // WIP
        cout << args["-og"] << endl;
	/*
        if(arg == "-d") {
            this->fname_docente = fname;
        }
        else if (arg == "-a") {
            this->fname_discente = fname;
        }
        else if(arg == "-p") {
            this->fname_producao = fname;
        }
        else if(arg == "-c") {
            this->fname_curso = fname;
        }
        else if(arg == "-r") {
            this->fname_disciplina = fname;
        }
        else if(arg == "-og") {
            this->fname_ograd = fname;
        }
        else if(arg == "-op") {
            this->fname_opos = fname;
        }
        else {
            throw exception();
        }*/
    }

    Sistema::~Sistema() {
        //TODO
    }

    void Sistema::WIP_carrega_dados(map<string*, string*> args) {

    }

    void Sistema::adicionaDocente(int codigo, string nome, string departamento) {
        Docente *d = new Docente(codigo, nome, departamento);
        this->docentes.insert(pair<int, Docente*>(codigo, d));
    }

    void Sistema::adicionaDiscente(long matricula, string nome, int codigoCurso) {
        Discente* d = new Discente(nome, matricula, this->cursos[codigoCurso]);
        this->discentes.insert(pair<long, Discente*>(matricula, d));
    }

    void Sistema::adicionaProducao(int codigo, string titulo, bool qualificada) {
        Producao* p = new Producao(*this->docentes[codigo], titulo, qualificada);
        this->producoes.push_back(p);
    }

    void Sistema::adicionaCurso(int codigo, string nome, bool grad) {
        Curso* c = new Curso(nome, codigo, grad);
        this->cursos.insert(pair<int, Curso*>(codigo, c));
    }

    void Sistema::adicionaDisciplina(string codigoMateria, string nome, int codigoDocente, int cargaSemanal,
                            int cargaSemestral, int codigoCurso) {
        Disciplina* d = new Disciplina(codigoMateria, nome, *this->docentes[codigoDocente], cargaSemanal,
                                       cargaSemestral, *this->cursos[codigoCurso]);
        this->atividades.push_back(d);
    }

    void Sistema::adicionaOrientacaoGrad(int codigoDocente, long matriculaDiscente, int codigoCurso, int cargaSemanal) {
        OrientaGrad* o = new OrientaGrad(*this->docentes[codigoDocente], *this->discentes[matriculaDiscente],
                                         *this->cursos[codigoCurso], cargaSemanal);
        this->atividades.push_back(o);
    }

    void Sistema::adicionaOrientacaoPos(int codigoDocente, long matriculaDiscente, int dataIngresso,
                               string programa, int cargaSemanal) {
        OrientaPos* o = new OrientaPos(*this->docentes[codigoDocente], cargaSemanal, *this->discentes[matriculaDiscente],
                                       dataIngresso, programa);
    }
}
