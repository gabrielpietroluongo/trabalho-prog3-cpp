//
//  isvstream.hpp
//  prog3
//
//  Created by Gabriel Pietroluongo on 27/06/2018.
//  Copyright © 2018 Gabriel Pietroluongo. All rights reserved.
//

#ifndef isvstream_hpp
#define isvstream_hpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class icstream {
private:
    ifstream* inputStream;
    
    vector<vector<string>> data;
public:
    icstream(string inputFile);
    ~icstream();
};

#endif /* isvstream_hpp */
