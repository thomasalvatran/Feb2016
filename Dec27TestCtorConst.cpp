//http://www.geeksforgeeks.org/copy-constructor-argument-const/
#include<iostream>
using namespace std;
 
class Test
{
   /* Class data members */
public:
   Test(const Test &t) { /* Copy data members from t*/ cout << "copy ctor" << endl;}
   Test()        { /* Initialize data members */ cout << "ctor" << endl;}
};
 
Test fun()
{
    cout << "fun() Called\n";
    Test t;
    return t;
}
 
int main()
{
     Test t1;
     Test t2 = fun(); //copy ctor
    // Test t2;
    // t2 = fun();  //assign operator overload 
    return 0;
}