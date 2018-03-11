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
	fin.open("../problem2/output.bin", ios_base::binary | ios_base::app);

	ofstream fout;
	fout.open("output.txt");

	char s[20];
	Student a;

	char c1; string str; char c2, c3;
	while (!fin.eof()) {
		fin.read((char*)&a.id, sizeof(a.id));
		fin.read((char*)a.name, sizeof(a.name));
		fin.read((char*)&a.gpa, sizeof(a.gpa));
		fout << a.id << " " << a.name << " " << a.gpa << endl;
	}


	fout.close();


	return 0;

}
