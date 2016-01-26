//OK it is using value
// #include <iostream>
// using namespace std;

// class Person
// {
//     string m_name;
//     int m_age;
// public:
//     Person(string name, int age): m_name(name), m_age(age){}
//     void showName() 
//     {
//         cout << m_name << " " << m_age << endl;
//     }
//     void changeName(string name, int age) // : m_name(name), m_age(age) {}
//     {
//         m_name = name;
//         m_age = age;
//     }
    
// };

// int main()
// {
//     Person p("anil", 20);
//     Person p1 = p;
//     p.showName();
//     p1.showName();
//     p.changeName("tovan", 22);
//     p.showName();
//     p1.showName();
    
// }
#include <iostream>
using namespace std;

class Person
{
    string *m_name;
    int m_age;
public:
    // Person(string name, int age): m_name(name), m_age(age){} //error cnnot convert string to *string
    Person(string name, int age): m_name(new string(name)), m_age(age){}
    void showName()
    {
        cout << *m_name << " " << m_age << endl;
    }
    void changeName(string name, int age)
    {
        *m_name = name;
        m_age = age;
    }
    //Rule of three: assign =, copy ctor and ctor.
    Person(const Person& p)  : m_name(new string(*p.m_name)), m_age(p.m_age)
    {
        // m_name = new Person(*p.m_name);
        // m_age = new Person(*p.m_age);
        cout << "copy ctor" << endl;
    }
    Person &operator=(const Person& p)                                        //Overload assignment
    {
        m_name = new string(*p.m_name);
        m_age = p.m_age;
        cout << "operator assignment overload" << endl;
    }
};
int main()
{
    Person p("anil", 20);
    Person p1 = p;   
    p.showName();
    p1.showName();
    
    p.changeName("tovan", 22);
    p.showName();
    p1.showName();
}