//
//  osvstream.cpp
//  prog3
//
//  Created by Gabriel Pietroluongo on 27/06/2018.
//  Copyright © 2018 Gabriel Pietroluongo. All rights reserved.
//

#include "ocstream.h"
/**
     *****************************************************************************************
     *  @brief      Construtor da classe
     *
     *  @param      string Arquivo de saida
     *
     ****************************************************************************************/
ocstream::ocstream(string outputFile) {
    this->outputStream = new ofstream(outputFile);

    }

/**
 *****************************************************************************************
 *  @brief      Escreve dados de csv no arquivo de saida
 *
 *  @param      vector<string> dados a serem escritos
 *
 ****************************************************************************************/
void ocstream::escreve(vector<string> data){
    int i = 0;
    for(auto elem : data){
        i++;
        *(this->outputStream) << elem;
        if(i != data.size())
            *(this->outputStream) << ";";
	}
    *(this->outputStream) << "\n";
}

ocstream::~ocstream() {
    delete this->outputStream;
}


