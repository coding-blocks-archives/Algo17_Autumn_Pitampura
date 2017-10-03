//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

void spiralPrint(char mat[][10], int M, int N){ //O(M*N) M,N is the number of rows and column in the matrix
    int startRow = 0;
    int endRow = M - 1;
    int startCol = 0;
    int endCol = N - 1;

    while(startRow <= endRow && startCol <= endCol){
        //print something

        //print the topMost row
        for(int c = startCol; c <= endCol; ++c){
            cout << mat[startRow][c];
        }
        ++startRow;

        //print lastCol
        for(int r = startRow; r <= endRow; ++r){
            cout << mat[r][endCol];
        }
        --endCol;

        //print endRow
        for(int c = endCol; c >= startCol && endRow >= startRow; --c) cout << mat[endRow][c];
        --endRow;

        //print startCol
        for(int r = endRow; r >= startRow && endCol >= startCol; --r) cout << mat[r][startCol];
        ++startCol;
    }
}



int main(){
    char mat[10][10];
    int M;
    int N;
    cin >> M >> N;

    //input
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            cin >> mat[i][j];
        }
    }   

    spiralPrint(mat, M, N);
}
