// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class Comparator{
public:
    bool operator()(const int& a, const int& b){
        //is a should appear before b
        if (a > b) return true;
        else return false;
        //return a > b
    }
};

vector<int> bestKElements(vector<int>& v, int k){
    priority_queue<int, vector<int>, Comparator> pq;    //minHeap

    for(int i = 0; i < k; ++i) pq.push(-100000); //-inf

    for(int i = 0; i < v.size(); ++i){
        if (pq.top() < v[i]){
            pq.pop();
            pq.push(v[i]);
        }
    }

    vector<int> ans;
    while(pq.empty() == false){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
    vector<int> v;  
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x; 
        cin >> x;
        v.push_back(x);
    }

    int k;
    cin >> k;

    vector<int> res = bestKElements(v, k);  //greatest K elements

    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    
}