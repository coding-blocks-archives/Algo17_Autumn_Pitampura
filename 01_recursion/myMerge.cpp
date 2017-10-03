//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "importantFns.h"
#include <iostream>
using namespace std;

int a[20];
int b[20];
int res[40];

void copy(int from[], int be, int nFrom, int to[],  int toBe) {	//O(n)
	//copies from[be, en] to to[]
	//to has enough space to accomodate the elements--Assumption
	for (int i = be; i < nFrom; ++i) {
		to[toBe] = from[i];
		++toBe;
	}
}

void myMerge(int i, int j, int k, int nA, int nB) {	//O(n)  
							//O(nA+nB)
	//i --> A
	//j --> B
	//k --> res

	if (i == nA) {
		//A is empty
		//copy B into res
		copy(b, j, nB, res, k);
	}
	else if (j == nB) {
		//b is empty
		copy(a, i, nA, res, k);
	}
	else {
		//I can gurantee that I have atleast 1 element in both the arrays
		if (a[i] < b[j]) {
			res[k] = a[i];
			myMerge(i + 1, j, k + 1, nA, nB);
		}
		else {
			res[k] = b[j];
			myMerge(i, j + 1, k + 1, nA, nB);
		}
	}
}



int main() {
	int nA, nB;
	cin >> nA >> nB;

	inputArr(a, nA);
	inputArr(b, nB);
	myMerge(0, 0, 0, nA, nB);
	printArr(res, nA + nB);

}
