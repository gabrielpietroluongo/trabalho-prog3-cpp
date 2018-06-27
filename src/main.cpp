#include <iostream>

#include "Sistema.h"
#include "ArgParse.h"


int main(int argc, char* argv[]) {
    ArgParse parser = ArgParse();
    parser.parse(argc, argv);
    prog3::Sistema s = prog3::Sistema(parser.getArgs());
    std::cout << "Sucesso!" << std::endl;
    prog3::Docente* d = new prog3::Docente();
    return 0;
}
