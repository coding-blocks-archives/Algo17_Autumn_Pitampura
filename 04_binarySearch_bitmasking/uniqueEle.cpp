//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

int findUnique(int arr[], int n){   //O(n)
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
    int arr[100];
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> arr[i]; 

    int uniqueEle = findUnique(arr, n);  
    cout << uniqueEle;
}
