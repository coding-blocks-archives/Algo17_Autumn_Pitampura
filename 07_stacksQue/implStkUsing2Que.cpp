//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <queue>
using namespace std;

class myStack{
    queue<int> * full;       //always full
    queue<int> * emptiness;       //always empty
public:
    myStack(){
        full = new queue<int>;
        emptiness = new queue<int>;
    }


    int pop(){      //Time Complexity: O(n)
        if (full->empty()) return -1;

        //pop is costly
        while(full->size() > 1){
            int frontEle = full->front();
            full->pop();
            emptiness->push(frontEle);
        }
        int frontEle = full->front();
        full->pop();

        //restoring the definition
        // swap(emptiness, full);
        queue<int> * tmp = full;
        full = emptiness;
        emptiness = tmp;

        return frontEle;
    }

    void push(int x){       //Time Complexity: O(1)
        full->push(x);
    }

    ~myStack(){
        delete full;
        delete emptiness;
    }
};


int main(){

    myStack s;
    while(true){
        char c;
        cin >> c;
        switch(c){
            case 'a' : 
                int x; cin >> x;
                s.push(x);
                break;
            case 'd' : 
                cout << s.pop() << endl;
        }
    }
    return 0;
}
