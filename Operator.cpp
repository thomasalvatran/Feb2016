#include <stdio.h>
#include <iostream>
using namespace std;

const int SIZE = 3;

template <typename T>
class Array
{
    T array[SIZE];
    public:
    Array() { 
        int i = SIZE;
        while (i --> 0)
           array[i] = i;

    }
    T &operator[]( int i){
        if (i > SIZE)
        {
            cout << "Array is out of bound" << endl;
            return array[0];
        }
        return array[i];
    }
    void Diplay() {
           for (int i = 0; i < SIZE; i++)
                cout << array[i] << " ";
            cout << endl;
    }
};

int main()
{
    Array<float> arr;
    arr.Diplay();
    arr[0] = 22;
    arr.Diplay();
}