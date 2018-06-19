//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ARGPARSE_H
#define TRABALHO_PROG3_ARGPARSE_H

#include <string>
#include <iostream>

using namespace std;

class ArgParse {
public:
    string fname_docente;
    string fname_discente;
    string fname_producao;
    string fname_curso;
    string fname_disciplina;
    string fname_ograd;
    string fname_opos;
public:
    ArgParse();
    ~ArgParse();
    void parse(int argc, char** argv);
    void debug();
};


#endif //TRABALHO_PROG3_ARGPARSE_H
