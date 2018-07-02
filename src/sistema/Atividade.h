#ifndef TRABALHO_PROG3_ATIVIDADE_H
#define TRABALHO_PROG3_ATIVIDADE_H

#include <iostream>
#include <string>
#include "Docente.h"

namespace prog3 {

    //Forward declaration
    class Docente;
     /**
     *****************************************************************************************
     *  @brief      Classe de domínio Atividade
     *
     *  @param      Docente& docente relacionado à atividade
     *  @param      int Carga Horária Semanal relacionada à atividade
     *
     ****************************************************************************************/
    class Atividade {
    private:
        int cargaSemanal;
    protected:
        Docente* docente;                   ///< Docente responsavel pela atividade
    public:
        Atividade(Docente&, int = 0);
        virtual ~Atividade();
    };
}

#endif //TRABALHO_PROG3_ATIVIDADE_H
