//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "myHeader.cpp"
using namespace std;

int mySqrt(int n) {
	int be = 0;
	int en = n;
	int mid;

	while (be <= en) {
		mid = (be + en) / 2;
		if (mid * mid == n) return mid;
		else if (mid * mid <= n) {
			be = mid + 1;
		}
		else {
			en = mid - 1;
		}
	}
	return mid - 1;
}


int main() {
	int n;
	cin >> n;

	int rootn = mySqrt(n);
	cout << rootn;
}