//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

int cntSet(int n) {
    int cnt = 0;
    while (n) {
        // int lastBit = n & 1;
        // if (lastBit == 1) ++ cnt;

        cnt += n & 1;
        // cnt = cnt + n & 1; //WRONG!!! Precedence


        n = n >> 1; //right shifting
    }
    return cnt;
    //LOG(N)
}


int fastCnt(int n){ //O(LOG(N)) log base 10 
    int cnt = 0;
    while(n){
        ++cnt;
        int lastSetBit = n & (-n);
        // n = n >> lastSetBitPos;
        n = n - lastSetBit;
        // cout << n << endl;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    // int cnt = cntSet(n);
    int cnt = fastCnt(n);
    cout << cnt;
}
