#include "pch.h"
#include <iostream>
using namespace std; 



class Student {
private:
	unsigned int countOfMark = 0;
	float averegeOfMark = 0;
	unsigned int Marks = 0;
public:
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

class Mama{
public:
	int moodness;
	Mama(int mood) {
		moodness = mood;
	}

	bool moodIsGood(Student student) {
		if (student.getMark() >= moodness) {
			return true;
		}
		else return false;
	};



};

int main()
{
	Student Vasya;
	Mama Angela(4);
	int n, mark;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> mark;
		Vasya.setMark(mark);

	}
	if (Angela.moodIsGood(Vasya)) {
		cout << "good";
	}
	else { cout << "bad"; }
}