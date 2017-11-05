// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#ifndef NODE_H_
#define NODE_H_
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
#endif

#ifndef BST_H
#define BST_H

typedef TreeNode BstNode;

class Bst {
    static BstNode * insert(BstNode* root, int x) {
        if (root == NULL) {
            BstNode * tmp = new BstNode(x);
            return tmp;
        }

        if (x < root->data) {
            root->left = insert(root->left, x);
        } else {
            root->right = insert(root->right, x);
        }
        return root;
    }

public:

    static BstNode * create() {
        int x;
        BstNode * root = NULL;
        while (cin >> x && x != -1) {
            root = insert(root, x);
        }
        return root;
    }

    static void print(BstNode* root) {
        if (root == NULL) return;
        queue<BstNode*> q;
        q.push(root);
        // q.push(NULL);

        while (!q.empty()) {
            BstNode * cur = q.front();
            q.pop();

            if (cur == NULL) {
                cout << endl;
                if (q.empty() == false) q.push(NULL);
                continue;
            }

            cout << cur->data << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right)q.push(cur->right);
        }

        cout << endl << "===========" << endl;
    }
};
#endif