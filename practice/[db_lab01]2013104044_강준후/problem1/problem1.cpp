#include <fstream>
#include <iostream>
#include <string>
using namespace std;


#define MAX_SIZE 1000
char inputString[MAX_SIZE];


int  main() {

	// 파일 입력 (쓰기)
	ofstream outFile("output.txt"); //파일을 연다.

	string a;
	cin >> a;
	
	if (outFile.is_open()) { //열려있으면
		outFile << a; //넣어준다.
	}

	outFile.close(); //닫는다.

	return 0;

}