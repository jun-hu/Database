//#define _CRT_SECURE_NO_WARNINGS
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
	int id; char name[20];
	float gpa;
};

#define MAX_SIZE 100
char inputString[MAX_SIZE];

int  main() {

	ifstream fin;
	fin.open("../problem2/output.bin", ios_base::binary | ios_base::app);

	ofstream fout;
	fout.open("output.txt",ios::trunc);

	char s[20];
	Student a;
	int fileSize;
	if (fin)
	{
		fin.seekg(0, ios::end); //파일포인터를 지정한 시작위치부터 오프셋 바이트 만큼 이동한다.
		fileSize = (int)fin.tellg(); //현재 파일 포인터의 위치를 가져옴
		fin.seekg(0, ios::beg);
	}
	
	
	char c3[2] = {'a','b'};	char c1[4] = {}; char str[100] = {}; char c2[4] = {};
	while ((int)fin.tellg()!=fileSize) {
		//!fin.eof()
		//fin.read((char*)&a, sizeof(a));
		fin.read((char*)&a.id, sizeof(a.id));
		//a.id = atoi(c1);
		fin.read((char*)&a.name, sizeof(a.name));
		//fin.read((char*)&c3, 2);
		fin.read((char*)&a.gpa, sizeof(a.gpa));

		cout<< a.id << " " << a.name << " " << a.gpa << endl;
		fout << a.id << " " << a.name << " " << a.gpa << endl;
	}

	fin.close();
	fout.close();


	return 0;

}
