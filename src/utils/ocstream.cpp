//
//  osvstream.cpp
//  prog3
//
//  Created by Gabriel Pietroluongo on 27/06/2018.
//  Copyright © 2018 Gabriel Pietroluongo. All rights reserved.
//

#include "ocstream.h"

ocstream::ocstream(string outputFile) {
    this->outputStream = new ofstream(outputFile);

    }

void ocstream::escrever(vector<string> data){
	int tam = data.size();
	for(int i=0; i<tam; i++){

	}

}

ocstream::~ocstream() {
    delete this->outputStream;
}


