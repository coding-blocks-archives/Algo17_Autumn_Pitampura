// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include "arrayInput.h"
#include <iostream>
using namespace std;

int partition(int arr[], int be, int en) {
    int pivot = arr[en];
    int idx = be;

   for(int j = be; j < en; ++j){
    if (arr[j] < pivot){
        swap(arr[j], arr[idx]); 
        ++idx;
    }

   }
   swap(arr[idx], arr[en]);
   return idx;
}

void quicksort(int arr[], int be, int en) {
    if (be >= en) return;

    int pos = partition(arr, be, en);
    quicksort(arr, be, pos-1);
    quicksort(arr, pos + 1, en);
}


int main() {
    int arr[10];
    int n;
    cin >> n;
    inputArr(arr, arr + n);
    quicksort(arr, 0, n - 1);
    outputArr(arr, arr + n);

}