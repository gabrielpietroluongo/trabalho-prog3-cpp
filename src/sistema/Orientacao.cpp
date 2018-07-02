//
// Created by gabriel on 19/06/18.
//

#include "Orientacao.h"

namespace prog3 {
    /**
    *****************************************************************************************
    *  @brief      Construtor da classe
    *
    *  @params Docente& Docente responsavel pela orientaçao
    *  @params int Carga Semanal da orientaçao
    *  @params Discente& Discente orientado
    *
    ****************************************************************************************/
    Orientacao::Orientacao(Docente& docente, int cargaSemanal, Discente& discente) : Atividade(docente, cargaSemanal) {
        this->discente = &discente;
        this->discente->adicionaOrientacao(*this);
        this->docente->adicionaHorasOrientacao(cargaSemanal);
    }
    Orientacao::~Orientacao() {

    }
}