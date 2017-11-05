// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include "bst.h"
using namespace std;

typedef pair<int, int> pbb; //ceil, floor

pbb ceilFloor(BstNode* root, int x){
    if (root == NULL){
        return pbb(1e7,-1e7);
    }

    if (x == root->data){
        return pbb(x,x);
    }

    if (x < root->data){
        int ceilAns = root->data;
        auto ans = ceilFloor(root->left, x);
        ans.first = min(ceilAns, ans.first);
        return ans;
    }
    else {
        int floorAns = root->data;
        auto ans = ceilFloor(root->right, x);
        ans.second = max(floorAns, ans.second);
        return ans;
    }
}

int main() {
    BstNode * root = Bst::create();
    Bst::print(root);

    int x; cin >> x;
    auto ans = ceilFloor(root, x);
    cout << ans.first << " " << ans.second << endl;      
}