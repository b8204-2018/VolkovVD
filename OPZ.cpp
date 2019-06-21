#include <iostream>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <OPZ.h>

using namespace std

const int EMPTY = -1;
const int ZERO = 0;

class Parser {
    char *part;
    unsigned int size = 0;
public:

    void toPart(string equation) {
        if (strlen(equation) < 3){
            throw EMPTY;
        }
        catch(EMPTY);
        size_t open = 0, close = 0;
        for (size_t i = 0; i < strlen(equation); i++) {
            if (equation[i] == 40) {
                open++;
            }
            if (equation[i] == 41) {
                close++;
            }
        }
        if (open != close) {
            throw invalid_argument(equation);
        }
        catch(invalid_argument(equation));
        stack<char> sign;
        part = new char[equation.length()];
        for (size_t i = 0; i < equation.length(); i++) {
            if (equation[i] >= 48 && equation[i] <= 57) { //цифры
                part[size] = equation[i];
                size++;
            }
            if ((equation[i] == 40) || (equation[i] == 42) || (equation[i] == 43) || (equation[i] == 45) ||
                (equation[i] == 47)) {  //открывающаяся скобка, + - * /
                sign.push(equation[i]);
            }
            if (equation[i] == 41) { //закрывающаяся скобка
                while (sign.top() != 40) {
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

    char *getPartition() {
        return part;
    }

    unsigned int getSize() {
        return size;
    }
};

class Calculator {
    int result;
public:

    int Calculated(Parser part) {
        stack<int> numbers;
        char *eq = new char[part.getSize()];
        strcpy(eq, part.getPartition());
        for (size_t i = 0; i < part.getSize(); i++) {
            if (eq[i] >= 48 && eq[i] <= 57) {
                int num = atoi(&eq[i]);
                numbers.push(num);
            }
            if (eq[i] == 42) {
                int res = numbers.top();
                numbers.pop();
                res = res * numbers.top();
                numbers.pop();
                numbers.push(res);
            }
            if (eq[i] == 43) {
                int res = numbers.top();
                numbers.pop();
                res = res + numbers.top();
                numbers.pop();
                numbers.push(res);
            }
            if (eq[i] == 45) {
                int res = numbers.top();
                numbers.pop();
                res = res - numbers.top();
                numbers.pop();
                numbers.push(res);
            }
            if (eq[i] == 47) {
                int res = numbers.top();
                numbers.pop();
                if (res != 0) {
                    res = res / numbers.top();
                    numbers.pop();
                    numbers.push(res);
                }
                else {
                    throw (ZERO);
                }
                catch(ZERO);
            }
        }
        result = numbers.top();
        return result;
    };
};

class Polska {
    int result;
public:
    Polska(string equation) {
        Parser parser;
        parser.toPart(equation);
        Calculator calculator;
        result = calculator.Calculated(parser);
    }

    int getResult() {
        return result;
    };
};

int main() {
    Polska polska("((5+5)*(4-3))/2");
    cout << polska.getResult();
}