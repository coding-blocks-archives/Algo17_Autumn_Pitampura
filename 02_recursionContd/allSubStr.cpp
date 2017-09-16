//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
# include <iostream>
# include <cstring>
#include "myHeader.cpp"
using namespace std;

void print(char arr[], int be, int en) {
	while (be <= en) {
		cout << arr[be];
		++be;
	}
	cout << endl;
}

void subStartingAtBe(char arr[], int be, int en) {
	for (int i = be; i <= en; ++i) {
		print(arr, be, i);
	}
}


void allSubstr(char arr[], int be, int en) {
	while (be <= en) {
		subStartingAtBe(arr, be, en);
		cout << endl;
		++be;
	}
}

int main() {
	char arr[100];
	cin >> arr;
	int len = strlen(arr);

	allSubstr(arr, 0, len - 1);
}