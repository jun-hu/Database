#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct Student //student 구조체 
{
	int id; char name[20];
	float gpa;
};

#define MAX_SIZE 100
char inputString[MAX_SIZE];

int  main() {

	char* pch;
	vector<Student> sl; //student객체 넣을 리스트 만든다.
	ifstream inFile("input.txt"); //읽어들일 파일 연다.
	ofstream fout("output.bin",ios_base::binary | ios_base::trunc); 
	//저장할 파일을 이진파일로 연다. app는 뒤에 붙인다는 플래그

	while (!inFile.eof()) {

		Student a;

		if (!inFile.getline(inputString, 100))
		{
			break;
		};

		pch = strtok(inputString, "|"); //처음에는 들어갈 문자열, 두번째는 특정문자
		//string token함수로서 특정 문자를 기준으로 문자열을 잘라준다.
		a.id = atoi(pch);
		//inFile.getline(inputString, 100);
		pch = strtok(NULL, "|"); //해당 문자가 끝날 때까지 계속 null
		strcpy_s(a.name, pch);
		//inFile.getline(inputString, 100);
		pch = strtok(NULL, "\n");
		a.gpa = atof(pch);
		sl.push_back(a);
		cout << a.id << a.name << a.gpa << endl;
		cout << "size:" << sizeof(Student) << endl;
	}


	for (int i = 0; i < sl.size(); i++)
	{
		fout.write((char*)&sl.at(i), sizeof(Student));
	}

	//fout.write((char*)&sl.begin(),sizeof(sl)

	//cout << (*iter).id << " " << (*iter).name << " " << (*iter).gpa << endl;
	inFile.close();
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