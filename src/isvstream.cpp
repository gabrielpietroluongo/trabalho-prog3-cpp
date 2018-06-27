//
//  isvstream.cpp
//  prog3
//
//  Created by Gabriel Pietroluongo on 27/06/2018.
//  Copyright © 2018 Gabriel Pietroluongo. All rights reserved.
//

#include "isvstream.h"

icstream::icstream(string inputFile) {
    this->inputStream = new ifstream(inputFile);
}

icstream::~icstream() {
    delete this->inputStream;
}
