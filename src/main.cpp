/**
@mainpage

Trabalho de Programaçao 3

@author Gabriel Pietroluongo e Otavio Cozer
@date 02/07/2018
@file main.cpp
*/
#include <iostream>
#include <locale>

#include "sistema/Sistema.h"
#include "utils/ArgParse.h"

/**
   *****************************************************************************************
   *  @brief      Classe principal do programa
   *
   *  @params int numero de argumentos
   *  @params char* lista de argumentos
   *
   ****************************************************************************************/
int main(int argc, char* argv[]) {
    try {
        setlocale(LC_ALL, "Portuguese");
        locale::global(locale("pt_BR.UTF8"));
        ArgParse parser = ArgParse();
        parser.parse(argc, argv);
        prog3::Sistema s = prog3::Sistema(parser.getArgs());
        s.geraPADESalva();
        s.geraRHAESalva();
        s.geraAlocacaoESalva();
        s.geraPPGESalva();
        std::cout << "Sucesso!" << std::endl;
        return 0;
    }
    catch(string s) {
        cerr << s << endl;
    }
    catch(std::exception& e) {
        cerr << e.what() << endl;
    }
    catch(...) {
        cerr << "Erro desconhecido." << endl;
    }
}
