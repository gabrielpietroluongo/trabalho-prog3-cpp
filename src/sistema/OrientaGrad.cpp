//
// Created by gabriel on 19/06/18.
//

#include "OrientaGrad.h"
namespace prog3 {
    /**
   *****************************************************************************************
   *  @brief      Construtor da classe
   *
   *  @params Docente& Docente responsavel pela orientaçao
   *  @params Discente& Discente orientado
   *  @params Curso& Curso do discente
   *  @params int Carga Semanal da orientaçao
   *
   ****************************************************************************************/
    OrientaGrad::OrientaGrad(Docente& docente, Discente& discente,
                             Curso& curso, int cargaSemanal) : Orientacao(docente, cargaSemanal, discente) {
        this->curso = &curso;
        this->curso->adicionaOrientaGrad(*this);
    }

    OrientaGrad::~OrientaGrad() {

    }
}