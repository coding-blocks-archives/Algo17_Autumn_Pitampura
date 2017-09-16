//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "myHeader.cpp"
using namespace std;


//towerHanoi function shifts n discs from src to dest using helper
void towerHanoi(int n, char src, char dest, char helper) {
	if (n == 0) return;
	towerHanoi(n - 1, src, helper, dest);
	cout << "Move disc " << n << " from " << src << " to " << dest << endl;
	towerHanoi(n - 1, helper, dest, src);
}

int main() {
	int n;
	cin >> n;

	towerHanoi(n, 'A', 'B', 'C');
}