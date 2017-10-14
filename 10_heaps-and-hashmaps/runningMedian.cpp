// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Comparator {
public:
    bool operator()(const int& a, const int& b) {
        //is a should appear before b
        if (a > b) return true;
        else return false;
        //return a > b
    }
};


priority_queue<int> maxHeap;
priority_queue<int, vector<int>, Comparator> minHeap;
double M = 1000000000;    //M for median


void balance(){
   priority_queue<int> & left = maxHeap;
   auto & right = minHeap;

   int diff = right.size() - left.size();
   if (diff == 0) return;

   if (diff > 0){
        left.push(right.top());
        right.pop();
   }
   else if (diff < -1){
        right.push(left.top());
        left.pop();
   }
}

void setMedian() {
    if (maxHeap.size() == 0) return;

    if (maxHeap.size() == minHeap.size()) {
        M = 0.5 * (maxHeap.top() + minHeap.top());
    }
    else {
        M = maxHeap.top();
    }
}

void insert(int x) {
    if (x < M) {
        //insert into left
        maxHeap.push(x);
    }
    else {
        minHeap.push(x);
    }
    balance();
    setMedian();
}

double median(){
    return M;
}

void deleteFromSeq(){
    if (maxHeap.empty()) return;
    maxHeap.pop();
    balance();
    setMedian();
}

int main() {
    int x;
    char choice;
    bool isExit = false;

    while (isExit == false) {
        cin >> choice;
        switch (choice) {
        case 'A' :
            //Add
            cin >> x;
            insert(x);
            break;
        case 'D' :
            //Remove smaller element incase 2 are medians
            deleteFromSeq();
            break;
        case 'M' :
            cout << median() << endl;
            break;
        case 'E' :
            //exit
            isExit = true;
            break;
        }
    }
    return 0;
}