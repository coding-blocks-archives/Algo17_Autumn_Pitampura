// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
#include <exception>

using namespace std;


// void foo throws exception();
void foo();
int main() noexcept {
    foo();
}


void foo(){
    main();
}