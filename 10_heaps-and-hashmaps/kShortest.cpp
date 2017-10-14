// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef  tuple<int, int, int>  iii;

class Comparator {
public:
    bool operator()(const iii& t1, const iii& t2) {
        //if t1 should appear before t2
        return get<0>(t1) > get<0>(t2);
    }
};

vector<int> mergeKSorted(vvi& v, int k) {
    // iii t; //val, arrayNo, idxNo; val, r, c

    priority_queue<iii, vector<iii>, Comparator> minHeap;
    vector<int> ans;

    //setting the scene
    for (int i = 0; i < k; ++i) {
        minHeap.push(make_tuple(v[i][0], i, 0));
    }

    while (minHeap.empty() == false) {
        iii t = minHeap.top();
        minHeap.pop();
        ans.push_back(get<0>(t));

        //check for r, c+1
        int r = get<1>(t);
        int c = get<2>(t) + 1;
        if (c < v[r].size()) {
            //insert
            minHeap.push(make_tuple(v[r][c], r, c));
        }
    }
    return ans;
}

void input(vvi& v, int k) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> v[i][j];
        }
    }
}

void print(vi& v, int k) {
    for (int i = 0; i < v.size(); ++i) {
        // for (int j = 0; j < k; ++j) {
            cout << v[i] << " ";
        // }
        // cout << endl;
    }
}

int main() {
    int k;
    cin >> k;
    // vector<int> v(2, 1);

    vector<vector<int> > v(k, vector<int>(k));
    input(v, k);

    vector<int> ans = mergeKSorted(v, k);

    print(ans, k);

}