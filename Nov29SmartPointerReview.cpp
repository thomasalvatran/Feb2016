// #include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <memory>

using namespace std;

class Person{
    string name;
    int age;
    public:
    Person(): name(0), age(0){}
    Person( const string name, int age) : name(name), age(age){ cout << "Ctor " << endl; }
    ~Person() {cout << "Dtor" << endl; }
   void Display() { cout << name << " " << age << endl; }    
};

template <typename T>
class SP {
    T* pData;
    public:
    SP(T *pValue) : pData(pValue) { cout << "Ctor1" << endl; }
    ~SP() { cout << "Dtor1" << endl; delete pData; }
    T *operator->() { return pData; }  //???? smartpointer is a pointer need to have 
     T &operator*() { return *pData; }
};

int main()
{
//   SP sp = new int(10);
    // Person *p = new Person("Scott", 20);
    Person *p(new Person("Scott", 20));
    p->Display();
    Person p1("Mary", 25);
    p1.Display();
    // SP<Person> p2(new Person("Scotty", 34));
    // SP<Person> p2 = new Person("Bob", 35);
    SP<Person> p2{new Person{"Nancy", 44}};
    p2->Display();               //need *operator->
    // p2.operator->(); //Wrong
    p2.operator *().Display();  // need &operator*
    // (*p2).Display();
    p2.operator ->();
    {
        unique_ptr<int> test{new int[10]};
    }
    
    {
        unique_ptr<double> smartPointers{new double{20.3}};
        unique_ptr<string> are {new string{"extremely"}};
        unique_ptr<char> versatile{new char{'!'}};
    } //memory free out of scope no reason to use raw pointer
    return 0;
    
}