// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include <exception>
#include <cstdarg>
#include <vector>
#include <algorithm>
using namespace std;

int numEle(int * be, int * en) {
    return en - be + 1;
}



double avg(int *be, int n) {
    if (n % 2 == 0) {
        return (be[(n - 1) / 2] + be[n / 2]) * 0.5;
    }
    return be[n / 2];
}

double median(int cnt, ...){
    va_list firstElem;
    va_start(firstElem, cnt);

    vector<int> v;
    while(cnt--){
        // cout << *firstElem;
        v.push_back(va_arg(firstElem, int));
        // cout << v[v.size()-1] << endl;
    }

    sort(v.begin(), v.end());  // va_arg(firstElem, int);
    cnt = v.size();
    if (cnt & 1) return v[cnt/2];
    return 0.5*(v[cnt/2-1] + v[cnt/2]);

    va_end(firstElem);
}

double getMedian(int* aBeg, int* aEnd, int *bBeg, int *bEnd) noexcept {
    int n1 = numEle(aBeg, aEnd);
    int n2 = numEle(bBeg, bEnd);

    //Assume b will ALWAYS have a higher length
    if (n1 > n2) {
        swap(aBeg, bBeg);
        swap(aEnd, bEnd);
        swap(n1, n2);
    }

    if (n1 == 0 && n2 == 0) {
        //Exception
        return -1;
    }

    if (n1 == 0) return avg(bBeg, n2);

    // Case 1
    if (n1 == 1) {
        // 1 && even
        if (n2 % 2 == 0) {
            return median(3, bBeg[n2 - 1 / 2], bBeg[n2 / 2], *aBeg);
        }
        else {
            return median(4, *aBeg, bBeg[n2 / 2 - 1], bBeg[n2 / 2 + 1], bBeg[n2 / 2]);
        }
        // 1 && odd
    }
    else if (n1 == 2){
        if (n2 == 2){
            return median(4, aBeg[0], aBeg[1], bBeg[0], bBeg[1]);
        }
        else if (n2 % 2 == 0){
            return median(4, bBeg[n2/2], bBeg[n2/2-1], 
                max(*aBeg, bBeg[n2/2-2]),
                min(aBeg[1], bBeg[n2/2 + 1]));
        }
        else {
            return median(3, *aBeg, bBeg[n2/2], aBeg[1]);
        }
    }

    auto m1 = avg(aBeg, n1);
    auto m2 = avg(bBeg, n2);

    if (m1 < m2){
        return getMedian(&aBeg[n1/2], aEnd, bBeg, &bBeg[n2/2]);
    }
    else {
        return getMedian(aBeg, &aBeg[n1/2], &bBeg[n1/2], bEnd);
    }
}

int main() {
    int a[100];
    int b[100];
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; ++i)  cin >> a[i];
    for (int i = 0; i < n2; ++i)  cin >> b[i];

    auto ans = getMedian(a, a + (n1 - 1), b , b + (n2 - 1));
    cout << ans;
}