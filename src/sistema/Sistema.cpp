//
// Created by gabriel on 18/06/18.
//

#include <algorithm>
#include "Sistema.h"
#include "../utils/ocstream.h"

namespace prog3 {

    Sistema::Sistema(map<string, string> args) {

    	// Docente
    	icstream* stream = new icstream(args["-d"]);
    	for(vector<string> vec : stream->getData()) {
            adicionaDocente(stoi(vec[0]), vec[1], vec[2]);

    	}
    	delete stream;

    	// Produção
    	stream = new icstream(args["-p"]);
    	for(auto elem : stream->getData()) {
    		bool qualificada = false;
    		if(elem.size() == 3) {
    			if(elem[2] == "X") {
    				qualificada = true;
    			}
    		}
    		adicionaProducao(stoi(elem[0]), elem[1], qualificada);
    	}
    	delete stream;

    	// Curso
    	stream = new icstream(args["-c"]);
    	for(auto elem : stream->getData()) {
    		bool grad = false;
    		if(elem[2] == elem[3]) {
    		    throw "popopoy";
    		}
    		if(elem[3] == "X") {
    			grad = true;
			}
    		adicionaCurso(stoi(elem[0]), elem[1], grad);
    	}
    	delete stream;

    	// Discente
    	stream = new icstream(args["-a"]);
		for(auto elem : stream->getData()) {
			adicionaDiscente(stol(elem[0]), elem[1], stoi(elem[2]));
		}
		delete stream;

		// Disciplinas
		stream = new icstream(args["-r"]);
		for(auto elem : stream->getData()) {
			adicionaDisciplina(elem[0], elem[1], stoi(elem[2]), stoi(elem[3]), stoi(elem[4]), stoi(elem[5]));
		}
		delete stream;

		// Orientação graduação
		stream = new icstream(args["-og"]);
		for(auto elem : stream->getData()) {
			adicionaOrientacaoGrad(stoi(elem[0]), stol(elem[1]), stoi(elem[2]), stoi(elem[3]));
		}
		delete stream;

		// Orientação pós
		stream = new icstream(args["-op"]);
		for(auto elem : stream->getData()) {
			adicionaOrientacaoPos(stoi(elem[0]), stol(elem[1]), elem[2], elem[3], stoi(elem[4]));
		}
		delete stream;
    }

    Sistema::~Sistema() {
        //TODO
    }

    void Sistema::WIP_carrega_dados(map<string*, string*> args) {

    }

    void Sistema::WIP_Debug() {
        for(auto it = this->docentes.cbegin(); it != this->docentes.cend(); ++it)
        {
            std::cout << it->second << "\n";
        }
        for(auto it = this->discentes.cbegin(); it != this->discentes.cend(); ++it)
        {
            std::cout << it->second << "\n";
        }
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
        map<int, Curso*>::iterator it = this->cursos.find(codigo);
        if(it != this->cursos.end())
        {
            cout << "ERRO CURSO REPETIDO" << endl;
            exit(1);
        }
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

	void Sistema::geraPADESalva() {
        ocstream out = ocstream("1-pad.csv");
        out.escreve(vector<string> {"Docente", "Departamento", "Horas Semanais Aula", "Horas Semestrais Aula",
                                    "Horas Semanais Orientação", "Produções Qualificadas",
                                    "Produções Não Qualificadas"});
    	vector<Docente> docentes;
		for(auto it = this->docentes.cbegin(); it != this->docentes.cend(); ++it)
		{
			docentes.push_back(*(it->second));
		}
		sort(docentes.begin(), docentes.end());
		for(auto d : docentes) {
			out.escreve(d.getCSVData());
		}
    }

    struct outputData {
        vector<string> data;
    };

    bool compareData(const outputData &a, const outputData &b)
    {
        if(a.data[0] == b.data[0]) {
            if(a.data[1] == b.data[1]) {
                return cpp_util::stringCompare(a.data[3], b.data[3]);
            }
            else {
                return cpp_util::stringCompare(a.data[1], b.data[1]);
            }
        } else {
            return cpp_util::stringCompare(a.data[0], b.data[0]);
        }
    }

    void Sistema::geraRHAESalva() {
        ocstream out = ocstream("2-rha.csv");
        out.escreve(vector<string> {"Departamento", "Docente", "Cód. Curso", "Curso", "Horas Semestrais Aula"});
        vector<outputData> data;
        for(auto it = this->cursos.cbegin(); it != this->cursos.cend(); ++it)
        {
            Curso* c = it->second;
            map<Docente*, int>* horasDoc = c->getMap();
            for(auto it2 = horasDoc->cbegin(); it2 != horasDoc->cend(); ++it2) {
                vector<string> v = {
                        it2->first->getDepartamento(),
                        it2->first->getNome(),
                        std::to_string(c->getCodigo()),
                        c->getNome(),
                        std::to_string(it2->second)
                };
                outputData d;
                d.data = v;
                data.push_back(d);
            }
        }

        std::sort(data.begin(), data.end(), compareData);

        for(auto elem : data) {
            out.escreve(elem.data);
        }

    }

    void Sistema::geraAlocacaoESalva() {
        ocstream out = ocstream("3-alocacao.csv");
        out.escreve(vector<string> {"Docente", "Código", "Nome", "Carga Horária Semestral"});
        vector<Disciplina> disciplinas;
        for(auto elem : this->atividades) {
            Disciplina* cDisc = dynamic_cast<Disciplina*>(elem);
            if(cDisc) {
                disciplinas.push_back(*cDisc);
            }
        }
        sort(disciplinas.begin(), disciplinas.end());
        for(auto d : disciplinas) {
            out.escreve(d.getCSVData());
        }
    }
    void Sistema::geraPPGESalva() {
        ocstream out = ocstream("4-ppg.csv");
        out.escreve(vector<string> {"Nome do Programa", "Data de Ingresso", "Matrícula", "Nome"});
        vector<OrientaPos> orientacoes;
        for(auto elem : this->atividades) {
            OrientaPos* oPos = dynamic_cast<OrientaPos*>(elem);
            if(oPos) {
                orientacoes.push_back(*oPos);
            }
        }
        sort(orientacoes.begin(), orientacoes.end());
        for(auto o : orientacoes) {
            out.escreve(o.getCSVData());
        }
    }


}
