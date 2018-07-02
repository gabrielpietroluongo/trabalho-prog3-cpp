//
// Created by gabriel on 18/06/18.
//

#include "Producao.h"

namespace prog3 {
/**
   *****************************************************************************************
   *  @brief      Construtor da classe
   *
   *  @params Docente& Docente responsavel pela produçao
   *  @params string Titulo da publicaçao
   *  @params bool É qualificada?
   *
   ****************************************************************************************/
    Producao::Producao(Docente& d, string t, bool q) {
        this->titulo = t;
        this->docente = &d;
        this->qualificada = q;
        d.adicionaProducao(*this);
    }

    bool Producao::isQualificada() {
        return this->qualificada;
    }

    Producao::~Producao() {

    }
}