//
// Created by gabriel on 19/06/18.
//

#include "ArgParse.h"

using namespace std;

ArgParse::ArgParse() {

}
ArgParse::~ArgParse() {

}

void ArgParse::parse(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        string arg = argv[i];
        i++;
        string fname = argv[i];
	this->args[arg] = fname;
    }
}

map<string, string> ArgParse::getArgs() {
    return this->args;
}
