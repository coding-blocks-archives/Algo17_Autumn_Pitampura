//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "myHeader.cpp"
using namespace std;

char board[20][20];
void initialise(char board[][20], int n, char ch){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			board[i][j] = ch;
		}
	}
}

bool canPlace(char board[][20], int x, int y, int n) {
	//check for row
	for (int c = 0; c < n; ++c) {
		if (board[x][c] == 'Q') return false;
	}

	//check for col
	for (int r = 0; r < n; ++r) {
		if (board[r][y] == 'Q') return false;
	}

	int rDir[] = { -1, +1, +1, -1};
	int cDir[] = { -1, +1, -1, +1};
	int nDir = sizeof(rDir) / sizeof(int);

	for(int d = 0; d < nDir; ++d){
		int r = rDir[d];
		int c = cDir[d];

		int cx = x + r;
		int cy = y + c;
		while(cx >= 0 && cx < n && cy >= 0 && cy < n){
			if (board[cx][cy] == 'Q') return false;
			cx += r;
			cy += c;
		}
	}

	return true;
}


bool queen(int cRow, int n) {
	if (cRow == n) {
		return true;
	}

	//for every col in current Row, check if its the right cell to place the queen
	for (int c = 0; c < n; ++c) {
		if (canPlace(board, cRow, c, n) == true) {
			//pruning
			board[cRow][c] = 'Q';
			bool isSuccessful = queen(cRow + 1, n);	//try to keep n-1 queens on the remaining board
			if (isSuccessful) return true;

			board[cRow][c] = 'X';	//backtracking
			//restoring the original state
		}
	}
	return false;
}


int main() {
	int n;
	cin >> n;

	initialise(board, 20, 'X');

	bool isSuccessful = queen(0, n);


	if (isSuccessful) {
		print2DArr(board, n, n);
	}
	else {
		cout << "Sorry Man! Can't do...";
	}
	return 0;
}