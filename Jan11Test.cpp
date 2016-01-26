#include <iostream>
using namespace std;

class MyClass
{
public:
    int *x;
    MyClass(int i) : x(new int(i)){ cout << "ctor" << endl; }//x = new int(i);}
    // MyClass(int i) { cout << "ctor" << endl; }//x = new int(i);}
    MyClass(){ cout << "default ctor" << endl;  }  
    //MyClass(){} ////default ctor create by compiler
};

int main()
{
    MyClass m(111);
    cout << *(m.x) << endl;
}