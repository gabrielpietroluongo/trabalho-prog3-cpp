//
// Created by gabriel on 19/06/18.
//

#ifndef TRABALHO_PROG3_ARGPARSE_H
#define TRABALHO_PROG3_ARGPARSE_H

#include <string>
#include <iostream>
#include <map>

using namespace std;

class ArgParse {
private:
    map<string, string> args;
public:
    ArgParse();
    ~ArgParse();
    void parse(int argc, char** argv);
    map<string, string> getArgs();
};


#endif //TRABALHO_PROG3_ARGPARSE_H
