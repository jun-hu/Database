#include <fstream>
#include <iostream>
#include <string>

using namespace std;
#define MAX_SIZE 1000
char inputString[MAX_SIZE];

int  main() {




	//���� ��� (�б�)

	ifstream inFile("../problem1/output.txt"); //����.



	while (!inFile.eof()) { //eof���� �о���Ѵ�.

		inFile.getline(inputString, 100); //100����Ʈ��ŭ �о�´�.

		cout << inputString << endl; //�о�°� ���

	}

	inFile.close(); //�ݴ´�.

	return 0;

}