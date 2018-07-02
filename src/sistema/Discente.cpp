//
// Created by gabriel on 18/06/18.
//

#include "Discente.h"

namespace prog3 {
    /**
     *****************************************************************************************
     *  @brief      Construtor da classe
     *
     *  @param      string Nome do discente
     *  @param      long Matrícula do discente
     *  @param      Curso* Curso do discente
     *
     ****************************************************************************************/
    Discente::Discente(string n, long m, Curso* c) {
        this->nome = n;
        this->matricula = m;
        this->curso = c;
        c->adicionaDiscente(*this);
    }

    Discente::~Discente() {

    }

    void Discente::adicionaOrientacao(Orientacao& o) {
        this->orientacoes.push_back(&o);
    }

    ostream &operator<<(ostream &os, const Discente &dis) {
        os << "Nome: " << dis.nome << "\nMatricula: " << dis.matricula << "\nCurso: " << dis.curso->getCodigo() << "\nOrientacoes: ";
        for(auto o : dis.orientacoes)
        {
            std::cout << "\n" << o;
        }
        return os;
    }

    ostream &operator<<(ostream &os, const Discente* dis) {
        os << "Nome: " << dis->nome << "\nMatricula: " << dis->matricula << "\nCurso: " << dis->curso->getCodigo() << "\n Orientacoes: ";
        for(auto o : dis->orientacoes)
        {
            std::cout << "\n" << o;
        }
        return os;
    }
}