// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include <algorithm>
#include "arrayInput.h"
using namespace std;

int minMaxDiff(int arr[], int n, int k) {
    sort(arr, arr + n);

    int best = arr[n - 1] - arr[0];

    int begin = arr[0] + k;
    int end = arr[n - 1] - k;
    if (begin > end) swap(begin, end);

    for (int i = 1; i < n; ++i) {
        int cur = arr[i];
        int add = cur + k;
        int subtract  = cur - k;

        if (add <= end || subtract >= begin) continue;

        if (add - begin < end - subtract){
            end = add;
        }
        else {
            begin = subtract;
        }
    }

    return min(best, end-begin);
}

int main() {
    int arr[100];
    int n; cin >> n;

    inputArr(arr, arr + n);
    outputArr(arr, arr + n);
    int k ;
    cin >> k;

    cout << minMaxDiff(arr, n, k);
}