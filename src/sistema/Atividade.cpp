#include "Atividade.h"

namespace prog3 {

	/**
     *****************************************************************************************
     *  @brief      Construtor da classe
     *
     *  @param      docente relacionado à atividade
     *  @param      int Carga Horária Semanal relacionada à atividade
     *
     ****************************************************************************************/
    Atividade::Atividade(Docente& d, int c) {
        this->docente = &d;
        this->cargaSemanal = c;
        d.adicionaAtividade(*this);
    }

    Atividade::~Atividade() {

    }
}
