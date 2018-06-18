#ifndef TRABALHO_PROG3_DOCENTE_H
#define TRABALHO_PROG3_DOCENTE_H

#include <string>
#include <iostream>

using namespace std;

class Docente {
private:
    int codigo;
    string nome;
    string departamento;
public:
    Docente(int = 0, string = "", string = "");
    ~Docente();
    void print();
    string to_string();
    friend ostream& operator<<(ostream& os, const Docente& doc);
    friend ostream& operator<<(ostream& os, const Docente* doc);
};


#endif //TRABALHO_PROG3_DOCENTE_H