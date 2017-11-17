// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
using namespace std;

class Fruit{
public:
    virtual void x () = 0;
    void foo(){
        cout << "Fruit\n";
        x();
    }
};

class Mango:public Fruit{
public:
    void x(){}
     void foo(){
        cout << "Mango\n";
    }
};


int main() {
  Fruit * f;
  Mango*  m;
  // f = m;
  // f.foo();  

  f = new Mango();
  f->foo();
}