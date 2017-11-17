// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include <list>
using namespace std;

void insertIntoQue(list<int>& q, int x){
    int cnt = 0;
    while (q.empty() == false && x < q.back()) {
        ++cnt;
        q.pop_back();
    }
    while (cnt >= 0) q.push_back(x), --cnt;
}


void fillMinimum(int arr[], int n, int output[], int& idx, int winSize) {
    list<int> q;
    //look at indices
    //whenever position and value are associated think of indices
    for (int i = 0; i < winSize; ++i) {
        insertIntoQue(q, arr[i]);
    }

    int i = winSize;
    for (;;) {
        output[idx++] = q.front();
        if (i == n) break;
        q.pop_front();
        insertIntoQue(q, arr[i]);
        ++i;
    }
}



int main() {
    int n;
    cin >> n;
    int arr[100];

    for (int i = 0; i < n; ++i)  cin >> arr[i];

    int output[100];
    int n2 = 0;

    int windowSize = 0;
    cin >> windowSize;

    fillMinimum(arr, n, output, n2, windowSize);

    for (int i = 0; i < n2; ++i)  cout << output[i] << " ";

}