//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ARGPARSE_H
#define TRABALHO_PROG3_ARGPARSE_H

#include <string>
#include <iostream>
#include <map>

using namespace std;
/**
 *****************************************************************************************
 *  @brief      Classe de utilidades ArgParse
 *
 *  @usage      Utilizada para parsing de argumentos do programa
 *
 *  @param      int argc numero de argumentos
 *  @param      char** argv vetor de argumentos
 *
 ****************************************************************************************/
class ArgParse {
private:
    map<string, string> args;
public:
    ArgParse();
    ~ArgParse();
    void parse(int argc, char** argv);
    map<string, string> getArgs();
};


#endif //TRABALHO_PROG3_ARGPARSE_H
