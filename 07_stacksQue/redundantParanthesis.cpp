//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <stack>
using namespace std;

int redundantParanthesis(const string& str){    //O(n)
    stack<int> s;
    s.push(0);
    int cnt = 0;

    for(int i = 0; i < str.size(); ++i){
        char curChar = str[i];
        if (curChar == '(') s.push(0);
        else if (curChar == ')') {
            if (s.top() == 0) ++cnt;
            s.pop();
        }
        else ++s.top();
    }

    return cnt;
}

int main(){
    string s;
    getline(cin, s);

    int cnt = redundantParanthesis(s);

    cout << cnt << endl;    
}
