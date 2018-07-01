//
//  isvstream.cpp
//  prog3
//
//  Created by Gabriel Pietroluongo on 27/06/2018.
//  Copyright © 2018 Gabriel Pietroluongo. All rights reserved.
//

#include "icstream.h"

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

vector<vector<string>> icstream::getData() {
	return this->data;
}
