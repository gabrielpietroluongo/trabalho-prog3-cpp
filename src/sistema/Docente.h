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

    class Docente {
    private:
        int codigo;
        string nome;
        string departamento;
        vector<Producao*> producoes;
        vector<Atividade*> atividades;

    public:
        Docente(int = 0, string = "", string = "");

        ~Docente();

        void print();

        string to_string();

        void adicionaProducao(Producao&);

        void adicionaAtividade(Atividade&);

        // Operator overloads
        friend ostream &operator<<(ostream &os, const Docente &doc);

        friend ostream &operator<<(ostream &os, const Docente *doc);

        friend bool operator<(Docente const& a, Docente const& b);

    };

}
#endif //TRABALHO_PROG3_DOCENTE_H