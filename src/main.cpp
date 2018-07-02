#include <iostream>
#include <locale>

#include "sistema/Sistema.h"
#include "utils/ArgParse.h"


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
