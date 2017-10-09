//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

int fact(int n){	//O(n)
	if (n <= 0) return 1;
	int res = n * fact(n - 1);
	return res;
}


int main(){
	int n;
	cin >> n;	//read n
	int ans = fact(n);
	cout << ans; //print factorial(n)
}
