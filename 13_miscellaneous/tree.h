#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node * left;
    Node * right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};


Node* inputLevel() {
    Node * root = NULL;
    int x;
    cin >> x;
    if (x == -1) return NULL;

    root = new Node(x);
    queue<Node*> q;
    q.push(root);
    while (q.empty() == false) {
        Node * cur = q.front();
        q.pop();

        //setting the left child
        cin >> x;
        if (x != -1) {
            cur->left = new Node(x);
            q.push(cur->left);
        }

        cin >> x;
        if (x != -1) {
            cur->right = new Node(x);
            q.push(cur->right);
        }
    }
    return root;
}


void printLevel(Node * root) {      //O(N)
    if (root == NULL) {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.empty() == false) {
        Node * cur = q.front();
        q.pop();

        if (cur == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << cur->data << " ";
        if (cur->left)  q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }

}

#endif