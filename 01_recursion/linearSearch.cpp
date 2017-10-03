//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

void inputArr(int arr[], int sze){	//O(n)
	for(int i = 0; i < sze; ++i){
		cin >> arr[i];
	}
}

int linearSearch(int arr[], int be, int N, int toSearch){	//O(n)
	//base case
	if (be == N) return -1;	//base case

	if (arr[be] == toSearch) return be;

	int pos = linearSearch(arr, be + 1, N, toSearch);
	//recurrence step
	//hypotheses
	//assumption..that recursion always works
	return pos;
}


int main(){
	int n;
	cin >> n;
	int arr[20];

	// input arr
	inputArr(arr, n);

	int x;
	cin >> x;

	int pos = linearSearch(arr, 0, n, x);

	cout << pos;

}
