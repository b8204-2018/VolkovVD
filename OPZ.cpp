#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

class Calculator {
	int result;
	string equation;
public:

	void setEquation(string eq) {
		equation = eq;
	};

	void makePolska() {
		string buff;
		stack <char> sign;
		for (size_t i=0; i < equation.length(); i++) {
			if (equation[i] >= 48 && equation[i] <= 57) { //цифры
				buff = buff + equation[i];
			}
			if ((equation[i] == 40) || (equation[i] == 42) || (equation[i] == 43) || (equation[i] == 45) || (equation[i] == 47)) {  //открывающаяся скобка, + - * /
				sign.push(equation[i]);
			}
			if (equation[i] == 41) { //закрывающаяся скобка
				while (sign.top() != 40) {
					buff = buff + sign.top();
					sign.pop();
				}
				sign.pop();
			}
		}
		while (!sign.empty()) {
			buff = buff + sign.top();
			sign.pop();
		}
		equation = buff;
	};

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
