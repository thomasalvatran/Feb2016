#include <iostream>
using namespace std;

class Person
{
public:
    string *name;
    int age;
    Person(string name, int age): name(new string(name)), age(age){}
    // Person(const Person& p)
    // { // in case of 2 ctors overload with const and without const the one without const will be executed??
    //     cout << "const 1" << endl;
    // }
    Person(Person& p)  // no const will executed over with const
    {
        cout << "no const 2" << endl;
    }
};
int main()
{
    Person anil("Anil", 20);
    Person tom = anil;  //object is not defined then it is copy
}