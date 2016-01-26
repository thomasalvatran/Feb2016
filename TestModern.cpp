//youtube modern C++
#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    string s = "foo";
    // string s1 {"foo1"}; //Modern
    // string s1("foo1");     //old C++
    string s1 = { "foo1"};
    int n{ 4 }; //g++4.8 -std=c++11 ...Modern C++
                //g++4.8            ...Old C++ will warm
                //TestModern.cpp:8:9: warning: extended initializer 
                //lists only available with -std=c++11 or -std=gnu++11 [enabled by default]
                // int n{ 4 }; //g++4.8 -std=c++11 ...Modern C++
                //      ^
    int m(33);
    int o = 333;
    cout << a << " " << n << " " << s << " " << s1 << " " << m << " " << o << endl;
}