//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

void inputArr(int arr[], int sze){
	for(int i = 0; i < sze; ++i){
		cin >> arr[i];
	}
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; ++i) cout << arr[i] << " ";
	cout << endl;
}

void print2DArr(int arr[][20], int M, int N){
	for(int i = 0; i < M; ++i){
		for(int c = 0; c < N; ++c){
			cout << arr[i][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
}