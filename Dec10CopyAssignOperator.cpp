// http://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/
#include <iostream>
using namespace std;

class Test
{
public:
  int* data;
  // Test(int i) : data(new int(i)) { cout << "Ctor "<< i << endl; } //ctor deep
  Test(int i) : data(new int(i)) {} //if shallow only default ctor == empty ctor
  Test(const Test &t)
  {
      cout << "Copy Ctor" << endl;
     
  }
  Test& operator = (const Test &t)
  {
      cout << "Assign operator" << endl;
  }
 
};

int main()
{
    Test t1(111), t2(122);
    t2 = t1;        //assign
    Test t3 = t1;   //copy
    
    Test t4(15);
    cout << "data = " << *t4.data << endl;  //why not t->data  (*t).data
    Test *t5 = new Test(122);
    cout << t5->data << endl;
    cout << *t5->data << endl;
    cout << *(*t5).data << endl;
   
    return 0;
}
// Copy constructor is called when a new object is created from an existing object, as a copy of the existing object (see this G-Fact). 
// And assignment operator is called when an already initialized object is assigned a new value from another existing object.
// t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
// Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);"