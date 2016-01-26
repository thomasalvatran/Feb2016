#include <iostream>
using namespace std;

class Pointer
{
    int *m_x, *m_y;
public:
    // Pointer(int x, int y){ m_x = new int(x);}
    Pointer(int x, int y) : m_x(new int(x)), m_y(new int(y)){}
    void display()
    {
        cout << *m_x << " " << *m_y << endl;
    }
    void set(int x, int y)
    {
        *m_x = x;
        *m_y = y;
    }
    Pointer(const Pointer& p) //: m_x(new int(*p.m_x)), m_y(new int(*p.m_y)) {}
    {
        m_x = new int(*p.m_x);
        m_y = new int(*p.m_y);
        cout << "deep copy" << endl;
    }
    //Compile create a shallow copy it is default copy ctor
    Pointer(Pointer& p) : m_x(p.m_x), m_y(p.m_y)
    {
        cout << "shallow copy" << endl;
    }
//if 2 copy ctors it will run the default ctor.    
};
int main()
{
    Pointer p1(1, 2);
    Pointer p2 = p1;
    p1.set(3, 4);
    p1.display();
    p2.display();
}