//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include <cmath>
#include "myHeader.cpp"
using namespace std;
const int D = 20;
bool myfixed[D][D];

void initialize(int board[][D], int N){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if (board[i][j] != 0){
				myfixed[i][j] = true;
			}
			else{
				myfixed[i][j] = false;
			}
		}
	}
}

bool canPlace(int board[][D], int x, int y, int N, int numToPlace){
	for(int i = 0; i < N; ++i){
		//row
		if (board[x][i] == numToPlace) return false;
		if (board[i][y] == numToPlace) return false;
	}

	int rootN = sqrt(N);
	int rowStrip = x / rootN;	//TRUNCATION
	//x / rootN is effectively floor(x / rootN)
	int colStrip = y / rootN;
	int matRowBe = rowStrip * rootN;
	int matColBe = colStrip * rootN;
	int matRowEn = matRowBe + rootN;
	int matColEn = matColBe + rootN;
	//[matRowBe, matRowEn)

	for(int i = matRowBe; i < matRowEn; ++i){
		for(int j = matColBe; j < matColEn; ++j){
			if (board[i][j] == numToPlace) return false;
		}
	}
	return true;
}


bool solveSudoku(int board[][D], int x, int y, int N) {
	if (x >= N) return true;

	if (y >= N){
		//I have crossed the columns
		return solveSudoku(board, x + 1, 0, N);
	}

	if (myfixed[x][y] == true) {
		return solveSudoku(board, x, y + 1, N);
	}

	for (int curTrial = 1; curTrial <= N; ++curTrial) {
		if (canPlace(board, x, y, N, curTrial)) {
			board[x][y] = curTrial;
			bool isSolved = solveSudoku(board, x, y + 1, N);
			if (isSolved) return true;
			board[x][y] = 0;
		}
	}
	return false;

}

int main() {
	int N;
	cin >> N;
	int board[D][D] =
	{	{5, 3, 0, 5, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	initialize(board, N);

	bool isSolved = solveSudoku(board, 0, 0, N);

	if (isSolved == true) {
		print2DArr(board, N, N);
	}
	else {
		cout << "Oops! Wrong Sudoku Input...else we have solved it" << endl;
	}
}