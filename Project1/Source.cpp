#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main() {
	ifstream fin;
	string line;
	vector<STUDENT_DATA> studentData;

	fin.open("StudentData.txt");

	if (fin.is_open()) {
		while (!fin.eof()) {
			string line, first, last;
			STUDENT_DATA student;

			getline(fin, last, ',');
			getline(fin, first);

			student.firstName = first;
			student.lastName = last;

			studentData.push_back(student);
		}

		fin.close();
	}

	else {
		cout << "Cannot open file";
	}

	return 1;
}