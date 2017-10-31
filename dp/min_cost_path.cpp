/**
 * Finding Minimum-Cost Path in a 2D Matrix
 */
#include <iostream>
#include "header.h"
#include <climits>
#include <algorithm>
using namespace std;

// Time complexity => O(2 ^ (rows * cols))
int minCostPathRec(int* *cost, int rows, int cols, int desX, int desY) {
	if (desX == 0 && desY == 0) {
		return 0;
	}
	if (desX < 0 || desY < 0 || desX > rows || desY > cols) {
		return INT_MAX;
	}
	// either you came from left
	int fromLeft = minCostPathRec(cost, rows, cols, desX - 1, desY);
	// or you came from up
	int fromUp = minCostPathRec(cost, rows, cols, desX, desY - 1);
	// return the min value
	return min(fromLeft, fromUp) + cost[desX][desY];
}

// Time complexity => O(rows * cols)
// Space complexity => O(rows * cols)
int minCostPathDP(int* *cost, int rows, int cols, int desX, int desY, int** dp) {
	if (desX == 0 && desY == 0) {
		return 0;
	}
	if (desX < 0 || desY < 0 || desX > rows || desY > cols) {
		return INT_MAX;
	}
	if (dp[desX][desY] != -1) {
		return dp[desX][desY];
	}
	// either you came from left
	int fromLeft = minCostPathDP(cost, rows, cols, desX - 1, desY, dp);
	// or you came from up
	int fromUp = minCostPathDP(cost, rows, cols, desX, desY - 1, dp);
	// chose the min value and store the result
	dp[desX][desY] = min(fromLeft, fromUp) + cost[desX][desY];
	return dp[desX][desY];
}

int main(int argc, char const *argv[]) {
	int rows, cols, desX, desY;
	cin >> rows >> cols;
	int** cost = new int*[rows];
	matInput(cost, rows, cols);
	cin >> desX >> desY;
	//cout << minCostPathRec(cost, rows, cols, desX, desY) << endl;
	
	// initialize dp array
	int** dp = new int*[rows];
	initMat(dp, rows, cols, -1);
	cout << minCostPathDP(cost, rows, cols, desX, desY, dp) << endl;
	return 0;
}