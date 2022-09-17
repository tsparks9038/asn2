#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define LOG(x) cout << x << endl;
#define MODE cout << "Program running in pre-release" << endl;
#else
#define LOG(x)
#define MODE cout << "Program running in standard" << endl;
#endif

struct STUDENT_DATA {
	string firstName;
	string lastName;
	string email;
};

int main() {
	ifstream fin;
	string line;
	vector<STUDENT_DATA> studentData;

	MODE;

	fin.open("StudentData_Emails.txt");

	if (fin.is_open()) {
		while (!fin.eof()) {
			string line, first, last, email;
			STUDENT_DATA student;

			getline(fin, last, ',');
			getline(fin, first, ',');
			getline(fin, email);

			student.firstName = first;
			student.lastName = last;
			student.email = email;

			studentData.push_back(student);

			LOG(student.firstName);
			LOG(student.lastName);
			LOG(student.email);
		}

		fin.close();
	}

	else {
		cout << "Cannot open file";
	}

	return 1;
}