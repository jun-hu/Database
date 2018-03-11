#include <fstream>
#include <iostream>
#include <string>

using namespace std;



#define MAX_SIZE 1000

char inputString[MAX_SIZE];



int  main() {

	// 파일 입력 (쓰기)

	ofstream outFile("output.txt");

	string a;
	cin >> a;

	if (outFile.is_open()) {
		outFile << a;
	}


	outFile.close();


	return 0;

}
