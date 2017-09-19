//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "myHeader.cpp"
using namespace std;

const char codes[][5] = {
	" ", 
	"@!.", "abc", "def",
	"ghi", "jkl", "mno",
	"pqrs", "tuwv", "xyz"
};

char ans[20] = "";

void printCodes(char number[], int be){
	if (number[be] == '\0'){
		ans[be] = '\0';
		cout << ans << endl;
		return;
	}

	int idx = number[be] - '0';
	const char *correspondingString = codes[idx];
	for(int i = 0; correspondingString[i] != '\0'; ++i){
		ans[be] = correspondingString[i];
		printCodes(number, be + 1);
	}
}


int main(){
	char input[20];
	cin >> input;

	printCodes(input, 0);
		
}