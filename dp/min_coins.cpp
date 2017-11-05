#include <iostream>
#include "header.h"
#include <climits>
#include <algorithm>
using namespace std;


// Time complexity -> O(noOfAvblCoins ^ change) where noOfAvblCoins is the number of available coins
// and change is the value of change
int minCoinsRec(int* avblCoins, int noOfAvblCoins, int change) {
	// if the change is exactly 0, you found a solution!
	if (change == 0) {
		return 0;
	}

	int result = INT_MAX; // from climits
	for (int i = 0; i < noOfAvblCoins; i++) {
		// if the value of the coin is greater than change, it can't be used therefore skip it.
		if (avblCoins[i] > change) {
			continue;
		}

		// else use this coin and try to make the change available
		int coinsReq = minCoinsRec(avblCoins, noOfAvblCoins, change - avblCoins[i]) + 1;
		if (coinsReq < result) {
			result = coinsReq;
		}
	}
	return result;
}


// Time complexity -> O(noOfAvblCoins * change) -> number of available coins * change
// Space complexity -> O(change) -> the size of the dp array
int minCoinsTopDown(int* avblCoins, int noOfAvblCoins, int change, int* dp) {
	// if the change is exactly 0, you found a solution!
	if (dp[change] != -1) {
		return dp[change];
	}
	if (change == 0) {
		return 0;
	}

	int result = INT_MAX; // from climits
	for (int i = 0; i < noOfAvblCoins; i++) {
		// if the value of the coin is greater than change, it can't be used therefore skip it.
		if (avblCoins[i] > change) {
			continue;
		}

		// else use this coin and try to make the change available
		int coinsReq = minCoinsTopDown(avblCoins, noOfAvblCoins, change - avblCoins[i], dp) + 1;
		if (coinsReq < result) {
			result = coinsReq;
		}
	}
	dp[change] = result;
	return result;
}

// Time complexity -> O(NK)
// Space complexity -> O(N) -> the size of the dp array
int minCoinsBottomApproach(int* avblCoins, int noOfAvblCoins, int change) {
	// This array contains the minimum amount of coins required to make the change.
	// for eg. dp[8] will be 2, as the min number of coins required to make 8 is 2 (1 + 7)
	int* dp = new int[change + 1];

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= change; i++) {
		int minCoins = INT_MAX;
		// for every coin try to make the change
		for (int j = 0; j < noOfAvblCoins; j++) {
			if (i - avblCoins[j] < 0) {
				continue;
			}
			int remChange = i - avblCoins[j];
			// we have the best way to reach the remaining amount i.e. dp[remChange]
			// so the best way to reach change amount is (dp[remChange] + 1)
			minCoins = min(dp[remChange] + 1, minCoins);
		}
		dp[i] = minCoins;
	}
	return dp[change];
}

int main(int argc, char const *argv[]) {
	/* code */
	int change;
	cin >> change;
	int avblCoins[] = {1, 7, 10};
	int* dp = new int[change + 1];
	setArrayWithValue(dp, change + 1, -1);
	// cout << minCoinsRec(avblCoins, 3, change) << endl;
	//cout << minCoinsTopDown(avblCoins, 3, change, dp) << endl;
	cout << minCoinsBottomApproach(avblCoins, 3, change) << endl;
	return 0;
}