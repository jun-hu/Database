#include <fstream>
#include <iostream>
#include <string>
using namespace std;


#define MAX_SIZE 1000
char inputString[MAX_SIZE];


int  main() {

	// ���� �Է� (����)
	ofstream outFile("output.txt"); //������ ����.

	string a;
	cin >> a;
	
	if (outFile.is_open()) { //����������
		outFile << a; //�־��ش�.
	}

	outFile.close(); //�ݴ´�.

	return 0;

}