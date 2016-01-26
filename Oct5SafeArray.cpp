//http://www.tutorialspoint.com
//Ground up book page 343 Completed Ref C++
#include <iostream>
#include <stdlib.h>
using namespace std;

const int SIZE = 3;

class SaveArray{
    int array[SIZE];
    public:
    int i;
    SaveArray() {
        for(i = 0; i < SIZE; i++)
            array[i] = i;   //ctor init array to i
    }
    int &operator [] (int i) {
        if (i > SIZE)
        {
            cout << "Array is out of bound" << endl;
            return array[0]; //why return arrauy[0] ?????
        }
        return array[i];
    }
    
};
template <typename T>
class SaveArrayTemplate{
  T array[SIZE];  
  public:
  int i;
  SaveArrayTemplate(int SIZE) {
      for(i = 0; i < SIZE; i++)
        array[i] = i;
  }
  T &operator [](int i)
  {
      if (i > SIZE)
      {
          cout << "Array is out of bound" << endl;
          return array[0];          
      }
      return array[i];
  }
};
int main()
{
    SaveArray a;
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;
    // cout << a[4] << endl;
    SaveArrayTemplate<int> aint(SIZE);
    for(int i = 0; i < SIZE; i++)
        cout << aint[i] << " ";
    cout << endl;
    SaveArrayTemplate<double> dint(SIZE);
    for (int i = 0; i < SIZE; i++)
        dint[i] = 0.2 + i;
    for (int i = 0; i < SIZE; i++)
        cout << dint[i] << " "; 
    cout << endl;
}