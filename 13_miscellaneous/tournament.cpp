// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
using namespace std;

class Node{
public:
    int val;
    int left, right;
    Node(int v, l = NULL, r = NULL){
        val = v;
        left = l;
        right = r;
    }
}

int secondMin(Node * root){
    int ans = root->val;
    while(root){
        if (root->left)
    }
}

int secondMin(int arr[], int be, int en){
    queue<Node *> l;

    for(int i = be; i < en; i += 2){
        int v = arr[i] < arr[i + 1] ? arr[i] : arr[i + 1];
        queue.push(new Node(v));
    }

    if (en % 2 == 0) queue.push(new Node(arr[en]));

    //build tree
    while(q.size() > 1){
        auto n1 = q.front();    q.pop();
        auto n2 = q.front();    q.pop();
        Node * root = NULL;
        if (n1->val < n2->val){
            root = new Node(n1->val, n1, n2);
        } else{
            root = new Node(n2->val, n2, n1);
        }
        q.push(root);
    } 

    int ans =  secondMin(q.front());
    deleteTree(root);
    return ans;
}



int main() {
    int cnt;
    cin >> cnt;
    int arr[100];
    for (int i = 0; i < cnt; ++i)  cin >> arr[i];

    int ans = secondMin(arr, 0, cnt - 1);
    cout << ans;
}