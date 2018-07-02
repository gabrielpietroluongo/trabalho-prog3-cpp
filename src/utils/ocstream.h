//
//  osvstream.hpp
//  prog3
//
//  Created by Gabriel Pietroluongo on 27/06/2018.
//  Copyright © 2018 Gabriel Pietroluongo. All rights reserved.
//

#ifndef osvstream_hpp
#define osvstream_hpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
     *****************************************************************************************
     *  @brief      Classe de escrita de arquivos csv
     *
     *  @param      string Arquivo de saida
     *
     ****************************************************************************************/
class ocstream {
private:
    ofstream* outputStream;

public:
    ocstream(string outputFile);
    ~ocstream();

    void escreve(vector<string> data);
};

#endif /* osvstream_hpp */
