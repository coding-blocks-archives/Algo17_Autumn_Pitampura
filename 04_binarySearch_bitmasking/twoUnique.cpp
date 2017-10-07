//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <utility>
using namespace std;

int findXor(int arr[], int n){  //O(n)
    int ans = 0;
    for(int i = 0; i < n; ++i) ans ^= arr[i];
    return ans;
}


pair<int, int> twoUnique(int arr[], int n) {   //O(n)
    //PRINTS two unique elements
    //1 2 3 1 2 3 4 5
    int xored = findXor(arr, n);    //4 ^ 5

    int no1 = 0;

    int lastSetBit = xored & (-xored);
    for (int i = 0; i < n; ++i) {
        //if current element should belong to grp whose lastSetBit is set, then I will consider
        //that number
        if (lastSetBit & arr[i] != 0) no1 = no1 ^ arr[i];
    }

    int no2 = xored ^ no1;
    // cout << no1 << endl;
    // cout << no2 << endl;
    pair<int, int> obj;
    obj.first = no1;
    obj.second = no2;
    return obj;
}



int main() {
    int arr[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> arr[i];

    pair<int, int> ans = twoUnique(arr, n);
    cout << ans.first << " " << ans.second << endl;

    //pair of (pair of char, int) AND int
    // pair<pair<char, int>, int> p;
}
