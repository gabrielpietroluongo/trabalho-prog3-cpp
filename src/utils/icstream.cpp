//
//  isvstream.cpp
//  prog3
//
//  Created by Gabriel Pietroluongo on 27/06/2018.
//  Copyright © 2018 Gabriel Pietroluongo. All rights reserved.
//

#include "icstream.h"
/**
     *****************************************************************************************
     *  @brief      Construtor da classe
     *
     *  @param      string Arquivo de entrada
     *
     ****************************************************************************************/
icstream::icstream(string inputFile) {
    this->inputStream = new ifstream(inputFile);
    string d;
    vector<string> dv;
    std::getline(*(this->inputStream), d);
    while(std::getline(*(this->inputStream), d)) {
    	cpp_util::Tokenizer* tok = new cpp_util::Tokenizer(d, ';');
    	this->data.push_back(tok->remaining());
    	delete tok;
    }
}

icstream::~icstream() {
    delete this->inputStream;
}
/**
     *****************************************************************************************
     *  @brief      Retorna os dados lidos do arquivo csv
     *
     *  @returns    vector< vector <string> > Lista de vetores de strings com as informaçoes do csv lido
     *
     ****************************************************************************************/
vector<vector<string>> icstream::getData() {
	return this->data;
}
