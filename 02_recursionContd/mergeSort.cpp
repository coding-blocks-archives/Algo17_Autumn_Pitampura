//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "myHeader.cpp"
using namespace std;

//myMerge merges the sorted array arr, from [be, mid] & [mid+1, en] into arr
void myMerge(int arr[], int be, int en) {
	int mid = (be + en) / 2;

	// [be, mid] --> left
	int a[10];
	for (int i = be; i <= mid; ++i) {
		a[i - be] = arr[i];
	}

	//[mid + 1, en] --> right
	int b[10];
	for (int i = mid + 1; i <= en; ++i) {
		b[i - (mid + 1)] = arr[i];
	}

	int i = be;
	int j = mid + 1;
	int k = be;
	while (i <= mid && j <= en) {
		if (a[i - be] < b[j - (mid + 1)]) {
			arr[k] = a[i - be];
			++i;
			++k;
		}
		else {
			arr[k] = b[j - (mid + 1)];
			++j;
			++k;
		}
	}

	while (i <= mid) {
		arr[k] = a[i - be];
		++k;
		++i;
	}
	while (j <= en) {
		arr[k] = b[j - (mid + 1)];
		++k;
		++j;
	}

}

// mergeSort sorts an INTEGER ARRAY starting from be and ending at en, both inclusive
void mergeSort(int arr[], int be, int en) {
	if (be >= en) {
		//just one element
		//one element is always sorted
		return ;
	}

	int mid = (be + en) / 2;
	mergeSort(arr, be , mid);
	mergeSort(arr, mid + 1, en);
	myMerge(arr, be, en);

}


int main() {
	int arr[10];
	int n;
	cin >> n;
	inputArr(arr, n);

	mergeSort(arr, 0, n - 1);

	printArr(arr, n);
}