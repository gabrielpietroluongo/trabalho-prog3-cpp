//
// Created by gabriel on 02/07/18.
//

#include "ClassInconsistencyException.h"

ClassInconsistencyException::ClassInconsistencyException(const string& codigo, const string& nome) {
    this->msg_ = "Inconsistência ao definir o nível do curso: " + codigo + " - " + nome + ".";
}