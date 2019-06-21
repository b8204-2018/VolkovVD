//
// Created by refre on 21.06.2019.
//

#ifndef UNTITLED5_OPZ_H
#define UNTITLED5_OPZ_H

#include <iostream>
#include <stack>
#include <string.h>
#include <cstdlib>

using namespace std

class Parser {
    char *part;
    unsigned int size = 0;
public:
    void toPart(string equation);
    char *getPartition();
    unsigned int getSize();
};

class Calculator {
    int result;
public:
    int Calculated(Parser part);
};

class Polska {
    int result;
public:
    Polska(string equation);
    int getResult();
};


#endif //UNTITLED5_OPZ_H
