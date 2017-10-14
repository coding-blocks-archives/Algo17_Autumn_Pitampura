// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <queue>
#include <iostream>
using namespace std;

bool comparator(int a, int b) {
    //if a appears before b
    if (a < b) return true;
    else return false;
}

class compare {
public:
    bool operator()(const int& a, const int& b) {
        //if a appears before b
        if (a > b) return true;
        else return false;
    }
};

compare obj;
sort(beg, end, compare);

int main() {
    priority_queue<int, vector<int>, compare> q;

    q.push(2);
    q.push(3);
    cout << q.top();
}