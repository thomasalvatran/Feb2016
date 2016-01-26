// A safe array example.
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 5;

class atype {
    int a[SIZE];
    public:
    atype() {
        for (int i = 0; i < SIZE; i++)
            a[i] = i*i;
    }
    int &operator[](int i); //complete ref. p. 444
};
// Provide range checking for atype.
int &atype::operator[](int i)
{
    if(i<0 || i> SIZE) {
        cout << " Boundary Error\n ";
    exit(1);
    }
    return a[i];
}
int main()
{
atype ob;
for (int i = 0; i < SIZE + 2; i++)
    cout << ob[i] << " ";
cout << endl;
return 0;
}

