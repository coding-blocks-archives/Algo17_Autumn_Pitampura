// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include "tree.h"
using namespace std;

template<typename T>
void input(T containerStart, T containerEnd) {
    while (containerStart != containerEnd) {
        cin >> (*containerStart);
        ++containerStart;
    }
}

template <class T> void output(T containerStart, T containerEnd) {
    while (containerStart != containerEnd) {
        cout << (*containerStart);
        ++containerStart;
    }
}

void fillverticalPrint(Node * root, int level, multimap<int, Node*>& m) {
    if (root == NULL) {
        return;
    }

    // m.insert()--hw
    // m[level] = root;
    m.insert(make_pair(level, root));
    fillverticalPrint(root->left, level - 1, m);
    fillverticalPrint(root->right, level + 1, m);
}

void verticalPrint(Node *root) {
    multimap<int, Node*> m;
    fillverticalPrint(root, 0, m);
    int prevKey = 0;

    typedef map<int, Node*>::iterator mit;
    for (mit it = m.begin(); it != m.end(); ++it) {
        if (prevKey != it->first) {
            cout << endl;
            prevKey = it->first;
        }
        cout << it->second->data << " ";
    }
}

int * intersectionUnsorted(int arr1[], int n1, int arr2[], int n2, int& sze) {
    set<int> s;

    int* res = new int[min(n1, n2)] {};
    int k = 0;

    //setting the set
    for (int i = 0; i < n2; ++i) {
        s.insert(arr2[i]);
    }

    //result set
    for (int i = 0; i < n1; ++i) {
        if (s.find(arr1[i]) != s.end()) {
            res[k] = arr1[i];
            ++k;
        }
    }
    sze = k;
    return res;
}

vector<int> intersectionSorted(int arr[], int n) {
    //HW
}

typedef pair<int, int> ii;
void printSymmetric(vector<ii> v) {

}

void removeDuplicate(int arr[], int n) {

}

vector<ii> sumToX(int arr[], int n) {

}

int firstNonRepeatingElement(int arr[], int n) {

}

void  uniqueLine(const char* nameOfFile) {
    hash<string> H;
    hash<int> Hi;
    map<int, int> m;    //hash and lineNo
    // int computedHash = H(string);

    // ifstream in;
    string s;
    char c = 'a';
    int lineNo = 0;

    int computedHash = 0;

    while (c != '.' && true) {
        s.clear();
        for (int i = 0; i < 999; ++i) {
            cin.get(c);
            if (c == '.') break;
            if (c == '\n') break;
            s.push_back(c);
        }
        int computedHashStr = H(s);
        computedHash = Hi(computedHashStr + computedHash);
        if (c == '\n') {
            ++lineNo;
            if (m.find(computedHash) != m.end()) {
                //I have found the repeated line
                cout << m.find(computedHash)->second << " " << lineNo << endl;
                return;
            }
            else {
                m[computedHash] = lineNo;
            }
            computedHash = 0;
        }
    }
}

int main() {
    // int arr1[10];
    // int arr2[10];
    // int n1, n2 , sze;

    // cin >> n1 >> n2;
    // input(arr1, arr1 + n1);
    // input(arr2, arr2 + n2);
    // int * ans = intersectionUnsorted(arr1, n1, arr2, n2, sze);
    // output(ans, ans + sze);


    // Node * root = inputLevel();
    // printLevel(root);
    // cout << endl;
    // verticalPrint(root);

    uniqueLine("file.txt");

}