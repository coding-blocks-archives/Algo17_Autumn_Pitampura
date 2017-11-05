// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#ifndef ARRAY_INP
#define ARRAY_INP
#include <iostream>
using namespace std;

template <typename T>
void inputArr(T* be, T* en){
    while(be != en){
        cin >> *T;
        ++be;
    }
}

template <typename T>
void outputArr(T* be, T* en){
    while(be != en){
        cout << *be << " ";
        ++be;
    }
}

#endif