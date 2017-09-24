#include <iostream>
using namespace std;
int main(){
    int arr[10];
   
   cout << arr + 1 << endl;
   cout << &arr + 1 << endl;

   int (*ptr)[10] = &arr;   //ptr to an integer array
   int * arrPtr[10];                      //array of pointers


}