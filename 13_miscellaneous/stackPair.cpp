// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include <stdexcept>
using namespace std;

class StackPair {
private:
    const int sze;
    int arr[100];
    int top1;
    int top2;

public:
    StackPair(int s): sze(s) {
        top1 = -1;
        top2 = s;
    }

    void size1() {

    }
    void size2() {

    }
    void push1() {

    }
    void push2(int x) {

    }
    void pop1() throw() {
       if (top1 == -1){
        throw length_error("empty1 stack");
       }

    }
    void pop2() {

    }

    bool empty1() {

    }
};

int main() {
    StackPair s(10);
    try{
        s.pop1();
    }catch (exception& e){
        cout << e.what();
    }
}