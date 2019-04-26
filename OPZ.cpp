#include <iostream>
#include <stack>

using namespace std;

class Partition {
    char *part;
    unsigned int size = 0;
public:

    void toPart (string equation){
        stack <char> sign;
        part = new char [equation.length()];
        for (size_t i=0; i < equation.length(); i++) {
            if (equation[i] >= 48 && equation[i] <= 57) { //цифры
                part[size] = equation[i];
                size++;
            }
            if ((equation[i] == 40) || (equation[i] == 42) || (equation[i] == 43) || (equation[i] == 45) || (equation[i] == 47)) {  //открывающаяся скобка, + - * /
                sign.push(equation[i]);
            }
            if (equation[i] == 41) { //закрывающаяся скобка
                while (sign.top() != 40) {
                    part[size]=sign.top();
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

    char* getPartition(){
        return part;
    }

    unsigned int getSize(){
        return size;
    }
};

class Polska{
    char* polska;
    unsigned int size=0;
public:

    void MakePolska(Partition partition){
        int j=0;
        stack <char> sign;
        polska = new char [partition.getSize()];
        char* part = partition.getPartition();
        for (size_t i=0; i < partition.getSize(); i++){
            if (part[i] >= 48 && part[i] <= 57) { //цифры
                    polska[size] = part[i];
                    size++;
                }
                if ((part[i] == 40) || (part[i] == 42) || (part[i] == 43) || (part[i] == 45) || (part[i] == 47)) {  //открывающаяся скобка, + - * /
                    sign.push(part[i]);
                }
                if (part[i] == 41) { //закрывающаяся скобка
                    while (sign.top() != 40) {
                        polska[size] = sign.top();
                        size++;
                        sign.pop();
                    }
                    sign.pop();
                }
            }
            while (!sign.empty()) {
                polska[size] = sign.top();
                size++;
                sign.pop();
            }
    }

    char* getPolska(){
        return polska;
    }

    unsigned int getSize(){
        return size;
    }
};

class Calculator {
    int result;
public:

    int Calculated() {
        stack <char> numbers;
        for (size_t i=0; i < equation.length(); i++) {
            if ((equation[i] == 42) || (equation[i] == 43) || (equation[i] == 45) || (equation[i] == 47)) {

            }
        }
    };
};

int main() {

}