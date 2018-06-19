//
// Created by gabriel on 19/06/18.
//

#include "ArgParse.h"

ArgParse::ArgParse() {

}
ArgParse::~ArgParse() {

}

/*
 * string fname_docente;        d
    string fname_discente;      a
    string fname_producao;      p
    string fname_curso;         c
    string fname_disciplina;    r
    string fname_ograd;         og
    string fname_opos;          op
 */
void ArgParse::parse(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        string arg = argv[i];
        i++;
        string fname = argv[i];
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
        }
    }
}
void ArgParse::debug() {
    cout << this->fname_docente << endl;
    cout << this->fname_discente << endl;
    cout << this->fname_producao << endl;
    cout << this->fname_curso << endl;
    cout << this->fname_disciplina << endl;
    cout << this->fname_ograd << endl;
    cout << this->fname_opos << endl;

}