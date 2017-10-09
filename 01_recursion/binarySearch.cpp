//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include "importantFns.h"
#include <iostream>
using namespace std;

int binarySearching(int arr[], int be, int en, int toSearch){	//O(Log(n))
	if (be > en){
		//represents an invalid range
		return -1;
	}

	int mid = (be + en) / 2;
	//if found
	if (arr[mid] == toSearch) return mid;

	if (arr[mid] < toSearch){
		//scan in the right
		return binarySearching(arr, mid + 1, en, toSearch);
	}

	return binarySearching(arr, be, mid - 1, toSearch);

}

int main(){
	int arr[20];
	int n;
	cin >> n;
	inputArr(arr, n);
	int x;
	cin >> x;

	int pos = binarySearching(arr, 0, n-1, x);
	cout << pos; 
	
}
