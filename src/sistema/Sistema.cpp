//
// Created by gabriel on 18/06/18.
//

#include <algorithm>
#include "Sistema.h"
#include "../utils/ocstream.h"
#include "../exceptions/ClassInconsistencyException.h"
#include "../exceptions/RepeatedCodeException.h"

namespace prog3 {
/**
   *****************************************************************************************
   *  @brief      Construtor da classe
   *
   *  @param     map<string, string>       Mapa de argumentos para carregamento de arquivos
   *
   *
   ****************************************************************************************/
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
    		    throw ClassInconsistencyException(elem[0], elem[1]);
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
    /**
   *****************************************************************************************
   *  @brief      Adiciona docente ao mapa de docentes do sistema.
   *
   *  Cria um docente e o insere no mapa de docentes.
   *
   *
   *  @param int       Codigo do docente a ser adicionado
   *  @param string    Nome do docente a ser adicionado
   *  @param string    Departamento do docente a ser adicionado
   *
   *
   ****************************************************************************************/
    void Sistema::adicionaDocente(int codigo, string nome, string departamento) {
        Docente *d = new Docente(codigo, nome, departamento);
        if(this->docentes.count(codigo) != 0)
            throw RepeatedCodeException(RepeatedCodeException::Tipo::DOCENTE, to_string(codigo));
        this->docentes.insert(pair<int, Docente*>(codigo, d));
    }
/**
   *****************************************************************************************
   *  @brief      Adiciona discente ao mapa de discentes do sistema.
   *
   *  Cria um discente e o insere no mapa de discente.
   *
   *
   *  @param long      Matricula do discente a ser adicionado
   *  @param string    Nome do docente a ser adicionado
   *  @param int       Codigo do curso do discente a ser adicionado
   *
   *
   ****************************************************************************************/
    void Sistema::adicionaDiscente(long matricula, string nome, int codigoCurso) {
        Discente* d = new Discente(nome, matricula, this->cursos[codigoCurso]);
        if(this->discentes.count(matricula) != 0)
            throw RepeatedCodeException(RepeatedCodeException::Tipo::DISCENTE, to_string(matricula));
        this->discentes.insert(pair<long, Discente*>(matricula, d));
    }

