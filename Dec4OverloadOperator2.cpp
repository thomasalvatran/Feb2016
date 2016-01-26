#include <iostream>
using namespace std;

class Person
{
    string *m_name;
    int m_age;
public:                                                                       // Rules of three
    Person(string name, int age) : m_name(new string(name)), m_age(age){}     //ctor
    Person(const Person& p) : m_name(new string(*p.m_name)), m_age(p.m_age){} //copy ctor
    Person &operator=(const Person& p)                                        //Overload assignment
    {
        m_name = new string(*p.m_name);
        m_age = p.m_age;
    }
    
    void changename(string name, int age)
    {
        *m_name = name;
        m_age = age;
    }
    void display() 
    {
        cout << *m_name << " " << m_age << endl;
    }
};

int main()
{
    Person anil("Anil", 20);
    anil.display();
    Person tovan = anil;  //object tovan does not exist so copy ctor will be used
    tovan.display();
    
    tovan.changename("tovan", 40);
    anil.display();
    tovan.display();
    
    tovan = anil;        //object is exist so overload assigment will be used
    anil.display();
    tovan.display();
    return 0;
}