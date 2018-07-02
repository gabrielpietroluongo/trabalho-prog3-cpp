#ifndef TRABALHO_PROG3_DOCENTE_H
#define TRABALHO_PROG3_DOCENTE_H

#include <string>
#include <iostream>
#include <vector>

#include "../utils/cpp_utils/StringUtils.h"

using namespace std;

namespace prog3 {

    //Forward declaration
    class Producao;
    class Atividade;
    /**
    *****************************************************************************************
    *  @brief      Classe de dominio Docente
    *
    *  @param      int Codigo do docente
    *  @param      string Nome do docente
    *  @param      string Departamento do docente
    *
    ****************************************************************************************/
    class Docente {
    private:
        int codigo;
        string nome;
        string departamento;
        vector<Producao*> producoes;
        vector<Atividade*> atividades;
        int horasAulaSemanais;
        int horasAulaSemestrais;
        int horasOrientacaoSemanais;

    public:
        Docente(int = 0, string = "", string = "");

        ~Docente();

        void print();

        string to_string();

        string getNome();

        string getDepartamento() { return this->departamento; }

        void adicionaProducao(Producao&);

        void adicionaAtividade(Atividade&);

        void adicionaHorasAulaSemanais(int val);

        void adicionaHorasAulaSemestrais(int val);

        void adicionaHorasOrientacao(int val);

        vector<string> getCSVData();

        // Operator overloads
        friend ostream &operator<<(ostream &os, const Docente &doc);

        friend ostream &operator<<(ostream &os, const Docente *doc);

        friend bool operator<(Docente const& a, Docente const& b);

    };

}
#endif //TRABALHO_PROG3_DOCENTE_H