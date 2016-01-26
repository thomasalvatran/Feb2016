#include <iostream>
using namespace std;

class Person
{
    string m_name;
    int m_age;
    public:
    Person(string name, int age): m_name(name), m_age(age){ cout << "Ctor" << endl;}
    ~Person() { cout << "Dtor" << endl; }
    void Display()
    {
        cout << m_name << " "<< m_age << endl;
    }
};
template <typename T>
class SP
{
    T *pData;
    public:
    SP(T *pvalue) : pData(pValue) { cout << "Ctor" << endl; }
    ~SP()
    {
        cout << "Dtor" << endl;
        delete pData;
    }
    T& operator*() { return *pData; }
    T* operator&() { return pData; }
    
};
int main()
{
//  { //start scope
//  Person p("John", 21);
//  p.Display();
//  } //end scope
    {
    Person *p1 = new Person("Mary", 22);
    p1->Display();
    delete  p1; //crete on heap explicit delete explicit for Dtor to be called 
    } //out of scope to test if Dtor is called 
    return 0;
}