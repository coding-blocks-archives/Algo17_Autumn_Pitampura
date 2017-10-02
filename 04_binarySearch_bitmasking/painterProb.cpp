//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
// Painter Problem
#include <iostream>
#include <numeric>
using namespace std;

bool canFinish(int availPainter, int walls[], int n, int reqTime){  //O(n)
    int nPainter = 1;
    int curPainterTime = 0;

    for(int i = 0; i < n; ++i){
        //if currWall requires greater time than reqTime
        if (walls[i] > reqTime) return false;

        //it means current wall can be painted
        //can curWall be allocated to the curPainter or I should allocate it to next painter???
        if (curPainterTime + walls[i] > reqTime){
            ++nPainter;
            curPainterTime = walls[i];
        }
        else{
            curPainterTime += walls[i];
        }

        //To allocate the above job, I need more painters than I have
        if (nPainter > availPainter){
            //we are sort of workers man!!!!
            return false;
        }
    }
    return true;
}


int minWalls(int walls[], int n, int K){    //O(nlogs)  s=sum/best
    int best = accumulate(walls, walls + n, 0);

    int be = 0;
    int en = best;

    while(be <= en){
    //Now I am trying to find a better ans than best
        int mid = (be + en) / 2;    
        //can mid beat best???
        if(canFinish(K, walls, n, mid)){
            best = mid;
            en = mid - 1;
        }
        else {
            be = mid + 1;
        }
    }
    return best;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[100];

    //input arr
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int ans = minWalls(arr, n, k);
    cout << ans;   
}
