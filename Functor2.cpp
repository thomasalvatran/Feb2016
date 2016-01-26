#include <iostream>
#include <cmath>  //fmod modulus %

using namespace std;

template <typename T>
class Functor {
    T m_x;
public:
    Functor(T x): m_x(x){}
    string operator()(T x) { return fmod(x, m_x) ? "Odd" : "Even"; }
};

int main()
{
    Functor<int> func(3);
    cout << func.operator ()(21) << endl;
    cout << func(4) << endl;
    Functor<float> funf(2.2);
    cout << funf(4.4) << endl;
    
}