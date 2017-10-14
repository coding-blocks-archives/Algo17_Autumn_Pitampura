// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
using namespace std;

template <typename T, class V>
class Pair{
    T first;
    V second;
};

class PC{
    char first;
    char second;
};

template<typename T>
void printArr(T arr[], int n){

}


int main() {
  // Pair<int, char> ii;  

    Pair<Pair<int, char>, int> pi;
    Pair<int, Pair<int, char> > pii;
}