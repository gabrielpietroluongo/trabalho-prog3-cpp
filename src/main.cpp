#include <iostream>
#include <locale>

#include "sistema/Sistema.h"
#include "utils/ArgParse.h"


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Portuguese");
    locale::global(locale("pt_BR.UTF8"));
    ArgParse parser = ArgParse();
    parser.parse(argc, argv);
    prog3::Sistema s = prog3::Sistema(parser.getArgs());
    s.geraPADESalva();
    s.geraRHAESalva();
    s.geraAlocacaoESalva();
    s.geraPPGESalva();
    //s.WIP_Debug();
    std::cout << "Sucesso!" << std::endl;
    //prog3::Docente* d = new prog3::Docente();
    return 0;
}
