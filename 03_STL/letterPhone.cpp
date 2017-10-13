//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "myHeader.cpp"
using namespace std;

//Time Complexity : O(2^n)
void letterphone(char number[], int be, char codeSoFar[], int i){
	if (number[be] == '\0'){
		//no more numbers to process
		codeSoFar[i] = '\0';
		cout << codeSoFar << endl;
		return;
	}

	//123 to be handled
	int correspondingNumber = number[be] - '0';
	char correspondingChar = 'a' + correspondingNumber - 1;
	codeSoFar[i] = correspondingChar;	//1 handled
	letterphone(number, be + 1, codeSoFar, i + 1);	//handle 23

	int tensPos = number[be] - '0';
	if (number[be + 1] == '\0') return;		//emptiness
	int onesPos = number[be + 1] - '0';
	int completeNum = tensPos * 10 + onesPos;
	if (completeNum > 26) return;
	codeSoFar[i] = 'a' + completeNum - 1;
	letterphone(number, be + 2, codeSoFar, i + 1);
}

int main(){
	char number[20] = "";
	char result[20] = "";
	// int x = 0;
	cin >> number;

	letterphone(number, 0, result, 0);	
}
