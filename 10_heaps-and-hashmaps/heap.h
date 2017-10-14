// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <algorithm>
using std::swap;
using std::vector;

class Heap {
    vector<int> v;
    int sze;

    int parent(int i) { return i >> 1; }    //divided by 2; right shift
    int left(int i) { return i << 1;}
    int right(int i) { return (i << 1) + 1;}

    void heapify(int i){        //i is parent
        if (i >= sze) return;   //no child exists

        int pos = i;
        if (left(i) <= sze && v[left(i)] < v[pos]){
            pos = left(i);
        }

        if (right(i) <= sze && v[right(i)] < v[pos]){
            pos = right(i);
        }   
        swap(v[i], v[pos]);
        if (i != pos) heapify(pos);
    }

public:

    Heap(){
        // v[0] = -1;
        v.push_back(-1);
        sze = 0;
    }

    void push(int d){
        v.push_back(d);
        ++sze;

        int i = sze;    //idx of child
        while (i > 1 && v[i] < v[parent(i)]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }

    void pop(){
        if (sze == 0) return;

        swap(v[1], v[sze]);
        v.pop_back();
        --sze;
        heapify(1);
    }

    bool empty(){
        return sze == 0;
    }

    int top(){
        if (empty()) return -1;
        return v[1];
    }
};

#endif