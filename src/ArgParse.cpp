//
// Created by gabriel on 19/06/18.
//

#include "ArgParse.h"

using namespace std;

ArgParse::ArgParse() {

}
ArgParse::~ArgParse() {

}

void ArgParse::parse(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        string arg = argv[i];
        i++;
        string fname = argv[i];
        this->args.insert(pair<string, string>(arg, fname));
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

map<string, string> ArgParse::getArgs() {
    return this->args;
}