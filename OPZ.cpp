#include <iostream>
#include <stack>
#include <string.h>
#include <cstdlib>
#include "OPZ.h"

using namespace std;

const int OPENBRACKET = 40, CLOSEBRACKET = 41, MUL = 42, ADD = 43, DIV = 47, SUB = 45;

void Parser::toPart(string equation) {
    if (equation.length() < 3) {
        throw logic_error("Empty");
    }
    size_t open = 0, close = 0;
    for (size_t i = 0; i < equation.length(); i++) {
        if (equation[i] == OPENBRACKET) {
            open++;
        }
        if (equation[i] == CLOSEBRACKET) {
            close++;
        }
    }
    if (open != close) {
        throw logic_error("Open brackets <> Close brackets");
    }
    stack<char> sign;
    char *number = new char[equation.length()];
    int j = 0;
    part = new char[equation.length()];
    for (size_t i = 0; i < equation.length(); i++) {
        while (isdigit(equation[i])) { //цифры
            number[j] = equation[i];
            j++;
        }
        if ((equation[i] == OPENBRACKET) || (equation[i] == MUL) || (equation[i] == ADD) || (equation[i] == SUB) ||
            (equation[i] == DIV)) {  //открывающаяся скобка, + - * /
            number[j + 1] = '\0';
            for (size_t k = size, s = 0; j > 0; j--, s++, size++) {
                part[k] = number[s];
            }
            sign.push(equation[i]);
        }
        if (equation[i] == CLOSEBRACKET) { //закрывающаяся скобка
            while (sign.top() != OPENBRACKET) {
                part[size] = sign.top();
                size++;
                sign.pop();
            }
            sign.pop();
        }
    }
    while (!sign.empty()) {
        part[size] = sign.top();
        sign.pop();
        size++;
    }
}

char *Parser::getPartition() {
    return part;
}

unsigned int Parser::getSize() {
    return size;
}

int Calculator::Calculated(Parser part) {
    stack<int> numbers;
    int j = 0;
    char *number = new char[part.getSize()];
    char *eq = new char[part.getSize()];
    strcpy(eq, part.getPartition());
    for (size_t i = 0; i < part.getSize(); i++) {
        while (isdigit(eq[i])) {
            number[j] = eq[i];
        }
        number[j + 1] = '\0';
        int num = atoi(number);
        numbers.push(num);
        j = 0;
        if (eq[i] == MUL) {
            int res = numbers.top();
            numbers.pop();
            res = res * numbers.top();
            numbers.pop();
            numbers.push(res);
        }
        if (eq[i] == ADD) {
            int res = numbers.top();
            numbers.pop();
            res = res + numbers.top();
            numbers.pop();
            numbers.push(res);
        }
        if (eq[i] == SUB) {
            int res = numbers.top();
            numbers.pop();
            res = res - numbers.top();
            numbers.pop();
            numbers.push(res);
        }
        if (eq[i] == DIV) {
            int res = numbers.top();
            numbers.pop();
            if (res != 0) {
                res = res / numbers.top();
                numbers.pop();
                numbers.push(res);
            } else {
                throw invalid_argument("Division by zero");
            }
        }
    }
    result = numbers.top();
    return result;
};

Polska::Polska(string equation) {
    try {
        Parser parser;
    }
    catch (logic_error e) {
        cout << e.what();
        return;
    };
    parser.toPart(equation);
    try {
        Calculator calculator;
        result = calculator.Calculated(parser);
    }
    catch (invalid_argument e) {
        cout << e.what();
        return;
    };
}

int Polska::getResult() {
    return result;
};

int main() {
    Polska polska("((5+5)*(4-3))/2");
    cout << polska.getResult();
    return 0;
}