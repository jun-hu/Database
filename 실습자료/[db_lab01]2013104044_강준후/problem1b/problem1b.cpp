#include <fstream>
#include <iostream>
#include <string>

using namespace std;
#define MAX_SIZE 1000
char inputString[MAX_SIZE];

int  main() {




	//파일 출력 (읽기)

	ifstream inFile("../problem1/output.txt"); //연다.



	while (!inFile.eof()) { //eof까지 읽어야한다.

		inFile.getline(inputString, 100); //100바이트만큼 읽어온다.

		cout << inputString << endl; //읽어온거 출력

	}

	inFile.close(); //닫는다.

	return 0;

}