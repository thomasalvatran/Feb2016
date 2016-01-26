#include <iostream>
using namespace std;

class Person
{
    string* m_name;
    int m_age;
public:
     //Rule of three: assign =, copy ctor and ctor.
    Person(string name, int age) : m_name(new string(name)), m_age(age)
    {
        cout << "ctor" << endl;
    }
    Person(Person& p) //deep copy without const will run when overload, no const will be called 
    {
      m_name = new string(*p.m_name);
      m_age = p.m_age;
      cout << "Copy ctor deep" << endl;
    }
    Person(const Person& p) : m_name(p.m_name), m_age(p.m_age) 
    {  //shallow copy by compiler
      cout << "Copy ctor shallow" << endl;
    }
    Person& operator=(const Person& p)
    {
        if (this == &p)
         {
             return *this;
         }
        m_name = new string(*p.m_name);
        m_age = p.m_age;
        cout << "operator assignment overload" << endl;
    }
    void showPerson()
    {
        cout << *m_name << " " << m_age << endl;
    }
    void changeName(string name, int age)
    {
        *m_name = name;
        m_age = age;
    }
};

int main()
{
    Person anil("Anil", 20);
   
    Person tom = anil;
    anil.changeName("Anil Shetty", 100);
    anil.showPerson();
    tom.showPerson();
}