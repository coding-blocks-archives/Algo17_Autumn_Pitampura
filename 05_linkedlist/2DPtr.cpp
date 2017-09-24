//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;
int main() {
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    int (*ptr)[3][3] = &arr;

    cout << arr << endl;
    cout << arr + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << arr[0] << endl;
    cout  << *(arr[0]) << endl;
    cout << &arr[0][0] << endl;
    cout << arr[0] + 1 << endl;
    cout << (&arr[0][0]) + 1 << endl;
    cout << arr + 1 << endl;
    cout << &arr[1][0] << endl;
}