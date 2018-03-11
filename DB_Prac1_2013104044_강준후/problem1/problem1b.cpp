#include <fstream>
#include <iostream>
#include <string>

using namespace std;



#define MAX_SIZE 1000

char inputString[MAX_SIZE];
int  main() {

	// 파일 입력 (쓰기)



	//파일 출력 (읽기)

	ifstream inFile("../problem1/output.txt");



	while (!inFile.eof()) {

		inFile.getline(inputString, 100);

		cout << inputString << endl;

	}

	inFile.close();

	return 0;

}