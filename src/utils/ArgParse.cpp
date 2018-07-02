//
// Created by gabriel on 19/06/18.
//

#include "ArgParse.h"

using namespace std;

ArgParse::ArgParse() {

}
ArgParse::~ArgParse() {

}
/**
     *****************************************************************************************
     *  @brief      Construtor da classe
     *
     *  @param      int argc numero de argumentos
     *  @param      char** argv vetor de argumentos
     *
     ****************************************************************************************/
void ArgParse::parse(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        string arg = argv[i];
        i++;
        string fname = argv[i];
	this->args[arg] = fname;
    }
}
/**
     *****************************************************************************************
     *  @brief      Retorna a lista de argumentos
     *
     *  @return     map<string, string> Com os argumentos do programa
     *
     ****************************************************************************************/
map<string, string> ArgParse::getArgs() {
    return this->args;
}
