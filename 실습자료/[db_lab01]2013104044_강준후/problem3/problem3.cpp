#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

struct Student
{
	int id; char name[100];
	float gpa;
};

#define MAX_SIZE 100
char inputString[MAX_SIZE];



int  main() {

	ifstream fin;
	fin.open("../problem2/output.dat", ios_base::binary | ios_base::app);

	ofstream fout;
	fout.open("output.txt",ios::trunc);

	char s[20];
	Student a;

	char c3[2] = {};	char c1[4] = {}; char str[100] = {}; char c2[4] = {};
	while (!fin.eof()) {
		fin.read((char*)&c1, 4);
		a.id = atoi(c1);
		fin.read((char*)&str, 6);
		strcpy(a.name, str);
		fin.read((char*)&c3, 2);
		fin.read((char*)&c2, 4);
		a.gpa = atof(c2);
		cout<< a.id << " " << a.name << " " << a.gpa << endl;
		fout << a.id << " " << a.name << " " << a.gpa << endl;
	}

	fin.close();
	fout.close();


	return 0;

}
