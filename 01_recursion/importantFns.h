//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#ifndef IMP_FNS
#define IMP_FNS

#include <iostream>
using namespace std;

void inputArr(int arr[], int sze){	//O(n)
	for(int i = 0; i < sze; ++i){
		cin >> arr[i];
	}
}

void printArr(int arr[], int sze){	//O(n)
	for(int i = 0; i < sze; ++i) cout << arr[i] << " ";
	cout << endl; 
}

#endif
