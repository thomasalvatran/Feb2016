// http://www.geeksforgeeks.org/does-compiler-always-create-a-copy-constructor/

// #include <iostream>
// using namespace std;
 
// class Point
// {
//     int x, y;
// public:
//   Point(const Point &p) { x = p.x; y = p.y; } //copy constructor need to create default
//   Point(){}
// };
 
// int main()
// {
//     Point p1;  // COMPILER ERROR
//     Point p2 = p1;
//     return 0;
// }

#include<iostream>
using namespace std;
 
// A class without user defined assignment operator compiler create copy ctor
class Test
{
    int *ptr;
public:
    Test (int i = 0)      { ptr = new int(i); } //ptr is pointer ptr=i //invalid conversion or segment fault
    void setValue (int i) { *ptr = i; }
    void print()          { cout << *ptr << endl; }
    Test (const Test &t) 
    {
        ptr = new int(*t.ptr);
    }
    // Test &operator=(const Test &t) //without operator overload compiler create a shallow cpy
    // {
    //   ptr = new int(*t.ptr);  //deep copy
    // }
    Test &operator=(const Test &t) 
    {
         ptr = t.ptr;  //shallow copy
    }
};
 
int main()
{
    Test t1(5);
    Test t2;
    t2 = t1;
    t1.setValue(100);
    t2.print();  //shallow copy and using operator overload since both object are exist 
    return 0;
}

