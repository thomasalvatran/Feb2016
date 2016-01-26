#include<iostream>
using namespace std;
 
// Bitwise operator based function to check divisibility by 9
bool isDivBy9(int n)
{
    // Base cases
    if (n == 0 || n == 3)
        return true;
    if (n < 3)
        return false;
 
    // If n is greater than 9, then recur for [floor(n/9) - n%8]
    return isDivBy9((int)(n>>1) - (int)(n&7));
}
class Person
{
    string *m_name;
    int m_age;
public:
    Person(string nane, int age): m_name(name), m_age(age){}
    Person(const Person& p):m_name(new string(*p.m_name)), m_age(p.m_age) {}
    Person &operator=( Person &p)
    {
      m_name = new string(*p.m_name);
      m_age = p.age;
    }
}
// Driver program to test above function
int main()
{
    int i = 9>>3; 
    cout << i << endl;
    // Let us print all multiples of 9 from 0 to 100
    // using above method
    for (int i = 0; i < 20; i++)
       if (isDivBy9(i))
         cout << i << " ";
    return 0;
}