#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>


using namespace std;

struct Student
{
	int id; char name[100];
	float gpa;
};

#define MAX_SIZE 100

char inputString[MAX_SIZE];



int  main() {

	char* pch;
	list<Student> sl;
	ifstream inFile("input.txt");
	//ofstream oup2("output.dat", ios::in | ios::out | ios::binary);
	ofstream fout("output.bin", ios_base::binary | ios_base::app);
	//oup2.seekp(0, ios::beg);


	while (!inFile.eof()) {

		Student a;

		//inFile.getline(inputString, 100);
		if (!inFile.getline(inputString, 100))
		{
			break;
		};

		pch = strtok(inputString, "|");
		a.id = atoi(pch);
		//inFile.getline(inputString, 100);
		pch = strtok(NULL, "|");
		strcpy_s(a.name, pch);
		//inFile.getline(inputString, 100);
		pch = strtok(NULL, "\n");
		a.gpa = atof(pch);
		sl.push_back(a);
	}


	list<Student>::iterator iter;
	for (iter = sl.begin(); iter != sl.end(); iter++)
	{
		fout.write((char*)&(*iter), sizeof Student);
	}

	//cout << (*iter).id << " " << (*iter).name << " " << (*iter).gpa << endl;

	fout.close();


	return 0;

}


/*// 파일 입력 (쓰기)

ofstream outFile("output.txt");

string a;
cin >> a;

if (outFile.is_open()) {
outFile << a;
}


outFile.close();

//파일 출력 (읽기)

*/