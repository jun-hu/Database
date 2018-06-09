#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Student
{
	int id; char name[20];
	float gpa;
};

#define MAX_SIZE 100

char inputString[MAX_SIZE];



int  main() {

	ifstream fin;
	fin.open("../problem2/output.bin", ios_base::binary | ios_base::app);
	vector<Student> sl;
	char s[20];
	Student a;

	char c1; string str; char c2, c3;
	while (!fin.eof()) {
		fin.read((char*)&a.id, sizeof(a.id));
		fin.read((char*)a.name, sizeof(a.name));
		fin.read((char*)&a.gpa, sizeof(a.gpa));
		sl.push_back(a);
	}

	string name;
	cin >> name;
	
	for (int i = 0 ; i < sl.size(); i++)
	{
		if (name == sl.at(i).name) cout << sl.at(i).id << " " << sl.at(i).name << " " << sl.at(i).gpa << endl;
	}
	return 0;
}
