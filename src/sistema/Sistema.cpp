//
// Created by gabriel on 18/06/18.
//

#include "Sistema.h"

namespace prog3 {

    Sistema::Sistema(map<string, string> args) {

    	// Docente
    	icstream* stream = new icstream(args["-d"]);
    	for(auto elem : stream->getData()) {
    		adicionaDocente(atoi(elem[0].c_str()), elem[1], elem[2]);
    	}
    	delete stream;

    	// Produção
    	stream = new icstream(args["-p"]);
    	for(auto elem : stream->getData()) {
    		bool qualificada = false;
    		if(stream->getData().size() == 3) {
    			if(elem[3] == "X") {
    				qualificada = true;
    			}
    		}
    		adicionaProducao(atoi(elem[0].c_str()), elem[1], qualificada);
    	}
    	delete stream;

    	// Curso
    	stream = new icstream(args["-c"]);
    	for(auto elem : stream->getData()) {
    		bool grad = false;
    		if(elem[3] == "X") {
    			grad = true;
			}
    		adicionaCurso(atoi(elem[0].c_str()), elem[1], grad);
    	}
    	delete stream;

    	// Discente
    	stream = new icstream(args["-a"]);
		for(auto elem : stream->getData()) {
			adicionaDiscente(atol(elem[0].c_str()), elem[1], atoi(elem[2].c_str()));
		}
		delete stream;

		// Disciplinas
		stream = new icstream(args["-r"]);
		for(auto elem : stream->getData()) {
			adicionaDisciplina(elem[0], elem[1], atoi(elem[2].c_str()), atoi(elem[3].c_str()), atoi(elem[4].c_str()), atoi(elem[5].c_str()));
		}
		delete stream;

		// Orientação graduação
		stream = new icstream(args["-og"]);
		for(auto elem : stream->getData()) {
			adicionaOrientacaoGrad(atoi(elem[0].c_str()), atol(elem[1].c_str()), atoi(elem[2].c_str()), atoi(elem[3].c_str()));
		}
		delete stream;

		// Orientação graduação
		stream = new icstream(args["-og"]);
		for(auto elem : stream->getData()) {
			adicionaOrientacaoPos(atoi(elem[0].c_str()), atol(elem[1].c_str()), elem[2], elem[3], atoi(elem[4].c_str()));
		}
		delete stream;
    }

    Sistema::~Sistema() {
        //TODO
    }

    void Sistema::WIP_carrega_dados(map<string*, string*> args) {

    }

    void Sistema::WIP_Debug() {
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

    void Sistema::adicionaOrientacaoPos(int codigoDocente, long matriculaDiscente, string dataIngresso,
                               string programa, int cargaSemanal) {
        OrientaPos* o = new OrientaPos(*this->docentes[codigoDocente], cargaSemanal, *this->discentes[matriculaDiscente],
                                       dataIngresso, programa);
        this->atividades.push_back(o);
    }
}
