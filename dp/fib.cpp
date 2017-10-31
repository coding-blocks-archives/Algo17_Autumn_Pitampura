#include <iostream>
#include "header.h"

using namespace std;


// Time complexity -> O(2 ^ n)
// space complexity -> O(n) -> recursion stack size
/*
	Traditional method for computing the fibonacci of a number.
*/
int recFib(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return recFib(n - 1) + recFib(n - 2);
}

// Time complexity -> O(N)
// Space complexity -> O(N) -> the size of the dp array
/**
 * This method uses the top down approach(start at the top and break the problem into smaller pieces)
 * along with memoization(memorizing the results of	some specific states).
 */
int topDownDp(int n, int* dp) {
	if (n == 0 || n == 1) {
		return n;
	}
	// if we already have the answer, return that answer
	if (dp[n] != -1) {
		return dp[n];
	}
	// else compute the answer and store it
	dp[n] = topDownDp(n - 1, dp) + topDownDp(n - 2, dp);
	return dp[n];
}

// Time complexity -> O(N)
// Space complexity -> O(N) -> the size of the dp array
/**
 * This method uses the bottom up approach (starts at smaller ans and builds the answer of the higher terms)
 */
int bottomUpDp(int n) {
	int* dp = new int[n + 1];

	// we solve the smaller problem to get the solution to a larger problem.
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main(int argc, char const *argv[]) {
	int n;

	cin >> n;

	int* dp = new int[n + 1];
	// initialize arrays value with -1
	setArrayWithValue(dp, n + 1, -1);

	//int recFibAns = recFib(n);
	//cout << recFibAns << endl;
	//int topDownDpAns = topDownDp(n, dp);
	//cout << topDownDpAns << endl;

	int bottomUpDpAns = bottomUpDp(n);
	cout << bottomUpDpAns << endl;
	return 0;
}