//
// Created by gabriel on 02/07/18.
//

#include "InvalidDateException.h"

InvalidDateException::InvalidDateException(const string& nome, const string& data) {
    this->msg_ = "Data de ingresso do aluno \"" + nome + "\" está no futuro: " + data + ".";
}
