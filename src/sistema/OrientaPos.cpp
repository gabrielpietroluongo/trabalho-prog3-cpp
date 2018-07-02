//
// Created by gabriel on 19/06/18.
//

#include "OrientaPos.h"
#include "../exceptions/InvalidDateException.h"

namespace prog3 {
/**
   *****************************************************************************************
   *  @brief      Construtor da classe
   *
   *  @params Docente& Docente responsavel pela orientaçao
   *  @params int Carga Semanal da orientaçao
   *  @params Discente& Discente orientado
   *  @params string Data de ingresso do discente no programa (no formato DD/MM/AAAA)
   *  @params string Programa de orientaçao do discente
   *
   ****************************************************************************************/
    OrientaPos::OrientaPos(Docente& docente, int cargaSemanal, Discente& discente, string dataIngresso,
                           string programa) : Orientacao(docente, cargaSemanal, discente) {
        this->programa = programa;
        time_t now = time(NULL);
        this->dataIngresso = cpp_util::parseDate(dataIngresso, cpp_util::DATE_FORMAT_PT_BR_SHORT);
        double diff = difftime(now, this->dataIngresso);
        if (diff < 0) {
            throw InvalidDateException(discente.getNome(), dataIngresso);
        }
    }

/**
    *****************************************************************************************
    *  @brief      Retorna os dados formatados em CSV para escrita na saida
    *
    *  @returns    vector<string> lista de strings para escrita
    *
    ****************************************************************************************/
    vector<string> OrientaPos::getCSVData() {
        vector<string> vec = {
            this->programa,
            cpp_util::formatDate(this->dataIngresso, cpp_util::DATE_FORMAT_PT_BR_SHORT),
            std::to_string(this->discente->getMatricula()),
            this->discente->getNome()
        };
        return vec;
    }


    OrientaPos::~OrientaPos() {

    }

    bool operator<(OrientaPos const& a, OrientaPos const& b) {
        if(a.programa == b.programa) {
            double diff = std::difftime(a.dataIngresso, b.dataIngresso);
            if(diff != 0) {
                if(diff < 0)
                    return true;
                else
                    return false;

            } else {
                return cpp_util::stringCompare(a.docente->getNome(), b.docente->getNome());
            }
        } else {
            return cpp_util::stringCompare(a.programa, b.programa);
        }
    }
}
