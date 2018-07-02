//
// Created by gabriel on 02/07/18.
//

#include "InvalidDateException.h"
/**
*****************************************************************************************
*  @brief     Construtor da classe
*
*
*  @param      const string&         Nome do discente
*  @param     const string&         Data invalida
*
****************************************************************************************/
InvalidDateException::InvalidDateException(const string& nome, const string& data) {
    this->msg_ = "Data de ingresso do aluno \"" + nome + "\" está no futuro: " + data + ".";
}
