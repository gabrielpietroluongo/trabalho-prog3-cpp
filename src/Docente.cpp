#include "Docente.h"

Docente::Docente(int c, string n, string d) {
    this->codigo = c;
    this->nome = n;
    this->departamento = d;
}

Docente::~Docente() {

}

void Docente::print() {
    cout << "Nome: " << this->nome << "\nCodigo: " << this->codigo << "\nDepartamento: " << this->departamento;
}

string Docente::to_string() {
    string ret="";
    ret.append("Nome: ");
    ret.append(this->nome);
    ret.append("\nCodigo: ");
    ret.append(std::to_string(this->codigo));
    ret.append("\nDepartamento: ");
    ret.append(this->departamento);
    return ret;
}

ostream& operator<<(ostream& os, const Docente& doc) {
    os<< "Nome: " << doc.nome << "\nCodigo: " << doc.codigo << "\nDepartamento: " << doc.departamento;

}
ostream& operator<<(ostream& os, const Docente* doc) {
    cout << "Nome: " << doc->nome << "\nCodigo: " << doc->codigo << "\nDepartamento: " << doc->departamento;
}