#include "pch.h"
#include <iostream>
using namespace std; 

class Relaitive {


};

class Student {
public:
	unsigned int countOfMark = 0;
	float averegeOfMark = 0;
	unsigned int Marks = 0;

	void setMark(unsigned int mark) {
		if ((mark > 0) && (mark < 6)) {
			countOfMark++;
			Marks += mark;
			averegeOfMark = Marks / countOfMark;
		}
		else { cout << "wrong mark" << endl; }
	};

	float getMark() {
		return averegeOfMark;
	};

};

class Babushka: public Relaitive {
public:
	bool moodIsGood(Student student) {
		if (student.averegeOfMark > 0) {
			return true;
		}
		else return false;
	};

};

class Papa: public Relaitive {
public:
	bool moodIsGood(Student student) {
		if (student.Marks >= 2*student.countOfMark) {
			return true;
		}
		else return false;
	};

};

class Mama: public Relaitive{
public:
	int moodness;
	Mama(int mood) {
		moodness = mood;
	}

	bool moodIsGood(Student student) {
		if (student.averegeOfMark >= moodness) {
			return true;
		}
		else return false;
	};



};


int main()
{
	Student Vasya;
	Mama Angela(4);
	Papa Eduard;
	Babushka Masha;

	int n, mark;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> mark;
		Vasya.setMark(mark);

	}


	if (Eduard.moodIsGood(Vasya)) {
		cout << "papa: good";
	}
	else { cout << "papa: bad"; }
	if (Angela.moodIsGood(Vasya)) {
		cout << "mama: good" << endl;
	}
	else { cout << "mama: bad" << endl; }
}