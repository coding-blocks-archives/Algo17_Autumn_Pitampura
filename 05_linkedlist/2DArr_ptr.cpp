//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;
int main(){
    int ** mat = NULL;
    int n;
    cin >> n;
    mat = new int * [n];    //array of n pointers
    //rows created

    //lets create columns
    for(int row = 0; row < n; ++row){
        mat[row] = new int [n];
    }

    //delete [] mat[0]
    //delete [] mat

}