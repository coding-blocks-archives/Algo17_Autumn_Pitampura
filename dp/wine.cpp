#include <iostream>
#include "header.h"
#include <climits>
#include <algorithm>
using namespace std;

int maxPriceRec(int* wines, int be, int end, int days) {
	if (be > end) {
		return 0;
	}
	int leftPrice = maxPriceRec(wines, be + 1, end, days + 1) + days * wines[be];
	int rightPrice = maxPriceRec(wines, be, end - 1, days + 1) + days * wines[end];
	return max(leftPrice, rightPrice);
}

int maxPriceTopDownDP(int* wines, int be, int end, int days, int ** dp) {
	if (be > end) {
		return 0;
	}
	if (dp[be][end] != -1) {
		return dp[be][end];
	}
	int leftPrice = maxPriceTopDownDP(wines, be + 1, end, days + 1, dp) + days * wines[be];
	int rightPrice = maxPriceTopDownDP(wines, be, end - 1, days + 1, dp) + days * wines[end];
	dp[be][end] = max(leftPrice, rightPrice);
	return dp[be][end];
}

int main(int argc, char const *argv[]) {
	int wines[] = {2, 3, 5, 1, 4};
	int bottles = sizeof(wines)/sizeof(int);
	// cout << maxPriceRec(wines, 0, bottles - 1, 1) << endl;
	
	// initialize the dp matrix with -1
	int* *dp = new int*[bottles + 1];
	for (int i = 0; i <= bottles; i++) {
		dp[i] = new int[bottles + 1];
		for (int j = 0; j <= bottles; j++) {
			dp[i][j] = -1;
		}
	}
	cout << maxPriceTopDownDP(wines, 0, bottles - 1, 1, dp) << endl;

	return 0;
}