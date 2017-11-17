// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include "tree.h"
#include <iostream>
#include <stack>
using namespace std;

void inorderIter(Node * root) {
    if (root == NULL) return;
    stack<Node * > s;

    s.push(root);

    while(s.empty() == false){
        cout << s.top()->data << " ";
        root = s.top();
        s.pop();
        if (root->right) s.push(root->right);
        if (root->left) s.push(root->left);

    }
}


int main() {
    Node * root = inputLevel();
    printLevel(root);

    inorderIter(root);
}