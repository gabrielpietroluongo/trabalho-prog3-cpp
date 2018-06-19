#ifndef TRABALHO_PROG3_DOCENTE_H
#define TRABALHO_PROG3_DOCENTE_H

#include <string>
#include <iostream>
#include <vector>
#include "Sistema.h"

using namespace std;

namespace prog3 {

    //Forward declaration
    class Producao;

    class Docente {
    private:
        int codigo;
        string nome;
        string departamento;
        vector<Producao*> producoes;
    public:
        Docente(int = 0, string = "", string = "");

        ~Docente();

        void print();

        string to_string();

        void adicionaProducao(Producao& p);

        // Operator overloads
        friend ostream &operator<<(ostream &os, const Docente &doc);

        friend ostream &operator<<(ostream &os, const Docente *doc);
    };

}
#endif //TRABALHO_PROG3_DOCENTE_H