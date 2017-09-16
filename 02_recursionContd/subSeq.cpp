//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "myHeader.cpp"
#include <cstring>
using namespace std;

char output[100];	//contains one of the possible subsequence from [0, outBe]


//subseq prints all the subsequence of arr[be, en]
void subSeq(char arr[], int be, int en, int outBe){

	if (be > en){
		output[outBe] = '\0';
		cout << output << endl;
		return;
	}

	//lets leave a
	subSeq(arr, be + 1, en, outBe);

	//lets include a
	output[outBe] = arr[be];
	subSeq(arr, be + 1, en, outBe + 1);



}


int main(){
	char s[100];
	cin >> s;

	int len = strlen(s);

	subSeq(s, 0, len - 1, 0);	
}