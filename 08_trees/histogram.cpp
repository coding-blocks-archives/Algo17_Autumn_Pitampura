//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <stack>
using namespace std;

int histogram(int arr[], int n) {
    int cur  = 0;
    stack<int> s;
    cur = arr[0];
    int best = cur;
    s.push(0);

    for (int i = 0; !s.empty() && i < n; ++i) {
        if (arr[s.top()] < arr[i]) {
            best = max(best, arr[i]);
            cur = arr[s.top()] * (i - s.top() + 1);
            s.push(i);
            best = max(best, cur);
            // cur = arr[i];
        }
        else {
            while (!s.empty() && arr[i] < arr[s.top()]) {
                int curSum = arr[i] * (i - s.top() + 1);
                s.pop();
                best = max(curSum, best);
            }
        }
    }
    return best;
}

int main() {
    int arr[10];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    cout << histogram(arr, n);
}