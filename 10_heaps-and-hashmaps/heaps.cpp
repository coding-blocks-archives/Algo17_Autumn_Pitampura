// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    Heap h;
    h.push(2);
    h.push(-1);
    cout << h.top() << endl;  
    h.push(4);
    h.pop();   
    cout << h.top() << endl;  
}