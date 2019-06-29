//
// Created by refre on 21.06.2019.
//

#ifndef UNTITLED5_OPZ_H
#define UNTITLED5_OPZ_H

#include <iostream>
#include <stack>
#include <string.h>
#include <cstdlib>

class Parser {
    char *part;
    unsigned int size = 0;
public:
    void toPart(std::string equation);

    char *getPartition();

    unsigned int getSize();
};

class Calculator {
    float result;
public:
    float Calculated(Parser part);
};

class Polska {
    float result;
public:
    Polska(std::string equation);

    float getResult();
};


#endif //UNTITLED5_OPZ_H
