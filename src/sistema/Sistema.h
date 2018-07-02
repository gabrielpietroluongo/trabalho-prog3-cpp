//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_SISTEMA_H
#define TRABALHO_PROG3_SISTEMA_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "../utils/cpp_utils/StringUtils.h"

//Includes do sistema
#include "Docente.h"
#include "Curso.h"
#include "Producao.h"
#include "Discente.h"
#include "Atividade.h"
#include "Disciplina.h"
#include "Orientacao.h"
#include "OrientaGrad.h"
#include "OrientaPos.h"


#include "../utils/icstream.h"

using namespace std;

namespace prog3 {

    class Sistema {
    private:
        map<int, Docente*> docentes;
        vector<Producao*> producoes;
        map<int, Curso*> cursos;
        map<long, Discente*> discentes;
        vector<Atividade*> atividades;
    public:
        Sistema(map<string, string> args);
        ~Sistema();
        void WIP_carrega_dados(map<string*, string*> args);
        void WIP_Debug();
        void adicionaDocente(int codigo, string nome, string departamento);
        void adicionaDiscente(long matricula, string nome, int codigoCurso);
        void adicionaProducao(int codigo, string titulo, bool qualificada);
        void adicionaCurso(int codigo, string nome, bool grad);
        void adicionaDisciplina(string codigoMateria, string nome, int codigoDocente, int cargaSemanal,
                                int cargaSemestral, int codigoCurso);
        void adicionaOrientacaoGrad(int codigoDocente, long matriculaDiscente, int codigoCurso, int cargaSemanal);
        void adicionaOrientacaoPos(int codigoDocente, long matriculaDiscente, string dataIngresso,
                                   string programa, int cargaSemanal);
        void geraPADESalva();
        void geraRHAESalva();
        void geraAlocacaoESalva();
        void geraPPGESalva();
    };

}

#endif //TRABALHO_PROG3_SISTEMA_H
