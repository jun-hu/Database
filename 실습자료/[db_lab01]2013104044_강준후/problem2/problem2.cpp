#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct Student //student ����ü 
{
	int id; char name[20];
	float gpa;
};

#define MAX_SIZE 100
char inputString[MAX_SIZE];

int  main() {

	char* pch;
	vector<Student> sl; //student��ü ���� ����Ʈ �����.
	ifstream inFile("input.txt"); //�о���� ���� ����.
	ofstream fout("output.bin",ios_base::binary | ios_base::trunc); 
	//������ ������ �������Ϸ� ����. app�� �ڿ� ���δٴ� �÷���

	while (!inFile.eof()) {

		Student a;

		if (!inFile.getline(inputString, 100))
		{
			break;
		};

		pch = strtok(inputString, "|"); //ó������ �� ���ڿ�, �ι�°�� Ư������
		//string token�Լ��μ� Ư�� ���ڸ� �������� ���ڿ��� �߶��ش�.
		a.id = atoi(pch);
		//inFile.getline(inputString, 100);
		pch = strtok(NULL, "|"); //�ش� ���ڰ� ���� ������ ��� null
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


/*// ���� �Է� (����)

ofstream outFile("output.txt");

string a;
cin >> a;

if (outFile.is_open()) {
outFile << a;
}


outFile.close();

//���� ��� (�б�)

*/