    /**
   *****************************************************************************************
   *  @brief      Adiciona producao a lista de producoes do sistema.
   *
   *  Cria uma producao e a insere na lista de docentes.
   *
   *
   *  @param int       Codigo do docente responsavel
   *  @param string    Titulo da produçao
   *  @param bool      É produçao qualificada?
   *
   *
   ****************************************************************************************/
    void Sistema::adicionaProducao(int codigo, string titulo, bool qualificada) {
        if(this->docentes.count(codigo) == 0) {
            throw InvalidCodeException(InvalidCodeException::Tipo::DOCENTE_PUBLICACAO, to_string(codigo),
                                       titulo);
        }
        Producao* p = new Producao(*this->docentes[codigo], titulo, qualificada);
        this->producoes.push_back(p);
    }
    /**
   *****************************************************************************************
   *  @brief      Adiciona producao a lista de producoes do sistema.
   *
   *  Cria uma producao e a insere na lista de docentes.
   *
   *
   *  @param int       Codigo do docente responsavel
   *  @param string    Titulo da produçao
   *  @param bool      É produçao qualificada?
   *
   *
   ****************************************************************************************/
    void Sistema::adicionaCurso(int codigo, string nome, bool grad) {
        Curso* c = new Curso(nome, codigo, grad);
        if(this->cursos.count(codigo) != 0)
            throw RepeatedCodeException(RepeatedCodeException::Tipo::CURSO, to_string(codigo));
        this->cursos.insert(pair<int, Curso*>(codigo, c));
    }
    /**
   *****************************************************************************************
   *  @brief      Adiciona disciplina a lista de atividades do sistema.
   *
   *  Cria uma disciplina e a insere na lista de atividades.
   *
   *
   *  @param string    Codigo da materia
   *  @param string    Nome da materia
   *  @param int       Codigo do docente responsavel pela materia
   *  @param int       Carga horaria semanal da materia
   *  @param int       Carga horaria semestral da materia
   *  @param int       Codigo do curso relacionado a materia
   *
   *
   ****************************************************************************************/
    void Sistema::adicionaDisciplina(string codigoMateria, string nome, int codigoDocente, int cargaSemanal,
                            int cargaSemestral, int codigoCurso) {
        if(this->docentes.count(codigoDocente) == 0) {
            throw InvalidCodeException(InvalidCodeException::Tipo::DOCENTE_DISCIPLINA, to_string(codigoDocente), nome);
        }

        if(this->cursos.count(codigoCurso) == 0) {
            throw InvalidCodeException(InvalidCodeException::Tipo::CURSO_DISCIPLINA, to_string(codigoCurso),
                                       nome);
        }

        Disciplina* d = new Disciplina(codigoMateria, nome, *this->docentes[codigoDocente], cargaSemanal,
                                       cargaSemestral, *this->cursos[codigoCurso]);
        for(auto elem : this->atividades) {
            Disciplina* cDisc = dynamic_cast<Disciplina*>(elem);
            if(cDisc) {
                if(cDisc->getCodigo() == codigoMateria) {
                    throw RepeatedCodeException(RepeatedCodeException::Tipo::DISCIPLINA, codigoMateria);
                }
            }
        }
        this->atividades.push_back(d);
    }
    /**
   *****************************************************************************************
   *  @brief      Adiciona Orientaçao de graduaçao a lista de atividades do sistema.
   *
   *  Cria uma Orientaçao de Graduaçao e a insere na lista de atividades.
   *
   *
   *  @param int       Codigo do docente responsavel pela materia
   *  @param long      Matricula do discente
   *  @param int       Codigo do curso do discente
   *  @param int       Carga horaria semanal da orientaçao
   *
   *
   ****************************************************************************************/
    void Sistema::adicionaOrientacaoGrad(int codigoDocente, long matriculaDiscente, int codigoCurso, int cargaSemanal) {
        if(this->docentes.count(codigoDocente) == 0) {
            throw InvalidCodeException(InvalidCodeException::Tipo::DOCENTE_ORIENTACAO, to_string(codigoDocente),
            this->discentes[matriculaDiscente]->getNome());
        }

        if(this->cursos.count(codigoCurso) == 0) {
            throw InvalidCodeException(InvalidCodeException::Tipo::CURSO_ORIENTACAO, to_string(codigoCurso),
                                       this->discentes[matriculaDiscente]->getNome());
        }

        OrientaGrad* o = new OrientaGrad(*this->docentes[codigoDocente], *this->discentes[matriculaDiscente],
                                         *this->cursos[codigoCurso], cargaSemanal);
        this->atividades.push_back(o);
    }
/**
   *****************************************************************************************
   *  @brief      Adiciona Orientaçao de pos graduaçao a lista de atividades do sistema.
   *
   *  Cria uma Orientaçao de Pos Graduaçao e a insere na lista de atividades.
   *
   *
   *  @param int       Codigo do docente responsavel pela materia
   *  @param long      Matricula do discente
   *  @param string    Data de ingresso do discente no programa (no formato DD/MM/AAAA)
   *  @param string    Programa de orientaçao
   *  @param int       Carga horaria semanal da orientaçao
   *
   *
   ****************************************************************************************/
    void Sistema::adicionaOrientacaoPos(int codigoDocente, long matriculaDiscente, string dataIngresso,
                               string programa, int cargaSemanal) {
        if(this->docentes.count(codigoDocente) == 0) {
            throw InvalidCodeException(InvalidCodeException::Tipo::DOCENTE_ORIENTACAO, to_string(codigoDocente),
                                       this->discentes[matriculaDiscente]->getNome());
        }

        OrientaPos* o = new OrientaPos(*this->docentes[codigoDocente], cargaSemanal, *this->discentes[matriculaDiscente],
                                       dataIngresso, programa);
        this->atividades.push_back(o);
    }

    /**
   *****************************************************************************************
   *  @brief      Gera o arquivo de saida 1, o PAD
   *
   *  Analisa os dados do sistema e gera o arquivo de saida.
   *
   *
   ****************************************************************************************/
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
    /**
    *****************************************************************************************
    *  @brief      Struct auxiliar para geraçao do Relatorio de Horas-Aula
    *
    *  Struct que auxilia na organizaçao e ordenaçao do segundo arquivo de saida
    *
    *
    ****************************************************************************************/
    struct outputData {
        vector<string> data;
    };

    // Funçao auxiliar para ordenaçao de vetores de outputData s
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
    /**
   *****************************************************************************************
   *  @brief      Gera o arquivo de saida 2, o RHA
   *
   *  Analisa os dados do sistema e gera o arquivo de saida.
   *
   *
   ****************************************************************************************/
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
    /**
    *****************************************************************************************
    *  @brief      Gera o arquivo de saida 3, o relatorio de Alocaçao
    *
    *  Analisa os dados do sistema e gera o arquivo de saida.
    *
    *
    ****************************************************************************************/
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
    /**
    *****************************************************************************************
    *  @brief      Gera o arquivo de saida 1, o relatorio de PPG
    *
    *  Analisa os dados do sistema e gera o arquivo de saida.
    *
    *
    ****************************************************************************************/
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
