//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x){  //O(n)
    if (s.empty()){
        s.push(x);
        return;
    }

    int topEle = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(topEle);
}


void reverse(stack<int>& s){    //O(n^2)
    if (s.empty()) return;

    int topEle = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, topEle);
}

int main(){
    stack<int> s({2, 3, 4, 5});
    // reverse(s);

    while(s.empty() == false){
        cout << s.top() << " ";
        s.pop();
    }   
}
