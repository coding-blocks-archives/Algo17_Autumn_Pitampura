// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node * next;
    Node(string s, int k) {
        key = s;
        //arr1 = arr2 !Wrong!!
        val = k;
        next = NULL;
    }
};

class HashMap {
    Node ** table;
    int sze;
    int tableSize;

    int hashFunction(string& s) {
        int num = 0;
        int mul = 1;
        for (int i = 0; i < s.size(); ++i) {
            num += (s[i] % tableSize) * mul;
            mul = mul * 31;
            mul %= tableSize;
            num %= tableSize;
        }
        return num;
    }

    Node* deleteNode(Node * head, string k) {
        if (head == NULL) return NULL;

        if (head->key == k) {
            Node * ahead = head->next;
            --sze;
            delete head;    //VERY IMPORTANT STEP
            return ahead;
        }

        head->next = deleteNode(head->next, k);
        return head;
    }

    double loadFactor() {
        return (double)sze / tableSize;
    }

    void rehash() {
        Node * * oldTable = table;
        int oldSize = tableSize;
        table = new Node*[2 * tableSize]{};
        tableSize = 2 * tableSize;
        sze = 0;

        //for every list
        for (int i = 0; i < oldSize; ++i) {
            Node * head = oldTable[i];
            while (head) {
                insert(head->key, head->val);
                Node * tmp = head;
                head = head->next;
                delete tmp;
            }
        }
    }

public:
    HashMap() {
        table = new Node*[7]{};
        tableSize = 7;
        sze = 0;
    }

    void insert(string k, int v) {
        int idx = hashFunction(k);

        Node * newNode = new Node(k, v);

        Node * head = table[idx];
        //insertion at head
        newNode->next = head;
        table[idx] = newNode;
        ++sze;

        if (loadFactor() >= 0.7) rehash();
    }

    int find(string k) {
        int idx = hashFunction(k);
        Node * head = table[idx];
        //search in the head for k
        while (head) {
            if (head->key == k) return head->val;
            head = head->next;
        }
        return -1;
    }

    void remove(string k) {
        int idx = hashFunction(k);
        Node * head = table[idx];

        table[idx] = deleteNode(head, k);
    }

};

int main() {
    HashMap M;
    M.insert("abc", 123);
    M.insert("def", 456);

    M.remove("abc");
    cout << "abc" << endl;
    cout << M.find("abc");
}